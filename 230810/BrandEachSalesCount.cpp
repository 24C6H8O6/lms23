#include "Brand.h"

void Brand_Each_Sales_Count::Come_kia_rank(std::string select_month)
{
    int sum = 0;
    sum = BASC.Come_kia_sell(select_month);
    int result = sqlite3_open("car", &db3);
    const char *come_kia;
    if (select_month == "5월")
    {
        come_kia = "SELECT Model, May FROM cars WHERE Brand = '기아' ORDER BY May DESC";
    }
    else if (select_month == "6월")
    {
        come_kia = "SELECT Model, June FROM cars WHERE Brand = '기아' ORDER BY June DESC";
    }
    else if (select_month == "7월")
    {
        come_kia = "SELECT Model, July FROM cars WHERE Brand = '기아' ORDER BY July DESC";
    }

    result = sqlite3_prepare_v2(db3, come_kia, -1, &stmt_check3, nullptr);

    if (result != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(db3) << std::endl;
        sqlite3_close(db3);
    }

    int rank_cnt = 1;
    int sum_month = 0;
    double bac;
    std::cout << "┌─────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                                             │" << std::endl;
    std::cout << "│          기아 " + select_month + " 자동차 판매 실적          │" << std::endl;
    std::cout << "│                                             │" << std::endl;
    std::cout << "└─────────────────────────────────────────────┘" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "순위     모델          판매량(점유율)" << std::endl;
    while (sqlite3_step(stmt_check3) == SQLITE_ROW)
    {
        const char *model = reinterpret_cast<const char *>(sqlite3_column_text(stmt_check3, 0));
        const char *month = reinterpret_cast<const char *>(sqlite3_column_text(stmt_check3, 1));

        bac = std::stoi(month);
        double nanu = (100 * bac / sum);
        std::cout << std::left << rank_cnt;
        std::cout << "\t" << std::setw(15) << model;
        std::cout << "\t" << std::right << month << "(" << std::fixed << std::setprecision(3) << nanu << "%)" << std::endl;
        rank_cnt++;
    }
    sqlite3_finalize(stmt_check3);
    sqlite3_close(db3);
}

void Brand_Each_Sales_Count::Come_hyunda_rank(std::string select_month)
{
    int sum = 0;
    sum = BASC.Come_hyunda_sell(select_month);
    int result = sqlite3_open("car", &db3);
    const char *come_hyunda;
    if (select_month == "5월")
    {
        come_hyunda = "SELECT Model, May FROM cars WHERE Brand = '현대' ORDER BY May DESC";
    }
    else if (select_month == "6월")
    {
        come_hyunda = "SELECT Model, June FROM cars WHERE Brand = '현대' ORDER BY June DESC";
    }
    else if (select_month == "7월")
    {
        come_hyunda = "SELECT Model, July FROM cars WHERE Brand = '현대' ORDER BY July DESC";
    }

    result = sqlite3_prepare_v2(db3, come_hyunda, -1, &stmt_check3, nullptr);

    if (result != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(db3) << std::endl;
        sqlite3_close(db3);
    }

    int rank_cnt = 1;
    int sum_month = 0;
    double bac;
    std::cout << "┌─────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                                             │" << std::endl;
    std::cout << "│          현대 " + select_month + " 자동차 판매 실적          │" << std::endl;
    std::cout << "│                                             │" << std::endl;
    std::cout << "└─────────────────────────────────────────────┘" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "순위     모델                  판매량(점유율)" << std::endl;
    while (sqlite3_step(stmt_check3) == SQLITE_ROW)
    {
        const char *model = reinterpret_cast<const char *>(sqlite3_column_text(stmt_check3, 0));
        const char *month = reinterpret_cast<const char *>(sqlite3_column_text(stmt_check3, 1));

        bac = std::stoi(month);
        double nanu = (100 * bac / sum);
        std::cout << std::left << rank_cnt;
        std::cout << "\t" << std::setw(35) << model;
        std::cout << "\t" << std::right << month << "(" << std::fixed << std::setprecision(3) << nanu << "%)" << std::endl;
        rank_cnt++;
    }
    sqlite3_finalize(stmt_check3);
    sqlite3_close(db3);
}

