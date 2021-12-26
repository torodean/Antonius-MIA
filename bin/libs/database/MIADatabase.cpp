/**
 * File: MIADatabase.hpp
 * Author: Antonius Torode
 * Date: 03/11/2021
 * Description: This class defines database connections.
 */

#include "MIADatabase.hpp"
#include "Credentials.hpp"

using std::cout;
using std::endl;

MIADatabase::~MIADatabase()
{
    delete res;
    delete stmt;
    delete con;
}

int MIADatabase::testConnect()
{
    try
    {
        /* Create a connection */
        driver = get_driver_instance();
        sql::SQLString hostname("tcp://127.0.0.1:3306");
        con = driver->connect(hostname, "testUser", "password");
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

        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void MIADatabase::initialize()
{
    // @TODO
}

int MIADatabase::testDatabase()
{
    std::cout << "Starting database test." << std::endl;
    try
    {
        if(testConnect() != EXIT_SUCCESS)
            return EXIT_FAILURE;
        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * FROM testTable;"); // Get all the rows.
        size_t columns = 2;
        // Loop over each row.
        while (res->next())
        {
            cout << "\t... MySQL reply: ";
            // Access column data by numeric offset, 1 is the first column
            for(size_t i=1; i <= columns; i++)
            {
                cout << res->getString((uint32_t)i);
                if (i != columns)
                    cout << ", ";
            }
            cout << endl;
        }
    }
    catch (sql::SQLException &e)
    {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;

        return EXIT_FAILURE;
    }

    std::cout << "Finished database test." << std::endl;
    return EXIT_SUCCESS;
}

int MIADatabase::connect()
{
    // @TODO
    return EXIT_SUCCESS;
}

