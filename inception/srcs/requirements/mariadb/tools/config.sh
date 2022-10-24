#!/bin/sh

# setup mysql config file in order to acces it remotely
sed -i "s|skip-networking|# skip-networking|g" /etc/mysql/mariadb.conf.d/50-server.cnf
sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0|g" /etc/mysql/mariadb.conf.d/50-server.cnf

# start mysql service
service mysql start

# sleep to be sure service is on (it is just because i'm paranoid)
sleep 2

# use -e flag in order to pass param
# create database with database_name if not exist and grant privileges to database user
# it will create user if not exist and identified it with password
mysql -e "\
CREATE DATABASE IF NOT EXISTS $WP_DATABASE_NAME CHARACTER SET utf8 COLLATE utf8_general_ci;
GRANT ALL PRIVILEGES ON $WP_DATABASE_NAME.* TO '$WP_DATABASE_USR'@'%.%.%.%' IDENTIFIED BY '$WP_DATABASE_PWD';
FLUSH PRIVILEGES;"

# sleep in order to allow me to open shell inside of this container
mysqld_safe --datadir=/var/lib/mysql