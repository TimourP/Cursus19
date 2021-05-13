# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/12 20:22:07 by tpetit            #+#    #+#              #
#    Updated: 2021/05/13 11:33:51 by tpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt-get update && apt-get install
RUN apt-get -y install wget
RUN apt-get -y install nginx
RUN apt-get -y install mariadb-server
RUN apt-get -y install php7.3-fpm php7.3-common php7.3-mysql php7.3-gmp php7.3-curl php7.3-intl php7.3-mbstring php7.3-xmlrpc php7.3-gd php7.3-xml php7.3-cli php7.3-zip php7.3-soap php7.3-imap

COPY ./srcs/init_container.sh /
COPY ./srcs/default /tmp/default
COPY ./srcs/config.inc.php /tmp/phpmyadmin.inc.php
COPY ./srcs/wp-config.php /tmp/wp-config.php

CMD bash init_container.sh