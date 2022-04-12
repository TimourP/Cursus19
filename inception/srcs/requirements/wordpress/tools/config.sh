# #!/bin/bash

sleep 2

adduser nginx
echo "nginx:$WP_DATABASE_PWD" | chpasswd

mkdir /run/php

sed -i "s/define( 'DB_NAME', '' );/define( 'DB_NAME', '$WP_DATABASE_NAME' );/" /tmp/wp-config.php
sed -i "s/define( 'DB_USER', '' );/define( 'DB_USER', '$WP_DATABASE_USR' );/" /tmp/wp-config.php
sed -i "s/define( 'DB_PASSWORD', '' );/define( 'DB_PASSWORD', '$WP_DATABASE_PWD' );/" /tmp/wp-config.php
sed -i "s/define( 'DB_HOST', '' );/define( 'DB_HOST', '$MYSQL_HOST' );/" /tmp/wp-config.php

if [ ! -f "/var/www/html/index.html" ]; then

	mv /tmp/index.html /var/www/html/index.html

	wp core download --allow-root
	cp /tmp/wp-config.php /var/www/html/wordpress/wp-config.php
	wp core install --url=$DOMAIN_NAME/wordpress --title=$WP_TITLE --admin_user=$WP_ADMIN_USR --admin_password=$WP_ADMIN_PWD --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root
	wp user create $WP_USR $WP_EMAIL --role=author --user_pass=$WP_PWD --allow-root
	wp theme install bravada --activate --allow-root

fi

/usr/sbin/php-fpm7.3 -F -R