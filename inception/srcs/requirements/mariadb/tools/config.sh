#!/bin/sh
chown -R mysql:mysql /var/lib/mysql
# setup mysql config file in order to acces it remotely
if [ ! -d /var/lib/mysql/$WP_DATABASE_PWD ]; then
    sed -i "s|skip-networking|# skip-networking|g" /etc/mysql/mariadb.conf.d/50-server.cnf
    sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0|g" /etc/mysql/mariadb.conf.d/50-server.cnf

    # start mysql service
    service mysql start --datadir=/var/lib/mysql

    mkdir -p /var/run/mysqld
	# Setting up .pid if it's not automatically set 
	# .sock file has been automatically created at this point
	touch /var/run/mysqld/mysqlf.pid

    # sleep to be sure service is on (it is just because i'm paranoid)
    sleep 2

    # use -e flag in order to pass param
    # create database with database_name if not exist and grant privileges to database user
    # it will create user if not exist and identified it with password
    mysql -e "\
    CREATE DATABASE IF NOT EXISTS $WP_DATABASE_NAME CHARACTER SET utf8 COLLATE utf8_general_ci;
    GRANT ALL PRIVILEGES ON $WP_DATABASE_NAME.* TO '$WP_DATABASE_USR'@'%.%.%.%' IDENTIFIED BY '$WP_DATABASE_PWD';
    CREATE USER 'TESTBIS'@'localhost' identified by '';
    FLUSH PRIVILEGES;"
    mysqladmin -u root password $WP_DATABASE_PWD
    service mysql stop --datadir=/var/lib/mysql
else
	# Create a folder for the daemon (mysql server’s socket file)
    echo "je passe ici"
	mkdir -p /var/run/mysqld
	#Setting up .pid and .sock since they're not automatically set
	touch /var/run/mysqld/mysqlf.pid
	mkfifo /var/run/mk
fi
# sleep in order to allow me to open shell inside of this container

chown -R mysql:mysql /var/run/mysqld
#Start the database daemon
echo "--start DB daemon"
mysqld_safe --datadir=/var/lib/mysql