<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', "wordpress" );

/** Database username */
define( 'DB_USER', "tpetit" );

/** Database password */
define( 'DB_PASSWORD', "secret" );

/** Database hostname */
define( 'DB_HOST', "mariadb" );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'In9&yGK=4AM=Mr76F=Y-0uhQD3{vBvxA=#srok2S)#J?MEIZC|;q9QCJ,R/l1-Em');
define('SECURE_AUTH_KEY',  'N|QVv<K#vmj4 !)gh1QIrnHHs}bgK=J{.,5baK5hM-=WEWCwtEvrOJk5h?NC@Nyf');
define('LOGGED_IN_KEY',    ';0a6OF<dx$)os1WsFGy|&7`.9dKF^ew!SJ<xyBju`D*#P=23%+F/`]gH/Es74I;C');
define('NONCE_KEY',        '~(c*=iz&c],@ypc`E?4it3+BDz(s.9_v4=W*+N/?(aq;`: gTfQ|7pi<P>wWk*)Y');
define('AUTH_SALT',        ')00lBaWA^|=Q$+R*?TrEA3pl3hREwO!RMHYC[?weki-Q-rDkZ|sICP*TGjuES}E|');
define('SECURE_AUTH_SALT', ',4*gziGlsZ]Qo>Mrm~!67XAw#QL;1}_+<)aILi|>6RH.=qso(vnRBG@ag9`@mlb+');
define('LOGGED_IN_SALT',   '=DDT=8]Mkc]xE`ct$AX|_TqhB$D4;Wi1UDHou|P~p|SG:*Y];}1]YUa>PdRL_4S^');
define('NONCE_SALT',       'p_`;m1 26D#GWxRHuCL*ueofvO<8.gI|eGVI-rSn;h$+/R/Y#QAU3P1.Uq^GvdD7');

/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';