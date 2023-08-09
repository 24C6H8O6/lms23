#include <iostream>
#include <sqlite3.h>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <cstring>
#include <iomanip>
class carMonth
{
};

class carType
{
private:
    sqlite3 *db;
    char *err_msg = 0;
    sqlite3_stmt *res;
    std::string car_type;
    std::string month = "July";
    sqlite3_stmt *stmt_check2;
    int flag1 = 0;
    int flag2 = 0;
    vector;

public:
    int type();
    int type_month();
};

int carType::type()
{
    flag1 = 0;
    flag2 = 0;
    // DB열기
    int result = sqlite3_open("car", &db);
    // 차종 선택
    while (!flag1)
    {
        std::cout << "차종을 선택하세요" << std::endl;
        std::cout << "경차, 소형, 준중형, 중형, 준대형, 스포츠카" << std::endl;
        std::cout << "소형SUV, 중형SUV, 대형SUV, RV/MPV, 상용" << std::endl;
        std::cin >> car_type;
        if (car_type == "경차" || car_type == "소형" || car_type == "준중형" || car_type == "중형" || car_type == "준대형" || car_type == "스포츠카" || car_type == "소형SUV" || car_type == "중형SUV" || car_type == "대형SUV" || car_type == "RV/MPV" || car_type == "상용")
        {
            flag1 = 1;
        }
        else
        {
            std::cout << "잘못입력하셨습니다. 다시 입력 요망!!" << std::endl;
            continue;
        }
    }
    // 월 선택
    // while (!flag2)
    // {
    //     std::cout << "월을 입력하세요" << std::endl;
    //     std::cout << "May, June, July" << std::endl;
    //     std::cin >> month;
    //     if (month == "May" || month == "June" || month == "July")
    //     {
    //         flag2 = 1;
    //     }
    //     else
    //     {
    //         std::cout << "잘못입력하셨습니다. 다시 입력 요망!!" << std::endl;
    //         continue;
    //     }
    // }
    // 총합 sql문
    std::string sql = "SELECT SUM(" + month + ") FROM cars WHERE Type=?;";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt_check2, 0) != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
    sqlite3_bind_text(stmt_check2, 1, car_type.c_str(), -1, SQLITE_STATIC);
    unsigned int sumCar = 0;
    if (sqlite3_step(stmt_check2) == SQLITE_ROW)
    {
        sumCar = sqlite3_column_int(stmt_check2, 0);
    }
    std::cout << "총합 : " << sumCar << std::endl;

    // 타입별 sql문
    std::string sql2 = "SELECT Brand, Model, " + month + " FROM cars WHERE Type=? ORDER BY " + month + " DESC;";
    // std::cout << sql;
    if (sqlite3_prepare_v2(db, sql2.c_str(), -1, &stmt_check2, 0) != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
    // 물음표(?)에 car_type 대입
    sqlite3_bind_text(stmt_check2, 1, car_type.c_str(), -1, SQLITE_STATIC);

    if (month == "May")
    {
        month = "5";
    }
    else if (month == "June")
    {
        month = "6";
    }
    else if (month == "July")
    {
        month = "7";
    }
    // std::cout << "순번\t브랜드\t모델\t" << month << "월 판매량 점유율" << std::endl;
    std::cout << std::left << std::setw(30) << "순번"
              << std::left << std::setw(30) << "브랜드"
              << std::left << std::setw(30) << "모델"
              << std::left << std::setw(30) << "월 판매량"
              << std::left << std::setw(30) << "점유율" << std::endl;
    int number = 1;

    while (sqlite3_step(stmt_check2) == SQLITE_ROW)
    {
        // sqlite3_column_text가 const unsigned char형으로 반환함
        const unsigned char *brand = (sqlite3_column_text(stmt_check2, 0));
        const unsigned char *model = (sqlite3_column_text(stmt_check2, 1));
        int month = sqlite3_column_int(stmt_check2, 2);
        double salesShare = ((month / (double)sumCar) * 100);
        std::cout.precision(0);
        std::cout << std::left << std::setw(30) << number << std::left << std::setw(30) << brand
                  << std::left << std::setw(30) << model << std::left << std::setw(30) << month << " (";
        std::cout.precision(2);
        std::cout << salesShare << "%)" << std::endl;
        number++;
    }

    // 수행하는 구문 종료
    sqlite3_finalize(stmt_check2);
    // sqlite3 종료
    sqlite3_close(db);
}

