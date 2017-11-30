//
// Created on 22/11/2017.
//

#include "DatabaseManager.h"

#include <cstdio>
#include <cstdlib>

#define DB_FILE "cards.db"

bool DatabaseManager::connectDB()
{

    if (sqlite3_open(DB_FILE, &_sqlDatabase) == SQLITE_OK)
    {
        _isOpen = true;
        return true;
    }
    else
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(_sqlDatabase));
        return false;
    }
}

void DatabaseManager::disconnectDB()
{
    if (_isOpen)
    {
        sqlite3_close(_sqlDatabase);
    }
}

int DatabaseManager::createTable()
{
    const char * sqlQuery = "CREATE TABLE CARD(" \
                            "ID INT PRIMARY KEY NOT NULL," \
                            "NAME TEXT NOT NULL," \
                            "DESCRIPTION CHAR(140) NOT NULL," \
                            "ENTITY_PATH TEXT NOT NULL";

    if (sqlite3_exec(_sqlDatabase, sqlQuery, nullptr, nullptr, nullptr) == SQLITE_OK)
    {
        fprintf(stdout, "Table has been successfully created.\n");
        return EXIT_SUCCESS;
    }
    else
    {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(_sqlDatabase));
        return EXIT_FAILURE;
    }
}


int DatabaseManager::addDataRow()
{
    return 0;
}