/**
 * File: MIADatabase.hpp
 * Author: Antonius Torode
 * Date: 03/11/2021
 * Description: This is the class designed for connection and use with databases.
 *              The MIA database uses SQL.
 */

#include "Credentials.hpp"
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

/**
 * This is the class designed for connection and use with databases.
 * The MIA database uses MYSQL.
 * Connector/C++ API Reference: https://dev.mysql.com/doc/dev/connector-cpp/8.0/
 */
class MIADatabase
{
public:

    /// This is the main default constructor for a MIADatabase object.
    MIADatabase() = default;
    /// The main destructor for a MIADatabase object.
    ~MIADatabase();

    /**
     * Initializes the database variables from the MIAConfig.MIA file.
     * This will setup the credentials and database to use.
     */
    void initialize();

    /**
     * Connects to the database.
     * Initialize should be ran first to gather database settings from config.
     */
     int connect();

    /**
     * Creates a test connection to a database. Used for testing.
     * The following setup needs used within mysql for this test.
     * mysql> CREATE DATABASE testDB;
     * mysql> CREATE USER testUser@localhost IDENTIFIED BY 'password'
     * mysql> GRANT ALL ON *.* TO 'testUser'@'localhost';
     * mysql> USE testDB;
     * mysql> CREATE TABLE testTable (id INT, value VARCHAR(150));
     * mysql> INSERT INTO testTable (id, value) VALUES (1, 'val01'), (2, 'val02'), (3, 'val03');
     * mysql> SELECT * FROM testTable # Use this to show the table values.
     * @return returns EXIT_SUCCESS if no failures occur.
     */
    int testConnect();

    /**
     * Runs some test code against the test database.
     * @return returns EXIT_SUCCESS if no failures occur.
     */
    int testDatabase();

    /**
     * This will set which database to use.
     */
    void setDatabase(std::string& db);


protected:

private:

    Credentials credentials;    ///< Credentials used to login to a database.
    std::string database;       ///< The database name to login to.
    /// MySQL values for the connection.
    sql::Driver *driver{};
    sql::Connection *con{};
    sql::Statement *stmt{};
    sql::ResultSet *res{};

};
