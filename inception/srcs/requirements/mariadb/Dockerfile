FROM debian:buster-slim

# update and upgrade apt
RUN apt-get update
RUN apt-get upgrade -y

# install mariadb packages
RUN apt-get install -y mariadb-server mariadb-client

# just tools to debug
RUN apt-get install -y net-tools telnet

# copy config who will be use by CMD
COPY tools/config.sh /tmp

CMD ["sh", "/tmp/config.sh"]
