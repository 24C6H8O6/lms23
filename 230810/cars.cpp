#include "cars.h"

void All_car::May()
{
    std::cout << "┌─────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                                             │" << std::endl;
    std::cout << "│             5월 자동차 판매 실적            │" << std::endl;
    std::cout << "│                                             │" << std::endl;
    std::cout << "└─────────────────────────────────────────────┘" << std::endl;

    // 5월 판매량 총합
    const char *sql = "SELECT SUM(May) FROM cars;"; // 5월 판매량의 총합을 계산하기 위해 sql 쿼리를 저장
    sqlite3_stmt *stmt = nullptr;                   // sql문장 핸들러
    totalsales = 0;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) == SQLITE_OK) // sql문을 컴파일하여 준비
    {
        if (sqlite3_step(stmt) == SQLITE_ROW) // 준비된 sql문을 실행하고 결과를 확인
        {
            totalsales = sqlite3_column_double(stmt, 0); // May 컬럼 합계를 double로 가져옴
        }

        sqlite3_finalize(stmt); // 준비된 문장 핸들러를 종료
    }

    std::cout << "5월판매량: " << totalsales << " 대" << std::endl;

    const char *sql2 = "SELECT Brand, Type, Model, May FROM cars ORDER BY May DESC;"; // 브랜드,타입,모델,5월 판매량을 가져오기 위한 sql문 정의

    if (sqlite3_prepare_v2(db, sql2, -1, &stmt, 0) == SQLITE_OK) // 쿼리 실행할 준비
    {
        int ranking = 1; // 순서대로 출력하기 위한 변수
        int columnCount = sqlite3_column_count(stmt);

        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            std::cout << ranking << ". "; // 순서 출력

            for (int i = 0; i < columnCount; i++)
            {
                const char *columnText = reinterpret_cast<const char *>(sqlite3_column_text(stmt, i)); // 결과 집합에서 열 값을 가져온다
                if (i == 3)                                                                            // May 컬럼 처리
                {
                    double mayvalue = sqlite3_column_double(stmt, i); // double 값으로 변환
                    double percentage = (mayvalue / totalsales) * 100;
                    std::cout << static_cast<int>(mayvalue) << " (" << std::fixed << std::setprecision(1) << percentage << "%) ";
                }
                else
                {
                    std::cout << (columnText ? columnText : "") << " "; // columnText가 널문자가 아니면 출력 맞으면 " "출력
                }
            }

            std::cout << std::endl;

            ranking++; // 다음 순위로 증가
        }

        sqlite3_finalize(stmt);
    }
}

void All_car::June()
{
    std::cout << "┌─────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                                             │" << std::endl;
    std::cout << "│             6월 자동차 판매 실적            │" << std::endl;
    std::cout << "│                                             │" << std::endl;
    std::cout << "└─────────────────────────────────────────────┘" << std::endl;

    // 6월 판매량 총합
    const char *sql = "SELECT SUM(June) FROM cars;";
    sqlite3_stmt *stmt = nullptr;
    totalsales = 0;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) == SQLITE_OK)
    {
        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            totalsales = sqlite3_column_double(stmt, 0); // June 컬럼 합계를 double로 가져옴
        }

        sqlite3_finalize(stmt);
    }

    std::cout << "6월판매량: " << totalsales << " 대" << std::endl;

    const char *sql2 = "SELECT Brand, Type, Model, June FROM cars ORDER BY June DESC;";

    if (sqlite3_prepare_v2(db, sql2, -1, &stmt, 0) == SQLITE_OK)
    {
        int ranking = 1; // 순서대로 출력하기 위한 변수
        int columnCount = sqlite3_column_count(stmt);

        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            std::cout << ranking << ". "; // 순서 출력

            for (int i = 0; i < columnCount; i++)
            {
                const char *columnText = reinterpret_cast<const char *>(sqlite3_column_text(stmt, i));
                if (i == 3) // May 컬럼 처리
                {
                    double mayvalue = sqlite3_column_double(stmt, i); // double 값으로 변환
                    double percentage = (mayvalue / totalsales) * 100;
                    std::cout << static_cast<int>(mayvalue) << " (" << std::fixed << std::setprecision(1) << percentage << "%) ";
                }
                else
                {
                    std::cout << (columnText ? columnText : "") << " ";
                }
            }

            std::cout << std::endl;

            ranking++; // 다음 순위로 증가
        }

        sqlite3_finalize(stmt);
    }
}

void All_car::July()
{
    std::cout << "┌─────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                                             │" << std::endl;
    std::cout << "│             7월 자동차 판매 실적            │" << std::endl;
    std::cout << "│                                             │" << std::endl;
    std::cout << "└─────────────────────────────────────────────┘" << std::endl;

    // 7월 판매량 총합
    const char *sql = "SELECT SUM(July) FROM cars;";
    sqlite3_stmt *stmt = nullptr;
    totalsales = 0;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) == SQLITE_OK)
    {
        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            totalsales = sqlite3_column_double(stmt, 0); // July 컬럼 합계를 double로 가져옴
        }

        sqlite3_finalize(stmt);
    }

    std::cout << "7월판매량: " << totalsales << " 대" << std::endl;

    const char *sql2 = "SELECT Brand, Type, Model, July FROM cars ORDER BY July DESC;";

    if (sqlite3_prepare_v2(db, sql2, -1, &stmt, 0) == SQLITE_OK)
    {
        int ranking = 1; // 순서대로 출력하기 위한 변수
        int columnCount = sqlite3_column_count(stmt);

        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            std::cout << ranking << ". "; // 순서 출력

            for (int i = 0; i < columnCount; i++)
            {
                const char *columnText = reinterpret_cast<const char *>(sqlite3_column_text(stmt, i));
                if (i == 3) // May 컬럼 처리
                {
                    double mayvalue = sqlite3_column_double(stmt, i); // double 값으로 변환
                    double percentage = (mayvalue / totalsales) * 100;
                    std::cout << static_cast<int>(mayvalue) << " (" << std::fixed << std::setprecision(1) << percentage << "%) ";
                }
                else
                {
                    std::cout << (columnText ? columnText : "") << " ";
                }
            }

            std::cout << std::endl;

            ranking++; // 다음 순위로 증가
        }

        sqlite3_finalize(stmt);
    }
}