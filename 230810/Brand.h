#ifndef BRAND
#define BRAND

#include <iostream>
#include <sqlite3.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <cstdlib>

class Brand_All_Sales_Count
{
private:
    sqlite3 *db1;
    sqlite3_stmt *stmt_check1;

public:
    int Come_kia_sell(std::string num);
    int Come_hyunda_sell(std::string num);
    int Come_jenesiss_sell(std::string num);
    int Come_chevrolet_sell(std::string num);
    int Come_kgmobility_sell(std::string num);
    int Come_renault_sell(std::string num);
};

class Brand_Each_Sales_Count
{
private:
    sqlite3 *db3;
    sqlite3_stmt *stmt_check3;
    Brand_All_Sales_Count BASC;

public:
    void Come_kia_rank(std::string select_month);
    void Come_hyunda_rank(std::string select_month);
    void Come_jenesiss_rank(std::string select_month);
    void Come_chevrolet_rank(std::string select_month);
    void Come_kgmobility_rank(std::string select_month);
    void Come_renault_rank(std::string select_month);
};

class Brand_Main_Logic
{
private:
    sqlite3 *db2;
    std::string sql_check;
    sqlite3_stmt *stmt_check2;
    Brand_All_Sales_Count BASC;
    Brand_Each_Sales_Count BESC;

public:
    void Brand_Rank();
    void Brand_Logic();
};

#endif