#ifndef CARS_H_
#define CARS_H_

#include <stdio.h>
#include <iostream>
#include <sqlite3.h>
#include <unistd.h>
#include <iomanip> //정렬
#include "Brand.h"
#include "cars1.h"

class All_car
{
private:
    sqlite3 *db;
    int totalsales;

public:
    All_car(const std::string &dbPath)
    {
        int result = sqlite3_open("car", &db);

        if (result != SQLITE_OK)
        {
            std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
            db = nullptr;
        }
    }

    All_car()
    {
        if (db)
        {
            sqlite3_close(db);
        }
    }

    bool isopen() const
    {
        return db != nullptr;
    }

    void May();
    void June();
    void July();
};

class All_Main
{
private:
public:
    int Main();
};

#endif