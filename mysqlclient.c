/******************************************************************************
/ PROGRAM:  mysqlclient.c
/ AUTHOR:   Jeff Hemmes
/ SYNOPSIS: Demonstrates how a C program can interact with a MySQL database
/           using the mysqlclient API.  Refer to instructions on how to setup
/           a MySQL database on Linux in the separate handout "Using the C API
/           with MySQL Databases". This program assumes a database named
/           'dognames' is already set up as in the handout.  To build the
/           program, there are a number of compiler and linker options that
/           must be specified. Build with:
/
/           gcc -o mysqlclient mysqlclient.c `mysql_config --cflags --libs`
/
/           (c) Regis University
******************************************************************************/
#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

  MYSQL *connection;
  MYSQL_ROW row;
  MYSQL_RES *result;

  // Initialize the MySQL connection object

  if ((connection = mysql_init(NULL)) == NULL)
  {
    fprintf(stderr, "Could not initialize mysql: %s\n", mysql_error(connection));
    return EXIT_FAILURE;
  }

  // Connect to database 'dognames' on 'localhost' and provide login credentials

  if (mysql_real_connect(connection, "localhost", "root", "password", // change username and password
                         "tacos_recipes", 3306, NULL, 0) == NULL)
  {
    fprintf(stderr, "Could not connect to MySQL database: %s\n",
            mysql_error(connection));
    mysql_close(connection);
    return EXIT_FAILURE;
  }

  // Query the database using a SELECT command on the table 'famous_dogs'

  if (mysql_query(connection, "SELECT * FROM MyTable1"))
  {
    fprintf(stderr, "MySQL query failed: %s\n", mysql_error(connection));
    mysql_close(connection);
    return EXIT_FAILURE;
  }

  // Get the result of the SQL query and reference it using the pointer
  // variable 'result'

  if ((result = mysql_store_result(connection)) == NULL)
  {
    fprintf(stderr, "%s\n", mysql_error(connection));
    mysql_close(connection);
    return EXIT_FAILURE;
  }

  // Get each row from the query result, then output the three fields in each

  printf("Query 1:\n");
  while (row = mysql_fetch_row(result))
    printf("ID: %s Name: %s Breed: %s\n", row[0], row[1], row[2]);

  // Query the database using an INSERT command on the table 'famous_dogs'
  // This assumes the entry with ID 7 (primary key) does not already exist.

  // if (mysql_query(connection, "INSERT INTO famous_dogs (id, name, breed) VALUES (7, 'Beethoven', 'Saint Bernard' );")) {
  // fprintf(stderr, "MySQL query failed: %s\n", mysql_error(connection));
  // mysql_close(connection);
  // return EXIT_FAILURE;
  //}

  // Get the updated result by executing a SELECT query

  // if (mysql_query(connection, "SELECT * FROM famous_dogs")) {
  // fprintf(stderr, "MySQL query failed: %s\n", mysql_error(connection));
  // mysql_close(connection);
  // return EXIT_FAILURE;
  //}

  // Get the result of the SQL query and reference it using the pointer
  // variable 'result'

  // if ((result = mysql_store_result(connection)) == NULL) {
  //   fprintf(stderr, "%s\n", mysql_error(connection));
  //   mysql_close(connection);
  //    return EXIT_FAILURE;
  //}

  // Get each row from the query result, then output the three fields in each

  printf("Query 2:\n");
  while (row = mysql_fetch_row(result))
    printf("ID: %s Name: %s Breed: %s\n", row[0], row[1], row[2]);

  // Clean up and free dynamically allocated memory

  mysql_free_result(result);
  mysql_close(connection);

  return EXIT_SUCCESS;
}
