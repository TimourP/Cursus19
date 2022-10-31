#!/bin/sh
chown -R mysql:mysql /var/lib/mysql
# setup mysql config file in order to acces it remotely
if [ ! -d /var/lib/mysql/$WP_DATABASE_NAME ]; then
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
    CREATE USER IF NOT EXISTS $WP_DATABASE_USR IDENTIFIED BY '$WP_DATABASE_PWD';
    GRANT ALL PRIVILEGES ON $WP_DATABASE_NAME.* TO $WP_DATABASE_USR;
    FLUSH PRIVILEGES;"
    mysqladmin -u root password $WP_DATABASE_PWD
    service mysql stop
else
	# Create a folder for the daemon (mysql server’s socket file)
    echo "je passe ici"
	#Setting up .pid and .sock since they're not automatically set
	service mysql start
fi
# sleep in order to allow me to open shell inside of this container

mysql --user=$WP_DATABASE_NAME --password=$WP_DATABASE_PWD

sleep infinity