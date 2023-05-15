#include <iostream>

#ifndef CPORTA

#include <fstream>
#include "Provider.h"

#else

#include <sstream>
#include <clocale>
#include "utils/String.h"
#include "plan/PlanFactory.h"
#include "plan/Basic.h"
#include "plan/ZoomerNet.h"
#include "plan/AllInMax.h"
#include "gtest_lite.h"
#include "Client.h"

#endif

enum Error {
    BAD_USAGE, RUNTIME_ERROR, INVALID_DATA
};

/**
 * Az interaktív főprogram belépési pontja.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char* argv[]) {

#ifndef CPORTA

    if (argc != 4) {
        std::cout << "Usage: telco [CLIENTS FILE] [DATA USAGES FILE] [REPORT FILE]" << std::endl;
        return Error::BAD_USAGE;
    }

    try {
        // RAII-menedzselt, nem kell explicit bezárni
        std::fstream client_file(argv[1], std::ios_base::in);

        if (!client_file.is_open())
            throw std::runtime_error("Can't open file.");

        // RAII-menedzselt, nem kell explicit bezárni
        std::fstream usage_file(argv[2], std::ios_base::in);

        if (!usage_file.is_open())
            throw std::runtime_error("Can't open file.");

        // RAII-menedzselt, nem kell explicit bezárni
        std::fstream report_file(argv[3], std::ios_base::out);

        if (!report_file.is_open())
            throw std::runtime_error("Can't open file.");

        Provider provider(client_file, usage_file);
        provider.createReport(report_file);
    } catch (std::runtime_error& ex) {
        std::cerr << ex.what() << std::endl;
        return Error::RUNTIME_ERROR;
    } catch (std::logic_error& ex) {
        std::cerr << ex.what() << std::endl;
        return Error::INVALID_DATA;
    }

#else

    using std::cin;
    using std::cout;
    using std::cerr;
    using std::endl;

    TEST(String, strings) {} ENDM

    TEST(Vector, vectors) {} ENDM

    TEST(Plan, planCreation)
        {
            const utils::String names[] = {"Basic", "ZoomerNet", "AllInMax"};
            const utils::String type_names[] = {typeid(Basic).name(), typeid(ZoomerNet).name(),
                                                typeid(AllInMax).name()};

            for (size_t i = 0; i < sizeof(names) / sizeof(names[0]); i++) {
                Plan* plan = nullptr;
                EXPECT_NO_THROW(plan = PlanFactory::createPlan(names[i]));
                EXPECT_STREQ(typeid(*plan).name(), type_names[i]);
                delete plan;
            }

            Plan* plan = nullptr;
            EXPECT_THROW(plan = PlanFactory::createPlan("random string"), std::invalid_argument);
            delete plan;
        }
    ENDM

    TEST(Plan, planPrices)
        {
            Basic basic;
            ZoomerNet zoomer_net;
            AllInMax all_in_max;
            const Plan* plans[] = {&basic, &zoomer_net, &all_in_max};
            const int base_costs[] = {1990, 5990, 9990};
            const int fees_for_1_hour[] = {60 * 30, 60 * 15, 0};
            const int fees_for_69_SMS[] = {69 * 45, 5 * 45 + 10 * 25 + 54 * 5, 0};
            const int fees_for_1_GB[] = {500 * 5, 0, 0};

            for (size_t i = 0; i < sizeof(plans) / sizeof(plans[0]); i++) {
                EXPECT_EQ(base_costs[i], plans[i]->baseCost());
                EXPECT_EQ(fees_for_1_hour[i], plans[i]->minuteCost(60));
                EXPECT_EQ(fees_for_69_SMS[i], plans[i]->smsCost(69));
                EXPECT_EQ(fees_for_1_GB[i], plans[i]->dataCost(1000));
            }
        }
    ENDM

    TEST(DataUsage, dataUsageCreation)
        {
            const utils::String phone = "+36302401782";
            const utils::String date = "2023.01.";
            const int minutes = 32;
            const int sms_count = 3;
            const double data = 4320.1;

            DataUsage usage(phone, date, minutes, sms_count, data);
            EXPECT_EQ(phone, usage.getPhone());
            EXPECT_EQ(date, usage.getDate());
            EXPECT_EQ(minutes, usage.getMinutes());
            EXPECT_EQ(sms_count, usage.getSmsCount());
            EXPECT_EQ(data, usage.getData());
        }
    ENDM

    TEST(Client, clientCreation)
        {
            const utils::String phone = "+36302401782";

            Client client("Tmites Aladár", "1117 Budapest, Magyar Tudósok Körútja 2, I épület IE315", phone,
                          "AllInMax", utils::Vector<DataUsage>(0));
            EXPECT_EQ(phone, client.getPhone());
        }
    ENDM

    TEST(Client, addDataUsage)
        {
            Client client("Tmites Aladár", "1117 Budapest, Magyar Tudósok Körútja 2, I épület IE315", "+36302401782",
                          "AllInMax", utils::Vector<DataUsage>(0));

            DataUsage empty_usage;
            EXPECT_THROW(client.addDataUsage(empty_usage), std::invalid_argument);

            DataUsage related_usage("+36302401782", "2023.01.", 32, 3, 4320.1);
            EXPECT_NO_THROW(client.addDataUsage(related_usage));
        }
    ENDM
#endif

    return 0;
}
