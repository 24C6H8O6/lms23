#include "Brand.h"

void Brand_Main_Logic::Brand_Rank()
{
    std::string select_month;
    std::string select_brand;
    std::string select_month1;
    int all_sum = 0;
    int sum_kia, sum_hyunda, sum_jenesiss, sum_kgmobility, sum_renault, sum_chevrolet;
    while (true)
    {
        std::cout << "(국산브랜드)조회할 월을 선택해주세요.(종료)" << std::endl;
        std::cout << "5월  6월  7월  종료" << std::endl;
        std::cout << "선택 : ";
        std::cin >> select_month;
        if (select_month == "5월" || select_month == "6월" || select_month == "7월")
        {
            system("clear");
            sum_hyunda = BASC.Come_hyunda_sell(select_month);
            sum_kia = BASC.Come_kia_sell(select_month);
            sum_chevrolet = BASC.Come_chevrolet_sell(select_month);
            sum_jenesiss = BASC.Come_jenesiss_sell(select_month);
            sum_kgmobility = BASC.Come_kgmobility_sell(select_month);
            sum_renault = BASC.Come_renault_sell(select_month);

            std::vector<int> brand_rank = {sum_hyunda, sum_chevrolet, sum_jenesiss, sum_kgmobility, sum_kia, sum_renault};
            std::vector<std::string> brand_name = {"기아", "현대", "제네시스", "쉐보레", "KG모빌리티", "르노코리아"};
            std::sort(brand_rank.begin(), brand_rank.end());
            std::reverse(brand_rank.begin(), brand_rank.end());

            for (int j = 0; j <= 5; j++)
            {
                all_sum += brand_rank[j];
            }
            std::cout << "┌─────────────────────────────────────────────┐" << std::endl;
            std::cout << "│                                             │" << std::endl;
            std::cout << "│        브랜드별 " << select_month << " 자동차 판매 실적        │" << std::endl;
            std::cout << "│                                             │" << std::endl;
            std::cout << "└─────────────────────────────────────────────┘" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "총 판매량 : " << all_sum << "대" << std::endl;
            double nanure;

            std::cout << "순위\t브랜드명\t판매량\t점유율" << std::endl;
            for (int i = 0; i <= 6; i++)
            {
                nanure = (100.0 * brand_rank[i] / all_sum);
                if (brand_rank[i] == sum_hyunda)
                {
                    std::cout << std::left << i + 1 << "\t" << std::setw(15) << "현대"
                              << "\t" << brand_rank[i] << "\t"
                              << std::fixed << std::setprecision(2) << nanure << std::endl;
                }
                else if (brand_rank[i] == sum_kia)
                {
                    std::cout << std::left << i + 1 << "\t" << std::setw(15) << "기아"
                              << "\t" << brand_rank[i] << "\t"
                              << std::fixed << std::setprecision(2) << nanure << "%" << std::endl;
                }
                else if (brand_rank[i] == sum_jenesiss)
                {
                    std::cout << std::left << i + 1 << "\t" << std::setw(15) << "제네시스"
                              << "\t" << brand_rank[i] << "\t"
                              << std::fixed << std::setprecision(2) << nanure << "%" << std::endl;
                }
                else if (brand_rank[i] == sum_chevrolet)
                {
                    std::cout << std::left << i + 1 << "\t" << std::setw(15) << "쉐보레"
                              << "\t" << brand_rank[i] << "\t"
                              << std::fixed << std::setprecision(2) << nanure << "%" << std::endl;
                }
                else if (brand_rank[i] == sum_kgmobility)
                {
                    std::cout << std::left << i + 1 << "\t" << std::setw(15) << "KG모빌리티"
                              << "\t" << brand_rank[i] << "\t"
                              << std::fixed << std::setprecision(2) << nanure << "%" << std::endl;
                }
                else if (brand_rank[i] == sum_renault)
                {
                    std::cout << std::left << i + 1 << "\t" << std::setw(15) << "르노코리아"
                              << "\t" << brand_rank[i] << "\t"
                              << std::fixed << std::setprecision(2) << nanure << "%" << std::endl;
                }
            }
            break;
        }

        else if (select_month == "종료")
        {
            exit(0);
        }

        else
        {
            system("clear");
            std::cout << select_month << "는 잘못된 입력입니다. 다시 입력해주세요." << std::endl;
        }
    }
}

