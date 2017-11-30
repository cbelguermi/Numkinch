//
// Created on 22/11/2017.
//

#ifndef NUMKINCH_DATABASELOADER_H
#define NUMKINCH_DATABASELOADER_H


#include <sqlite3.h>

class DatabaseManager {

private:
    bool _isOpen = false;

    sqlite3 * _sqlDatabase;


public:
    bool connectDB();

    void disconnectDB();

    int createTable();

    int addDataRow();

};


#endif //NUMKINCH_DATABASELOADER_H

/*
 * TODO: store cards
 * name
 * description
 * entity
 */