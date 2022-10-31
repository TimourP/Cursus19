# Give owner and group for the the DB which is normally automatically created in this folder 
chown -R mysql:mysql /var/lib/mysql

sed -i "s|skip-networking|# skip-networking|g" /etc/mysql/mariadb.conf.d/50-server.cnf
sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0|g" /etc/mysql/mariadb.conf.d/50-server.cnf

#Just checking if the DB has been correctly created in the right path
if [ ! -d /var/lib/mysql/$WP_DATABASE_NAME ]; then
	service mysql start --datadir=/var/lib/mysql
	echo "--Service started"

	# Create a folder for the daemon (mysql server’s socket file)
	mkdir -p /var/run/mysqld
	# Setting up .pid if it's not automatically set 
	# .sock file has been automatically created at this point
	touch /var/run/mysqld/mysqlf.pid

	mysql -e "\
    CREATE DATABASE IF NOT EXISTS $WP_DATABASE_NAME CHARACTER SET utf8 COLLATE utf8_general_ci;
    CREATE USER IF NOT EXISTS $WP_DATABASE_USR IDENTIFIED BY '$WP_DATABASE_PWD';
    GRANT ALL PRIVILEGES ON $WP_DATABASE_NAME.* TO $WP_DATABASE_USR;
    FLUSH PRIVILEGES;"

	# Set MySQL root password (if you don't set it no password at all)
	mysqladmin -u root password $WP_DATABASE_PWD;
	echo "--Password set"

	service mysql stop --datadir=/var/lib/mysql
	echo "--Service stopped"
else
	# Create a folder for the daemon (mysql server’s socket file)
	mkdir -p /var/run/mysqld
	#Setting up .pid and .sock since they're not automatically set
	touch /var/run/mysqld/mysqlf.pid
	mkfifo /var/run/mk
fi

#Give owner and group to that too
chown -R mysql:mysql /var/run/mysqld
#Start the database daemon
echo "--start DB daemon"
mysqld_safe --datadir=/var/lib/mysql