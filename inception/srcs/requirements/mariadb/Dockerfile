FROM debian:buster-slim

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y mariadb-server mariadb-client

RUN apt-get install -y net-tools telnet

COPY tools/config.sh /tmp

CMD ["sh", "/tmp/config.sh"]
