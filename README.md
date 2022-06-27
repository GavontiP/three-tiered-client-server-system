# three-tiered-client-server-system

## MySql Database Setup Instructions

- The first step is installing the server and development libraries. On Ubuntu Linux, at the command prompt type:
- sudo apt-get install -y mysql-server libmysqlclient-dev
### Install the MySQL server 
At the command prompt, type:
- sudo apt-get update
- sudo apt-get install mysql-server
### Set the root password, type:
- sudo mysql_secure_installation utility
- Then just follow the prompts.
### Run the MySQL server and create a user
- First, run the mysql client:
- sudo mysql -u root –p
Enter the root password established in the previous step. This should bring you to the mysql shell.
At the shell prompt (mysql>), type:
- CREATE USER 'newuser'@'localhost' IDENTIFIED BY 'password';
Next, grant access rights to the newly created user account. Type:
- GRANT ALL PRIVILEGES ON * . * TO 'newuser'@'localhost';
FLUSH PRIVILEGES;
### Create a new database
  - At the MySQL client shell prompt, type:
   -  CREATE DATABASE dogs;
   -  CREATE TABLE famous_dogs ( id INT UNSIGNED NOT NULL, name VARCHAR(30) NOT NULL, breed VARCHAR(30) NOT NULL );

### Now we can begin inserting data:

INSERT INTO famous_dogs ( id, name, breed ) 
VALUES ( 1, 'Doug', 'Pug' ), (2, 'Toto', 'Cairn Terrier' ), ( 3, 'Beethoven', 'Saint Bernard'), ( 7, 'Beethoven', 'Saint Bernard');

### make sure to update the server connection with the credentials of your new datbase line 328 in ssl-server.c

## Installing and setting up VM using VirtualBox
(https://ubuntu.com/tutorials/how-to-run-ubuntu-desktop-on-a-virtual-machine-using-virtualbox#4-changing-the-window-resolution) (link to ubuntu tutorial)

 - in the virtual machine you will have to install the following:
    - sudo apt-get install libssl-dev
    - sudo apt-get install -y mysql-server libmysqlclient-dev
    - sudo apt install gcc

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

## DEMO VIDEO
https://user-images.githubusercontent.com/94074836/175838425-28b7a098-d732-4a77-bd59-dc2c2fee4cc6.mp4


