#include "cars.h"

int All_Main::Main()
{
    sqlite3 *db;
    All_car allcar("car");
    Brand_Main_Logic BML;
    carType Type;
    // 차종 선택을 위한 변수
    int number;
    int number1;
    if (!allcar.isopen())
    {
        std::cerr << "Failed to open database." << std::endl;
        return 1;
    }

    system("clear");

    int menu_num;

    while (1)
    {
        system("clear");

        std::cout << "┌─────────────────────────────────────────────┐" << std::endl;
        std::cout << "│          원하는 메뉴를 선택하세요.          │" << std::endl;
        std::cout << "│                                             │" << std::endl;
        std::cout << "│      1.전체 판매실적                        │" << std::endl;
        std::cout << "│      2.브랜드별 판매실적                    │" << std::endl;
        std::cout << "│      3.차종별 판매실적                      │" << std::endl;
        std::cout << "│      4.그만하기                             │" << std::endl;
        std::cout << "└─────────────────────────────────────────────┘" << std::endl;
        std::cin >> menu_num;
        system("clear");

        switch (menu_num)
        {
        case 1:
            system("clear");
            while (1)
            {
                std::cout << "┌─────────────────────────────────────────────┐" << std::endl;
                std::cout << "│          원하는 달을 선택하세요.            │" << std::endl;
                std::cout << "│                                             │" << std::endl;
                std::cout << "│      1. 5월                                 │" << std::endl;
                std::cout << "│      2. 6월                                 │" << std::endl;
                std::cout << "│      3. 7월                                 │" << std::endl;
                std::cout << "│      4. 그만하기                            │" << std::endl;
                std::cout << "└─────────────────────────────────────────────┘" << std::endl;
                int all_num;
                std::cin >> all_num;

                switch (all_num)
                {
                case 1:
                    system("clear");
                    allcar.May();
                    continue;

                case 2:
                    system("clear");
                    allcar.June();
                    continue;

                case 3:
                    system("clear");
                    allcar.July();
                    continue;

                case 4:
                    std::cout << "┌─────────────────────────────────────────────┐" << std::endl;
                    std::cout << "│                                             │" << std::endl;
                    std::cout << "│          그만하기를 선택하셨습니다.         │" << std::endl;
                    std::cout << "│                                             │" << std::endl;
                    std::cout << "└─────────────────────────────────────────────┘" << std::endl;
                    sleep(3);
                    system("clear");
                    break;
                    // exit(0);

                default:
                    std::cout << "┌─────────────────────────────────────────────┐" << std::endl;
                    std::cout << "│             잘못 입력하였습니다.            │" << std::endl;
                    std::cout << "│              다시 입력해주세요.             │" << std::endl;
                    std::cout << "└─────────────────────────────────────────────┘" << std::endl;
                    sleep(3);
                    system("clear");
                    break;
                }
                break;
            }
            continue;

        case 2:
            BML.Brand_Logic();
            continue;

        case 3:
            number = 0;
            while (!number)
            {
                number1 = 0;
                number = Type.choiceType(number);
                if (number == 1)
                {
                    break;
                }
                Type.type();

                while (!number1)
                {
                    number1 = Type.choiceMonth(number1);
                    if (number1 == 1)
                    {
                        break;
                    }
                    Type.type_month();
                }
            }

            continue;

        case 4:
            std::cout << "┌─────────────────────────────────────────────┐" << std::endl;
            std::cout << "│                                             │" << std::endl;
            std::cout << "│          그만하기를 선택하셨습니다.         │" << std::endl;
            std::cout << "│                                             │" << std::endl;
            std::cout << "└─────────────────────────────────────────────┘" << std::endl;
            exit(0);

            continue;

        default:
            std::cout << "┌─────────────────────────────────────────────┐" << std::endl;
            std::cout << "│             잘못 입력하였습니다.            │" << std::endl;
            std::cout << "│              다시 입력해주세요.             │" << std::endl;
            std::cout << "└─────────────────────────────────────────────┘" << std::endl;
            sleep(3);
            system("clear");
            break;
        }
    }
    // allcar.May();
    // allcar.June();
    // allcar.July();
    sqlite3_close(db);
    return 0;
}