void Brand_Main_Logic::Brand_Logic()
{
    std::string select_month;
    std::string select_brand;
    std::string select_month1;
    int all_sum = 0;
    int sum_kia, sum_hyunda, sum_jenesiss, sum_kgmobility, sum_renault, sum_chevrolet;

    while (true)
    {
        Brand_Rank();
        std::cout << "브랜드를 선택해주세요.(뒤로가기, 종료)" << std::endl;
        std::cout << "선택 : ";
        std::cin >> select_brand;
        if (select_brand == "현대")
        {
            while (true)
            {
                std::cout << "(현대)조회할 월을 입력해주세요." << std::endl;
                std::cout << "5월   6월  7월  (뒤로가기, 종료)" << std::endl;
                std::cout << "선택 : ";
                std::cin >> select_month1;
                system("clear");
                if (select_month1 == "5월" || select_month1 == "6월" || select_month1 == "7월")
                {
                    BESC.Come_hyunda_rank(select_month1);
                }
                else if (select_month1 == "종료")
                {
                    system("clear");
                    exit(0);
                }
                else if (select_month1 == "뒤로가기")
                {
                    system("clear");
                    break;
                }
                else
                {
                    std::cout << select_month1 << "는 잘못된 입력입니다. 다시 입력해주세요." << std::endl;
                }
            }
        }

        else if (select_brand == "기아")
        {
            while (true)
            {
                std::cout << "(기아)조회할 월을 입력해주세요." << std::endl;
                std::cout << "5월   6월  7월  (뒤로가기, 종료)" << std::endl;
                std::cout << "선택 : ";
                std::cin >> select_month1;
                system("clear");
                if (select_month1 == "5월" || select_month1 == "6월" || select_month1 == "7월")
                {
                    BESC.Come_kia_rank(select_month1);
                }
                else if (select_month1 == "종료")
                {
                    system("clear");
                    exit(0);
                }
                else if (select_month1 == "뒤로가기")
                {
                    system("clear");
                    break;
                }
                else
                {
                    std::cout << select_month1 << "는 잘못된 입력입니다. 다시 입력해주세요." << std::endl;
                }
            }
        }

        else if (select_brand == "제네시스")
        {
            while (true)
            {
                std::cout << "(제네시스)조회할 월을 입력해주세요." << std::endl;
                std::cout << "5월   6월  7월  (뒤로가기, 종료)" << std::endl;
                std::cout << "선택 : ";
                std::cin >> select_month1;
                system("clear");
                if (select_month1 == "5월" || select_month1 == "6월" || select_month1 == "7월")
                {
                    BESC.Come_jenesiss_rank(select_month1);
                }
                else if (select_month1 == "종료")
                {
                    system("clear");
                    exit(0);
                }
                else if (select_month1 == "뒤로가기")
                {
                    system("clear");
                    break;
                }
                else
                {
                    std::cout << select_month1 << "는 잘못된 입력입니다. 다시 입력해주세요." << std::endl;
                }
            }
        }

        else if (select_brand == "쉐보레")
        {
            while (true)
            {
                std::cout << "(쉐보레)조회할 월을 입력해주세요." << std::endl;
                std::cout << "5월   6월  7월  (뒤로가기, 종료)" << std::endl;
                std::cout << "선택 : ";
                std::cin >> select_month1;
                system("clear");
                if (select_month1 == "5월" || select_month1 == "6월" || select_month1 == "7월")
                {
                    BESC.Come_chevrolet_rank(select_month1);
                }
                else if (select_month1 == "종료")
                {
                    system("clear");
                    exit(0);
                }
                else if (select_month1 == "뒤로가기")
                {
                    system("clear");
                    break;
                }
                else
                {
                    std::cout << select_month1 << "는 잘못된 입력입니다. 다시 입력해주세요." << std::endl;
                }
            }
        }

        else if (select_brand == "KG모빌리티")
        {
            while (true)
            {
                std::cout << "(KG모빌리티)조회할 월을 입력해주세요." << std::endl;
                std::cout << "5월   6월  7월  (뒤로가기, 종료)" << std::endl;
                std::cout << "선택 : ";
                std::cin >> select_month1;
                system("clear");
                if (select_month1 == "5월" || select_month1 == "6월" || select_month1 == "7월")
                {
                    BESC.Come_kgmobility_rank(select_month1);
                }
                else if (select_month1 == "종료")
                {
                    system("clear");
                    exit(0);
                }
                else if (select_month1 == "뒤로가기")
                {
                    system("clear");
                    break;
                }
                else
                {
                    std::cout << select_month1 << "는 잘못된 입력입니다. 다시 입력해주세요." << std::endl;
                }
            }
        }

        else if (select_brand == "르노코리아")
        {
            while (true)
            {
                std::cout << "(르노코리아)조회할 월을 입력해주세요." << std::endl;
                std::cout << "5월   6월  7월  (뒤로가기, 종료)" << std::endl;
                std::cout << "선택 : ";
                std::cin >> select_month1;
                system("clear");
                if (select_month1 == "5월" || select_month1 == "6월" || select_month1 == "7월")
                {
                    BESC.Come_renault_rank(select_month1);
                }
                else if (select_month1 == "종료")
                {
                    system("clear");
                    exit(0);
                }
                else if (select_month1 == "뒤로가기")
                {
                    system("clear");
                    break;
                }
                else
                {
                    std::cout << select_month1 << "는 잘못된 입력입니다. 다시 입력해주세요." << std::endl;
                }
            }
        }

        else if (select_brand == "종료")
        {
            exit(0);
        }
        else if (select_brand == "뒤로가기")
        {
            system("clear");
            break;
        }
        else
        {
            std::cout << select_brand << "은 잘못된 입력입니다. 다시 입력해주세요." << std::endl;
        }
    }
}
