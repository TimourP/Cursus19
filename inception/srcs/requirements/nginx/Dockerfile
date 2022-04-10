FROM debian:buster-slim

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y nginx openssl

RUN mkdir /etc/nginx/ssl
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
        -out /etc/nginx/ssl/tpetit.pem \
        -keyout /etc/nginx/ssl/tpetit.key \
        -subj "/C=IT/ST=Nams/L=Nams/O=s19/OU=tpetit/CN=tpetit/"

COPY conf/nginx.conf /etc/nginx/sites-available/default

CMD ["nginx", "-g", "daemon off;"]
