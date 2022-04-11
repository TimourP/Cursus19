FROM debian:buster-slim

# update and upgrade apt
RUN apt-get update
RUN apt-get upgrade -y

# install requirements for wordpress (mostly php) and mariadb-client to allow wordpress to connect to remote mariadb
RUN apt-get install -y mariadb-client php-cgi php-common php-fpm php-pear php-mbstring php-zip php-net-socket php-gd php-xml-util php-gettext php-mysql php-bcmath unzip wget git curl

# just tools to debug
RUN apt-get install -y net-tools telnet


# copy config and index.html
COPY tools/config.sh /tmp/config.sh
COPY conf/php-fpm.conf /etc/php/7.3/fpm/php-fpm.conf
COPY conf/index.html /tmp/index.html
COPY conf/wp-config.php /tmp/wp-config.php

# set spawn path to /var/www/html/wordpress
WORKDIR /var/www/html/wordpress

CMD ["sh", "/tmp/config.sh"]