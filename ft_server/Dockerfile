# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/12 20:22:07 by tpetit            #+#    #+#              #
#    Updated: 2021/05/12 20:36:12 by tpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt-get update && apt-get install
RUN apt-get -y install wget
RUN apt-get -y install nginx
RUN apt-get -y install mariadb-server

COPY ./srcs/init_container.sh /
COPY ./srcs/default /tmp/default
COPY ./srcs/phpmyadmin.inc.php /tmp/phpmyadmin.inc.php
COPY ./srcs/wp-config.php /tmp/wp-config.php

CMD bash init_container.sh