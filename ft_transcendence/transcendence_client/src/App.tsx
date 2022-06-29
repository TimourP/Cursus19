import React, { useEffect, useRef, useState } from 'react';
import logo from './logo.svg';
import './App.css';
import { io } from "socket.io-client";

const ws = io("http://localhost:3000");
const up_key: string = "w";
const down_key: string = "o";
let last_send: string = "o";

const draw_players = (context: any, player1_y: number, player2_y: number, ball_x: number, ball_y: number) => {
	context.clearRect(-100, -100, context.canvas.width + 100, context.canvas.height + 100);
	context.fillStyle = '#CB4335';
	context.fillRect(ball_x - 5, ball_y - 5, 10, 10);
	context.fill();
	context.fillStyle = '#fff';
	context.fillRect(10, player1_y, 10, 60);
	context.fillRect(context.canvas.width - 20, player2_y, 10, 60);
}

function App() {

	const canvasRef = useRef(null)

	useEffect(() => {

		const canvas: any = canvasRef.current;

		const context = canvas.getContext('2d');

		draw_players(context, 10, 10, 350, 250);

		window.addEventListener('keydown', (e) => {
			if (e.key == up_key && last_send != 'u') {
				ws.emit('setPosition', 'u');
				last_send = 'u';
			} else if (e.key == down_key && last_send != 'd') {
				ws.emit('setPosition', 'd');
				last_send = 'd';
			}
		})

		window.addEventListener('keyup', (e) => {
			if (last_send != 'o') {
				ws.emit('setPosition', 'o');
				last_send = 'o';
			}
		})

		ws.on('getPosition', (message: string) => {
			let data = message.split(" ");
			draw_players(context, parseInt(data[0]), parseInt(data[1]), parseInt(data[2]), parseInt(data[3]));
		})

		ws.on('first', (message: string) => {
			canvas.style.backgroundColor = "#1B2631";
			console.log("first")
		})

		return () => {
			ws.close();
		}

	}, [])

	return (
		<div className="App">
			<canvas ref={canvasRef} width="700" height="500">
				Désolé, votre navigateur ne prend pas en charge &lt;canvas&gt;.
			</canvas>
		</div>
	);
}

export default App;
