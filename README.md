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

## This will start the server, listening for incoming TCP connections on the default or specified port. Use a port number greater than 1024, since those below or equal to 1024 are _well-known_ ports reserved for specific applications

- In the second terminal window, invoke the client by typing:
- _./ssl-client localhost_
- If the server is on a different machine than the client, you will need to specify that host name in place of localhost
- To specify a specific port type:
- _./ssl-client localhost:4435_
- where 4435 is whatever port number you want to specify.

## Once the connection is made, the client will list a series of possible commands and prompt the user for an input. Type one of the commands in the format provided to send it to the server.
