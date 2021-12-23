/**
 * File: MIADatabase.hpp
 * Author: Antonius Torode
 * Date: 03/11/2021
 * Description: This is the class designed for connection and use with databases.
 *              The MIA database uses SQL.
 */

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

class MIADatabase
{
public:

    MIADatabase() = default;

    ~MIADatabase();

    void initialize();

    void connect();

    void testDatabase();


protected:

private:

    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;

};
