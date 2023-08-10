#ifndef CARS1_H_
#define CARS1_H_

#include <stdio.h>
#include <iostream>
#include <sqlite3.h>
#include <unistd.h>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>

class carType
{
private:
    // 초기 세팅을 위한 값들
    sqlite3 *db;
    char *err_msg = 0;
    sqlite3_stmt *res;
    std::string car_type;
    sqlite3_stmt *stmt_check2;
    // 다나와 사이트에서 봤던 것처럼 선택했을 때 초기 값이 7월로 정해져 나와서
    // 7월로 정했고 나중에 이 값 바꾸면 초기에 다른 월로 조회 가능
    std::string month;
    int flag1 = 0;    // choiceType()함수의 반복문을 돌리기 위한 것
    int flag2 = 0;    // choiceMonth()함수의 반복문을 돌리기 위한 것
    int choice_type;  // 차종을 숫자로 입력받음 -> type12 벡터의 문자로 바꾸기 위한 수단
    int choice_month; // 월을 숫자로 입력받음 -> month3 벡터의 문자로 바꾸기 위한 수단
    // 차종 벡터
    std::vector<std::string> type12 = {"경차", "소형", "준중형", "중형", "준대형", "대형", "스포츠카", "소형SUV", "중형SUV", "대형SUV", "RV/MPV", "상용"};
    // 월 벡터
    std::vector<std::string> month3 = {"May", "June", "July"};

public:
    // 차종 선택
    int type();
    int type_month();
    int choiceType(int num);
    int choiceMonth(int num);
};

#endif