
chown -R mysql:mysql /var/lib/mysql

sed -i "s|skip-networking|# skip-networking|g" /etc/mysql/mariadb.conf.d/50-server.cnf
sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0|g" /etc/mysql/mariadb.conf.d/50-server.cnf

if [ ! -d /var/lib/mysql/$WP_DATABASE_NAME ]; then

	service mysql start --datadir=/var/lib/mysql

	mkdir -p /var/run/mysqld
	touch /var/run/mysqld/mysqlf.pid

	mysql -e "\
    CREATE DATABASE IF NOT EXISTS $WP_DATABASE_NAME CHARACTER SET utf8 COLLATE utf8_general_ci;
    CREATE USER IF NOT EXISTS $WP_DATABASE_USR IDENTIFIED BY '$WP_DATABASE_PWD';
    GRANT ALL PRIVILEGES ON $WP_DATABASE_NAME.* TO $WP_DATABASE_USR;
    FLUSH PRIVILEGES;"

    # set root password
	mysqladmin -u root password $MYSQL_ROOT_PWD;

	service mysql stop --datadir=/var/lib/mysql
else
	mkdir -p /var/run/mysqld
	touch /var/run/mysqld/mysqlf.pid
	mkfifo /var/run/mk
fi

chown -R mysql:mysql /var/run/mysqld
mysqld_safe --datadir=/var/lib/mysql