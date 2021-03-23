/**
 * File: MIADatabase.hpp
 * Author: Antonius Torode
 * Date: 03/11/2021
 * Description:
 */

#include "MIADatabase.hpp"
#include <iostream>

using std::cout;
using std::endl;

MIADatabase::~MIADatabase()
{
        delete res;
        delete stmt;
        delete con;
}

void MIADatabase::connect()
{

    try
    {
        /* Create a connection */
        driver = get_driver_instance();
        sql::SQLString hostname("tcp://192.168.1.4:3306");
        con = driver->connect(hostname, "testUser", "testPW");
        /* Connect to the MySQL test database */
        con->setSchema("testDB");
    }
    catch (sql::SQLException &e)
    {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
}

void MIADatabase::initialize()
{

}

void MIADatabase::testDatabase()
{
    std::cout << "Starting database test." << std::endl;
    connect();
    try
    {
        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT 'Hello World!' AS _message");
        while (res->next()) {
            cout << "\t... MySQL replies: ";
            /* Access column data by alias or column name */
            cout << res->getString("_message") << endl;
            cout << "\t... MySQL says it again: ";
            /* Access column data by numeric offset, 1 is the first column */
            cout << res->getString(1) << endl;
        }
    }
    catch (sql::SQLException &e)
    {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    std::cout << "Finished database test." << std::endl;
}

