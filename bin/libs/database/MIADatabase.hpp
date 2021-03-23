/**
 * File: MIADatabase.hpp
 * Author: Antonius Torode
 * Date: 03/11/2021
 * Description:
 */

#ifndef MIA2_MIADATABASE_HPP
#define MIA2_MIADATABASE_HPP

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

#endif //MIA2_MIADATABASE_HPP
