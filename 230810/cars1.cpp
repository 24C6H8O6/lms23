#include "cars1.h"
int carType::choiceType(int number)
{
    number = 0;
    flag1 = 0;

    while (!flag1)
    {

        std::cout << "┌─────────────────────────────────────────────┐" << std::endl;
        std::cout << "│              차종을 선택하세요              │" << std::endl;
        std::cout << "│                                             │" << std::endl;
        std::cout << "│       1.경차, 2.소형, 3.준중형, 4.중형      │" << std::endl;
        std::cout << "│   5.준대형, 6.대형, 7.스포츠카, 8.소형SUV   │" << std::endl;
        std::cout << "│  9.중형SUV, 10.대형SUV, 11.RV/MPV, 12.상용  │" << std::endl;
        std::cout << "│                 13.그만하기                 │" << std::endl;
        std::cout << "└─────────────────────────────────────────────┘" << std::endl;
        std::cin >> choice_type;
        if (choice_type >= 1 && choice_type <= 12)

        {
            flag1 = 1;
        }
        else if (choice_type == 13)
        {
            std::cout << "종료합니다!!" << std::endl;
            // exit(0);
            number = 1;
            break;
        }
        else
        {
            std::cout << "잘못입력하셨습니다. 다시 입력 요망!!" << std::endl;
            continue;
        }
        car_type = type12[choice_type - 1];
        // 출력문 확인을 위한 작업
        std::cout << car_type << std::endl;
        sleep(1);
        system("clear");
    }
    return number;
}

int carType::choiceMonth(int number)
{
    flag2 = 0;
    number = 0;
    month = "July";
    while (!flag2)
    {
        std::cout << "┌─────────────────────────────────────────────┐" << std::endl;
        std::cout << "│               월을 입력하세요               │" << std::endl;
        std::cout << "│                                             │" << std::endl;
        std::cout << "│            1.May, 2.June, 3.July            │" << std::endl;
        std::cout << "│                 4.그만하기                  │" << std::endl;
        std::cout << "└─────────────────────────────────────────────┘" << std::endl;
        std::cout << "" << std::endl;
        std::cin >> choice_month;
        if (choice_month >= 1 && choice_month <= 3)
        {
            month = month3[choice_month - 1];
            flag2 = 1;
        }
        else if (choice_month == 4)
        {
            std::cout << "종료합니다!!" << std::endl;
            // exit(0);
            number = 1;
            break;
        }
        else
        {
            std::cout << "잘못입력하셨습니다. 다시 입력 요망!!" << std::endl;
            continue;
        }

        // 출력문 확인을 위한 작업
        std::cout << month << std::endl;
        sleep(1);
        system("clear");
    }
    return number;
}

int carType::type()
{

    month = "July";
    // DB열기
    int result = sqlite3_open("car", &db);

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
    std::cout << "순번\t브랜드\t모델\t" << month << "월판매량 점유율" << std::endl;

    // 출력문 관련 문제
    // std::left << std::setw(30) : 30칸에서 왼쪽정렬
    // 한글이 3칸을 잡아먹기에 오류
    // std::cout << std::left << std::setw(30) << "순번"
    //           << std::left << std::setw(30) << "브랜드"
    //           << std::left << std::setw(30) << "모델"
    //           << std::left << std::setw(30) << "월 판매량"
    //           << std::left << std::setw(30) << "점유율" << std::endl;
    int number = 1;

    while (sqlite3_step(stmt_check2) == SQLITE_ROW)
    {
        // sqlite3_column_text가 const unsigned char형으로 반환함
        const unsigned char *brand1 = (sqlite3_column_text(stmt_check2, 0));
        const unsigned char *model1 = (sqlite3_column_text(stmt_check2, 1));
        int month1 = sqlite3_column_int(stmt_check2, 2);
        double salesShare = ((month1 / (double)sumCar) * 100);
        // 실수 출력 원래대로
        std::cout.precision(0);
        std::cout << number << "\t" << brand1
                  << "\t" << model1 << "\t" << month1 << "(";
        // precision(n) : 소수점 유효숫자 n의 자리 출력
        std::cout.precision(3);
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
    // DB열기
    int result = sqlite3_open("car", &db);

    // 총합 sql문
    std::string sql = "SELECT SUM(" + month + ") FROM cars WHERE Type=? AND " + month + ";";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt_check2, 0) != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
    sqlite3_bind_text(stmt_check2, 1, car_type.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt_check2, 2, month.c_str(), -1, SQLITE_STATIC);
    unsigned int sumCar = 0;
    if (sqlite3_step(stmt_check2) == SQLITE_ROW)
    {
        sumCar = sqlite3_column_int(stmt_check2, 0);
    }
    std::cout << "총합 : " << sumCar << std::endl;

    // 타입별 sql문
    std::string sql2 = "SELECT Brand, Model, " + month + " FROM cars WHERE Type=? ORDER BY " + month + " DESC;";
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
    std::cout << "순번\t브랜드\t모델\t" << month << "월판매량 점유율" << std::endl;
    int number = 1;

    while (sqlite3_step(stmt_check2) == SQLITE_ROW)
    {
        // sqlite3_column_text가 const unsigned char형으로 반환함
        const unsigned char *brand1 = (sqlite3_column_text(stmt_check2, 0));
        const unsigned char *model1 = (sqlite3_column_text(stmt_check2, 1));
        int month1 = sqlite3_column_int(stmt_check2, 2);
        double salesShare = ((month1 / (double)sumCar) * 100);
        // 실수 출력 원래대로
        std::cout.precision(0);
        std::cout << number << "\t" << brand1 << "\t"
                  << model1 << "\t" << month1 << "(";
        // precision(n) : 소수점 유효숫자 n의 자리 출력
        std::cout.precision(3);
        std::cout << salesShare << "%)" << std::endl;
        number++;
    }
    sleep(2);
    // 수행하는 구문 종료
    sqlite3_finalize(stmt_check2);
    // sqlite3 종료
    sqlite3_close(db);
}
