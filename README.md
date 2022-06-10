# three-tiered-client-server-system

# To create a self-signed certificate your server can use, at the command prompt type:

- openssl req -newkey rsa:2048 -nodes -keyout key.pem -x509 -days 365 -out cert.pem
- This will create two files: a private key contained in the file ‘key.pem’ and a certificate containing
  a public key in the file ‘cert.pem’. Your server will require both in order to operate properly. Both

## files must reside in the working directory of your server. The client does not require any such setup to work properly.
