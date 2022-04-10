NAME = inception

all: clean run

linux:
	@ echo "127.0.0.1 tpetit.42.fr" >> /etc/hosts
	
stop:
	@ docker-compose -f srcs/docker-compose.yml down

clean: stop
	@ rm -rf ~/Desktop/inception

prune: clean
	@ docker system prune --volumes -fa

run: 
	@ docker-compose -f srcs/docker-compose.yml up --build

.PHONY: linux stop clean run all