void Brand_Each_Sales_Count::Come_jenesiss_rank(std::string select_month)
{
    int sum = 0;
    sum = BASC.Come_jenesiss_sell(select_month);
    int result = sqlite3_open("car", &db3);
    const char *come_jenesiss;
    if (select_month == "5월")
    {
        come_jenesiss = "SELECT Model, May FROM cars WHERE Brand = '제네시스' ORDER BY May DESC";
    }
    else if (select_month == "6월")
    {
        come_jenesiss = "SELECT Model, June FROM cars WHERE Brand = '제네시스' ORDER BY June DESC";
    }
    else if (select_month == "7월")
    {
        come_jenesiss = "SELECT Model, July FROM cars WHERE Brand = '제네시스' ORDER BY July DESC";
    }

    result = sqlite3_prepare_v2(db3, come_jenesiss, -1, &stmt_check3, nullptr);

    if (result != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(db3) << std::endl;
        sqlite3_close(db3);
    }

    int rank_cnt = 1;
    int sum_month = 0;
    double bac;
    std::cout << "┌─────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                                             │" << std::endl;
    std::cout << "│        제네시스 " + select_month + " 자동차 판매 실적        │" << std::endl;
    std::cout << "│                                             │" << std::endl;
    std::cout << "└─────────────────────────────────────────────┘" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "순위     모델                  판매량(점유율)" << std::endl;
    while (sqlite3_step(stmt_check3) == SQLITE_ROW)
    {
        const char *model = reinterpret_cast<const char *>(sqlite3_column_text(stmt_check3, 0));
        const char *month = reinterpret_cast<const char *>(sqlite3_column_text(stmt_check3, 1));

        bac = std::stoi(month);
        double nanu = (100 * bac / sum);
        std::cout << std::left << rank_cnt;
        std::cout << "\t" << std::setw(30) << model;
        std::cout << "\t" << std::right << month << "(" << std::fixed << std::setprecision(3) << nanu << "%)" << std::endl;
        rank_cnt++;
    }
    sqlite3_finalize(stmt_check3);
    sqlite3_close(db3);
}

void Brand_Each_Sales_Count::Come_chevrolet_rank(std::string select_month)
{
    int sum = 0;
    sum = BASC.Come_chevrolet_sell(select_month);
    int result = sqlite3_open("car", &db3);
    const char *come_chevrolet;
    if (select_month == "5월")
    {
        come_chevrolet = "SELECT Model, May FROM cars WHERE Brand = '쉐보레' ORDER BY May DESC";
    }
    else if (select_month == "6월")
    {
        come_chevrolet = "SELECT Model, June FROM cars WHERE Brand = '쉐보레' ORDER BY June DESC";
    }
    else if (select_month == "7월")
    {
        come_chevrolet = "SELECT Model, July FROM cars WHERE Brand = '쉐보레' ORDER BY July DESC";
    }

    result = sqlite3_prepare_v2(db3, come_chevrolet, -1, &stmt_check3, nullptr);

    if (result != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(db3) << std::endl;
        sqlite3_close(db3);
    }

    int rank_cnt = 1;
    int sum_month = 0;
    double bac;
    std::cout << "┌─────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                                             │" << std::endl;
    std::cout << "│          쉐보레 " + select_month + " 자동차 판매 실적        │" << std::endl;
    std::cout << "│                                             │" << std::endl;
    std::cout << "└─────────────────────────────────────────────┘" << std::endl;
    std::cout << "" << std::endl;

    std::cout << "순위     모델                  판매량(점유율)" << std::endl;
    while (sqlite3_step(stmt_check3) == SQLITE_ROW)
    {
        const char *model = reinterpret_cast<const char *>(sqlite3_column_text(stmt_check3, 0));
        const char *month = reinterpret_cast<const char *>(sqlite3_column_text(stmt_check3, 1));

        bac = std::stoi(month);
        double nanu = (100 * bac / sum);
        std::cout << std::left << rank_cnt;
        std::cout << "\t" << std::setw(35) << model;
        std::cout << "\t" << std::right << month << "(" << std::fixed << std::setprecision(3) << nanu << "%)" << std::endl;
        rank_cnt++;
    }
    sqlite3_finalize(stmt_check3);
    sqlite3_close(db3);
}

