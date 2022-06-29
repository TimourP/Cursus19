import { Logger } from '@nestjs/common';
import { SubscribeMessage, WebSocketGateway, OnGatewayInit, OnGatewayConnection, OnGatewayDisconnect, WebSocketServer } from '@nestjs/websockets';
import { Socket, Server } from 'socket.io';

const sleep = (milliseconds: number) => {
	return new Promise(resolve => setTimeout(resolve, milliseconds))
}

function getRandomInt(max: number) {
	return Math.floor(Math.random() * max);
}

const random_ball = () => {
	return Math.random() * Math.PI / 2 - Math.PI / 4 + getRandomInt(2) * Math.PI;
}

class Player {

	y_pos: number;
	delta: number;
	id: string;
	socket: Socket;

	constructor(it: string, socket: Socket) {
		this.y_pos = 0;
		this.delta = 0;
		this.id = it;
		this.socket = socket;
	}
}

class Game {
	private logger: Logger = new Logger('AppGateway');

	is_running: boolean;
	first_player: Player = null;
	second_player: Player = null;
	ball_x: number = 350;
	ball_y: number = 250;
	ball_angle: number = random_ball();
	spectator: any = [];

	game_state() {
		this.logger.log(`Player1: ${this.first_player.id}`);
		this.logger.log(`Player2: ${this.second_player.id}`);
	}

	change_position(player: Player) {
		player.y_pos += player.delta * 10;
		if (player.y_pos < 10) {
			player.y_pos = 10;
		} else if (player.y_pos > 430) {
			player.y_pos = 430;
		}
	}

	touch_player(player: Player): boolean {
		const x: number = player == this.first_player ? 5 : 670;

		return (this.ball_x >= x && this.ball_x <= x + 20) && (this.ball_y >= player.y_pos && this.ball_y <= player.y_pos + 70);
	}

	change_ball_pos() {
		this.ball_x += 10 * Math.cos(this.ball_angle);
		this.ball_y += 10 * Math.sin(this.ball_angle);
		if (this.ball_x > 700) {
			this.ball_x = 350;
			this.ball_y = 250;
			this.ball_angle = random_ball();
		} else if (this.ball_x < 0) {
			this.ball_x = 350;
			this.ball_y = 250;
			this.ball_angle = random_ball();
		}
		if (this.ball_y >= 495) {
			this.ball_angle = -this.ball_angle;
		} else if (this.ball_y <= 5) {
			this.ball_angle = -this.ball_angle;
		}
		if (this.touch_player(this.first_player)) {
			this.ball_angle = Math.PI - this.ball_angle;
		}
		if (this.touch_player(this.second_player)) {
			this.ball_angle = Math.PI - this.ball_angle;
		}
	}

	async run_game() {
		this.ball_angle = random_ball();
		while (this.is_running) {
			this.change_ball_pos();
			this.change_position(this.first_player);
			this.change_position(this.second_player);
			this.first_player.socket.emit("getPosition", `${this.first_player.y_pos} ${this.second_player.y_pos} ${this.ball_x} ${this.ball_y}`);
			this.second_player.socket.emit("getPosition", `${this.second_player.y_pos} ${this.first_player.y_pos} ${700 - this.ball_x} ${this.ball_y}`);
			for (let index = 0; index < this.spectator.length; index++) {
				this.spectator[index].socket.emit("getPosition", `${this.first_player.y_pos} ${this.second_player.y_pos} ${this.ball_x} ${this.ball_y}`);
			}
			await sleep(50);
		}
	}

	constructor() {

	}

	add_player(p: Player) {
		if (this.first_player == null) {
			this.first_player = p;
		} else if (this.second_player == null) {
			this.first_player.socket.emit("first", "");
			this.second_player = p;
			this.is_running = true;
			this.ball_x = 350;
			this.ball_y = 250;
			this.run_game()
		} else {
			this.spectator.push(p);
		}
	}

	remove_player(id: string) {
		if (this.first_player && this.first_player.id == id) {
			this.first_player = null;
			this.is_running = false;
		} else if (this.second_player && this.second_player.id == id) {
			this.second_player = null;
			this.is_running = false;
		} else {
			for (let index = 0; index < this.spectator.length; index++) {
				const element: Player = this.spectator[index];
				if (element.id == id) {
					this.spectator.splice(index, 1);
					break;
				}
			}
		}
		if (this.first_player == null) {
			this.first_player = this.second_player;
			this.second_player = null;
		}
		this.logger.log(this.spectator.length)
	}

	set_delta(delta: number, id: string) {
		if (this.first_player && this.first_player.id == id) {
			this.first_player.delta = delta;
		} else if (this.second_player && this.second_player.id == id) {
			this.second_player.delta = delta;
		}
	}

}

@WebSocketGateway({ cors: true })
export class AppGateway implements OnGatewayInit, OnGatewayConnection, OnGatewayDisconnect {

	@WebSocketServer() wss: Server;

	game: Game = new Game();

	afterInit(server: any) {

	}

	handleConnection(client: Socket, ...args: any[]) {
		if (this.game.first_player == null) {
			client.emit("first", "");
		}
		this.game.add_player(new Player(client.id, client));
	}

	handleDisconnect(client: Socket) {
		this.game.remove_player(client.id);
	}

	private logger: Logger = new Logger('AppGateway');

	@SubscribeMessage('setPosition')
	handleMessage(client: Socket, message: string): void {
		if (message == 'd') {
			this.game.set_delta(1, client.id);
		} else if (message == 'u') {
			this.game.set_delta(-1, client.id);
		} else if (message == 'o') {
			this.game.set_delta(0, client.id);
		}
	}
}