int carType::type_month()
{

    flag1 = 0;
    flag2 = 0;
    // DB열기
    int result = sqlite3_open("car", &db);
    // 차종 선택
    while (!flag1)
    {
        std::cout << "차종을 선택하세요" << std::endl;
        std::cout << "경차, 소형, 준중형, 중형, 준대형, 스포츠카" << std::endl;
        std::cout << "소형SUV, 중형SUV, 대형SUV, RV/MPV, 상용" << std::endl;
        std::cin >> car_type;
        if (car_type == "경차" || car_type == "소형" || car_type == "준중형" || car_type == "중형" || car_type == "준대형" || car_type == "스포츠카" || car_type == "소형SUV" || car_type == "중형SUV" || car_type == "대형SUV" || car_type == "RV/MPV" || car_type == "상용")
        {
            flag1 = 1;
        }
        else
        {
            std::cout << "잘못입력하셨습니다. 다시 입력 요망!!" << std::endl;
            continue;
        }
    }
    while (!flag2)
    {
        std::cout << "월을 입력하세요" << std::endl;
        std::cout << "May, June, July" << std::endl;
        std::cin >> month;
        if (month == "May" || month == "June" || month == "July")
        {
            flag2 = 1;
        }
        else
        {
            std::cout << "잘못입력하셨습니다. 다시 입력 요망!!" << std::endl;
            continue;
        }
    }
    // 총합 sql문
    std::string sql = "SELECT SUM(" + month + ") FROM cars WHERE Type=?;";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt_check2, 0) != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
    sqlite3_bind_text(stmt_check2, 1, car_type.c_str(), -1, SQLITE_STATIC);
    unsigned int sumCar = 0;
    if (sqlite3_step(stmt_check2) == SQLITE_ROW)
    {
        sumCar = sqlite3_column_int(stmt_check2, 0);
    }
    std::cout << "총합 : " << sumCar << std::endl;

    // 타입별 sql문
    std::string sql2 = "SELECT Brand, Model, " + month + " FROM cars WHERE Type=? ORDER BY " + month + " DESC;";
    // std::cout << sql;
    if (sqlite3_prepare_v2(db, sql2.c_str(), -1, &stmt_check2, 0) != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
    // 물음표(?)에 car_type 대입
    sqlite3_bind_text(stmt_check2, 1, car_type.c_str(), -1, SQLITE_STATIC);

    if (month == "May")
    {
        month = "5";
    }
    else if (month == "June")
    {
        month = "6";
    }
    else if (month == "July")
    {
        month = "7";
    }
    // std::cout << "순번\t브랜드\t모델\t" << month << "월 판매량 점유율" << std::endl;
    std::cout << std::left << std::setw(30) << "순번"
              << std::left << std::setw(30) << "브랜드"
              << std::left << std::setw(30) << "모델"
              << std::left << std::setw(30) << "월 판매량"
              << std::left << std::setw(30) << "점유율" << std::endl;
    int number = 1;

    while (sqlite3_step(stmt_check2) == SQLITE_ROW)
    {
        // sqlite3_column_text가 const unsigned char형으로 반환함
        const unsigned char *brand = (sqlite3_column_text(stmt_check2, 0));
        const unsigned char *model = (sqlite3_column_text(stmt_check2, 1));
        int month = sqlite3_column_int(stmt_check2, 2);
        double salesShare = ((month / (double)sumCar) * 100);
        std::cout.precision(0);
        std::cout << std::left << std::setw(30) << number << std::left << std::setw(30) << brand
                  << std::left << std::setw(30) << model << std::left << std::setw(30) << month << " (";
        std::cout.precision(2);
        std::cout << salesShare << "%)" << std::endl;
        number++;
    }

    // 수행하는 구문 종료
    sqlite3_finalize(stmt_check2);
    // sqlite3 종료
    sqlite3_close(db);
}

int main()
{
    carType Type;
    Type.type();
    Type.type_month();
    return 0;
}