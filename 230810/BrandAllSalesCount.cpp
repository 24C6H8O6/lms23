#include <iostream>
#include <sqlite3.h>
#include "Brand.h"

int Brand_All_Sales_Count::Come_kia_sell(std::string num)
{
    int sum_kia = 0;
    int result = sqlite3_open("car", &db1); // car라는 이름을 가진 db를 열기
    const char *come_kia;
    if (num == "5월")
    {
        come_kia = "SELECT May FROM cars WHERE Brand = '기아'"; // Brand의 값이 기아인 May의 값을 불러오도록 지정
    }
    else if (num == "6월")
    {
        come_kia = "SELECT June FROM cars WHERE Brand = '기아'"; // Brand의 값이 기아인 June의 값을 불러오도록 지정
    }
    else if (num == "7월")
    {
        come_kia = "SELECT July FROM cars WHERE Brand = '기아'"; // Brand의 값이 기아인 July의 값을 불러오도록 지정
    }

    result = sqlite3_prepare_v2(db1, come_kia, -1, &stmt_check1, nullptr); // 쿼리준비(데이터베이스, 조건, -1이면 자동)
    if (result != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(db1) << std::endl;
        sqlite3_close(db1);
        return result;
    }
    int month_value = 0;
    while (sqlite3_step(stmt_check1) == SQLITE_ROW)
    {
        const char *monthstr = reinterpret_cast<const char *>(sqlite3_column_text(stmt_check1, 0));
        month_value = std::stoi(monthstr); // const char*을 정수형으로 변환

        sum_kia += month_value;
    }
    sqlite3_finalize(stmt_check1);
    sqlite3_close(db1); // 데이터베이스 닫기
    return sum_kia;
}

int Brand_All_Sales_Count::Come_hyunda_sell(std::string num)
{
    int sum_hyunda = 0;
    int result = sqlite3_open("car", &db1); // car라는 이름을 가진 db를 열기
    const char *come_hyunda;
    if (num == "5월")
    {
        come_hyunda = "SELECT May FROM cars WHERE Brand = '현대'"; // Brand의 값이 현대인 May의 값을 불러오도록 지정
    }
    else if (num == "6월")
    {
        come_hyunda = "SELECT June FROM cars WHERE Brand = '현대'"; // Brand의 값이 현대인 June의 값을 불러오도록 지정
    }
    else if (num == "7월")
    {
        come_hyunda = "SELECT July FROM cars WHERE Brand = '현대'"; // Brand의 값이 현대인 July의 값을 불러오도록 지정
    }

    result = sqlite3_prepare_v2(db1, come_hyunda, -1, &stmt_check1, nullptr); // 쿼리준비(데이터베이스, 조건, -1이면 자동)
    if (result != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(db1) << std::endl;
        sqlite3_close(db1);
        return result;
    }
    int month_value = 0;
    while (sqlite3_step(stmt_check1) == SQLITE_ROW)
    {
        const char *monthstr = reinterpret_cast<const char *>(sqlite3_column_text(stmt_check1, 0));
        month_value = std::stoi(monthstr); // const char*을 정수형으로 변환
        sum_hyunda += month_value;
    }
    sqlite3_finalize(stmt_check1);
    sqlite3_close(db1); // 데이터베이스 닫기
    return sum_hyunda;
}

int Brand_All_Sales_Count::Come_jenesiss_sell(std::string num)
{
    int sum_jenesiss = 0;
    int result = sqlite3_open("car", &db1); // car라는 이름을 가진 db를 열기
    const char *come_jenesiss;
    if (num == "5월")
    {
        come_jenesiss = "SELECT May FROM cars WHERE Brand = '제네시스'"; // Brand의 값이 제네시스대인 May의 값을 불러오도록 지정
    }
    else if (num == "6월")
    {
        come_jenesiss = "SELECT June FROM cars WHERE Brand = '제네시스'"; // Brand의 값이 제네시스인 June의 값을 불러오도록 지정
    }
    else if (num == "7월")
    {
        come_jenesiss = "SELECT July FROM cars WHERE Brand = '제네시스'"; // Brand의 값이 제네시스스인 July의 값을 불러오도록 지정
    }

    result = sqlite3_prepare_v2(db1, come_jenesiss, -1, &stmt_check1, nullptr); // 쿼리준비(데이터베이스, 조건, -1이면 자동)
    if (result != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(db1) << std::endl;
        sqlite3_close(db1);
        return result;
    }
    int month_value = 0;
    while (sqlite3_step(stmt_check1) == SQLITE_ROW)
    {
        const char *monthstr = reinterpret_cast<const char *>(sqlite3_column_text(stmt_check1, 0));
        month_value = std::stoi(monthstr); // const char*을 정수형으로 변환
        sum_jenesiss += month_value;
    }
    sqlite3_finalize(stmt_check1);
    sqlite3_close(db1); // 데이터베이스 닫기
    return sum_jenesiss;
}

