#!/bin/sh

# start mysql service

sed -i "s|skip-networking|# skip-networking|g" /etc/mysql/mariadb.conf.d/50-server.cnf
sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0|g" /etc/mysql/mariadb.conf.d/50-server.cnf

service mysql start

sleep 2

mysql -e "\
CREATE DATABASE IF NOT EXISTS $WP_DATABASE_NAME CHARACTER SET utf8 COLLATE utf8_general_ci;
GRANT ALL PRIVILEGES ON $WP_DATABASE_NAME.* TO '$WP_DATABASE_USR'@'%.%.%.%' IDENTIFIED BY 'secret';
FLUSH PRIVILEGES;"


sleep infinity