void Brand_Each_Sales_Count::Come_kgmobility_rank(std::string select_month)
{
    int sum = 0;
    sum = BASC.Come_kgmobility_sell(select_month);
    int result = sqlite3_open("car", &db3);
    const char *come_kgmobility;
    if (select_month == "5월")
    {
        come_kgmobility = "SELECT Model, May FROM cars WHERE Brand = 'KGMobility' ORDER BY May DESC";
    }
    else if (select_month == "6월")
    {
        come_kgmobility = "SELECT Model, June FROM cars WHERE Brand = 'KGMobility' ORDER BY June DESC";
    }
    else if (select_month == "7월")
    {
        come_kgmobility = "SELECT Model, July FROM cars WHERE Brand = 'KGMobility' ORDER BY July DESC";
    }

    result = sqlite3_prepare_v2(db3, come_kgmobility, -1, &stmt_check3, nullptr);

    if (result != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(db3) << std::endl;
        sqlite3_close(db3);
    }

    int rank_cnt = 1;
    int sum_month = 0;
    double bac;
    std::cout << "┌─────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                                             │" << std::endl;
    std::cout << "│        KGMobility " + select_month + " 자동차 판매 실적      │" << std::endl;
    std::cout << "│                                             │" << std::endl;
    std::cout << "└─────────────────────────────────────────────┘" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "순위     모델                  판매량(점유율)" << std::endl;
    while (sqlite3_step(stmt_check3) == SQLITE_ROW)
    {
        const char *model = reinterpret_cast<const char *>(sqlite3_column_text(stmt_check3, 0));
        const char *month = reinterpret_cast<const char *>(sqlite3_column_text(stmt_check3, 1));

        bac = std::stoi(month);
        double nanu = (100 * bac / sum);
        std::cout << std::left << rank_cnt;
        std::cout << "\t" << std::setw(35) << model;
        std::cout << "\t" << std::right << month << "(" << std::fixed << std::setprecision(3) << nanu << "%)" << std::endl;
        rank_cnt++;
    }
    sqlite3_finalize(stmt_check3);
    sqlite3_close(db3);
}

void Brand_Each_Sales_Count::Come_renault_rank(std::string select_month)
{
    int sum = 0;
    sum = BASC.Come_renault_sell(select_month);
    int result = sqlite3_open("car", &db3);
    const char *come_renault;
    if (select_month == "5월")
    {
        come_renault = "SELECT Model, May FROM cars WHERE Brand = '르노' ORDER BY May DESC";
    }
    else if (select_month == "6월")
    {
        come_renault = "SELECT Model, June FROM cars WHERE Brand = '르노' ORDER BY June DESC";
    }
    else if (select_month == "7월")
    {
        come_renault = "SELECT Model, July FROM cars WHERE Brand = '르노' ORDER BY July DESC";
    }

    result = sqlite3_prepare_v2(db3, come_renault, -1, &stmt_check3, nullptr);

    if (result != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(db3) << std::endl;
        sqlite3_close(db3);
    }

    int rank_cnt = 1;
    int sum_month = 0;
    double bac;
    std::cout << "┌─────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                                             │" << std::endl;
    std::cout << "│          르노 " + select_month + " 자동차 판매 실적          │" << std::endl;
    std::cout << "│                                             │" << std::endl;
    std::cout << "└─────────────────────────────────────────────┘" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "순위     모델          판매량(점유율)" << std::endl;
    while (sqlite3_step(stmt_check3) == SQLITE_ROW)
    {
        const char *model = reinterpret_cast<const char *>(sqlite3_column_text(stmt_check3, 0));
        const char *month = reinterpret_cast<const char *>(sqlite3_column_text(stmt_check3, 1));

        bac = std::stoi(month);
        double nanu = (100 * bac / sum);
        std::cout << std::left << rank_cnt;
        std::cout << "\t" << std::setw(15) << model;
        std::cout << "\t" << std::right << month << "(" << std::fixed << std::setprecision(3) << nanu << "%)" << std::endl;
        rank_cnt++;
    }
    sqlite3_finalize(stmt_check3);
    sqlite3_close(db3);
}