int Brand_All_Sales_Count::Come_chevrolet_sell(std::string num)
{
    int sum_chevrolet = 0;
    int result = sqlite3_open("car", &db1); // car라는 이름을 가진 db를 열기
    const char *come_chevrolet;
    if (num == "5월")
    {
        come_chevrolet = "SELECT May FROM cars WHERE Brand = '쉐보레'"; // Brand의 값이 쉐보레인 May의 값을 불러오도록 지정
    }
    else if (num == "6월")
    {
        come_chevrolet = "SELECT June FROM cars WHERE Brand = '쉐보레'"; // Brand의 값이 쉐보레인 June의 값을 불러오도록 지정
    }
    else if (num == "7월")
    {
        come_chevrolet = "SELECT July FROM cars WHERE Brand = '쉐보레'"; // Brand의 값이 쉐보레레인 July의 값을 불러오도록 지정
    }

    result = sqlite3_prepare_v2(db1, come_chevrolet, -1, &stmt_check1, nullptr); // 쿼리준비(데이터베이스, 조건, -1이면 자동)
    if (result != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(db1) << std::endl;
        sqlite3_close(db1);
        return result;
    }
    int month_value = 0;
    while (sqlite3_step(stmt_check1) == SQLITE_ROW)
    {
        const char *monthstr = reinterpret_cast<const char *>(sqlite3_column_text(stmt_check1, 0));
        month_value = std::stoi(monthstr); // const char*을 정수형으로 변환
        sum_chevrolet += month_value;
    }
    sqlite3_finalize(stmt_check1);
    sqlite3_close(db1); // 데이터베이스 닫기
    return sum_chevrolet;
}

int Brand_All_Sales_Count::Come_kgmobility_sell(std::string num)
{
    int sum_kgmobility = 0;
    int result = sqlite3_open("car", &db1); // car라는 이름을 가진 db를 열기
    const char *come_kgmobility;
    if (num == "5월")
    {
        come_kgmobility = "SELECT May FROM cars WHERE Brand = 'KGMobility'"; // Brand의 값이 KGMobility인 May의 값을 불러오도록 지정
    }
    else if (num == "6월")
    {
        come_kgmobility = "SELECT June FROM cars WHERE Brand = 'KGMobility'"; // Brand의 값이 KGMobility인 June의 값을 불러오도록 지정
    }
    else if (num == "7월")
    {
        come_kgmobility = "SELECT July FROM cars WHERE Brand = 'KGMobility'"; // Brand의 값이 KGMobility인 July의 값을 불러오도록 지정
    }

    result = sqlite3_prepare_v2(db1, come_kgmobility, -1, &stmt_check1, nullptr); // 쿼리준비(데이터베이스, 조건, -1이면 자동)
    if (result != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(db1) << std::endl;
        sqlite3_close(db1);
        return result;
    }
    int month_value = 0;
    while (sqlite3_step(stmt_check1) == SQLITE_ROW)
    {
        const char *monthstr = reinterpret_cast<const char *>(sqlite3_column_text(stmt_check1, 0));
        month_value = std::stoi(monthstr); // const char*을 정수형으로 변환
        sum_kgmobility += month_value;
    }
    sqlite3_finalize(stmt_check1);
    sqlite3_close(db1); // 데이터베이스 닫기
    return sum_kgmobility;
}

int Brand_All_Sales_Count::Come_renault_sell(std::string num)
{
    int sum_renault = 0;
    int result = sqlite3_open("car", &db1); // car라는 이름을 가진 db를 열기
    const char *come_renault;
    if (num == "5월")
    {
        come_renault = "SELECT May FROM cars WHERE Brand = '르노'"; // Brand의 값이 르노인 May의 값을 불러오도록 지정
    }
    else if (num == "6월")
    {
        come_renault = "SELECT June FROM cars WHERE Brand = '르노'"; // Brand의 값이 르노인 June의 값을 불러오도록 지정
    }
    else if (num == "7월")
    {
        come_renault = "SELECT July FROM cars WHERE Brand = '르노'"; // Brand의 값이 르노인 July의 값을 불러오도록 지정
    }

    result = sqlite3_prepare_v2(db1, come_renault, -1, &stmt_check1, nullptr); // 쿼리준비(데이터베이스, 조건, -1이면 자동)
    if (result != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(db1) << std::endl;
        sqlite3_close(db1);
        return result;
    }
    int month_value = 0;
    while (sqlite3_step(stmt_check1) == SQLITE_ROW)
    {
        const char *monthstr = reinterpret_cast<const char *>(sqlite3_column_text(stmt_check1, 0));
        month_value = std::stoi(monthstr); // const char*을 정수형으로 변환
        sum_renault += month_value;
    }
    sqlite3_finalize(stmt_check1);
    sqlite3_close(db1); // 데이터베이스 닫기
    return sum_renault;
}
