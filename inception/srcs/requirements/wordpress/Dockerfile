FROM debian:buster-slim

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y mariadb-client php-cgi php-common php-fpm php-pear php-mbstring php-zip php-net-socket php-gd php-xml-util php-gettext php-mysql php-bcmath unzip wget git curl

RUN apt-get install -y net-tools telnet


COPY tools/config.sh /tmp/config.sh
COPY conf/php-fpm.conf /etc/php/7.3/fpm/php-fpm.conf
COPY conf/index.html /tmp/index.html
COPY conf/wp-config.php /tmp/wp-config.php

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN cp wp-cli.phar /usr/bin/wp

WORKDIR /var/www/html/wordpress

CMD ["sh", "/tmp/config.sh"]