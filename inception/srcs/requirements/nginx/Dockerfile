FROM debian:buster-slim

# update and upgrade apt
RUN apt-get update
RUN apt-get upgrade -y

# install nginx and openssl (for https)
RUN apt-get install -y nginx openssl

# create ssl directory to put keys
RUN mkdir /etc/nginx/ssl
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
        -out /etc/nginx/ssl/tpetit.pem \
        -keyout /etc/nginx/ssl/tpetit.key \
        -subj "/C=IT/ST=Nams/L=Nams/O=s19/OU=tpetit/CN=tpetit/"

# copy nginx conf and replace default one in site available.
# because of default in sites-enabled is a link to default in sites-available I don't need to recrate it
COPY conf/nginx.conf /etc/nginx/sites-available/default

# start nginx and force container to stay open
CMD ["nginx", "-g", "daemon off;"]
