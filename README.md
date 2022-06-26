# three-tiered-client-server-system

## Running The Program

### In the working directory, several files will be needed:

- The source code file for the client, ssl-client.c, and server, ssl-server.c, and a Makefile for both
- You will also need the database to be used with the program

## Since the program is secured using SSL, you will need to create a key.pem and cert.pem file.
### To create a self-signed certificate your server can use, at the command prompt type:

- openssl req -newkey rsa:2048 -nodes -keyout key.pem -x509 -days 365 -out cert.pem
- This will create two files: a private key contained in the file ‘key.pem’ and a certificate containing
  a public key in the file ‘cert.pem’. Your server will require both in order to operate properly. Both files must reside in the working directory of your server. The client does not require any such setup to work properly.

## To build the executables for the program, two different commands are useful:

- In the command prompt, type:
- _make_ 
- this will build both the client and the server
- to remove the executables or clean them up type:
-  _make clean_

## It will probably be easiest to open two terminal windows, one for the client and the other for the server.
## To run the server program, in the terminal type:

- _./ssl-server_ 
- or to specify a different port, type:
- _./ssl-server (port number)_


