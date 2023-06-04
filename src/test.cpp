#include "test.h"

#include <sstream>
#include <clocale>
#include "utils/String.h"
#include "plan/PlanFactory.h"
#include "plan/Basic.h"
#include "plan/ZoomerNet.h"
#include "plan/AllInMax.h"
#include "Client.h"
#include "Provider.h"

#include "gtest_lite.h"
#include "memtrace.h"

void test::run_tests() {
    using std::cin;
    using std::cout;
    using std::cerr;
    using std::endl;

    TEST(String, creation)
        {
            const utils::String empty;
            EXPECT_EQ((size_t) 0, empty.size());
            EXPECT_STREQ("", empty);

            const char* c_as_cs = "a";
            const utils::String fromChr = c_as_cs[0];
            EXPECT_EQ((size_t) 1, fromChr.size());
            EXPECT_EQ(c_as_cs[0], fromChr[0]);
            EXPECT_STREQ(c_as_cs, fromChr);

            char cs[] = "hello";
            const utils::String fromCs = cs;
            EXPECT_EQ((size_t) 5, fromCs.size());
            EXPECT_STREQ(cs, fromCs);
            cs[0] = 'b';
            EXPECT_STRNE(cs, fromCs); // nem módosulhat cs módosításától fromCs

            EXPECT_STREQ((const char*) fromCs, fromCs.c_str());
        }
    ENDM

    TEST(String, copyAndAssign)
        {
            utils::String s1 = "something";
            utils::String s2 = s1;
            EXPECT_STREQ(s1, s2);
            s1[0] = 'x';
            EXPECT_STRNE(s1, s2); // nem módosulhat s1 módosításától s2

            utils::String s3;
            s3 = s2;
            EXPECT_STREQ(s2, s3);
            s2[0] = 'y';
            EXPECT_STRNE(s2, s3); // nem módosulhat s2 módosításától s3
        }
    ENDM

    TEST(String, concatenation)
        {
            utils::String s1 = "C++";
            utils::String s2 = " is good";
            utils::String s1_s2 = s1 + s2;
            EXPECT_STREQ("C++ is good", s1_s2);

            char c = 'C';
            utils::String c_s2 = c + s2;
            EXPECT_STREQ("C is good", c_s2);

            utils::String s = "hello";
            s += ' ';
            s += "world";
            EXPECT_STREQ("hello world", s);
        }
    ENDM

    TEST(String, comparison)
        {
            utils::String s1 = "hehe";
            utils::String s2 = "haha";

            // tényleg komplementer logikájú-e az == és a !=
            EXPECT_TRUE(s1 == "hehe");
            EXPECT_FALSE(s1 != "hehe");
            EXPECT_TRUE(s1 <= "hehe"); // <= is igaz-e, ha == igaz
            EXPECT_TRUE(s1 >= "hehe"); // >= is igaz-e, ha == igaz

            EXPECT_TRUE(s1 != "haha");
            EXPECT_FALSE(s1 == "haha");

            EXPECT_TRUE(s1 == s1);
            EXPECT_FALSE(s1 != s1);

            EXPECT_TRUE(s1 != s2);
            EXPECT_FALSE(s1 == s2);

            utils::String apple = "apple";
            utils::String banana = "banana";
            EXPECT_TRUE(apple < banana);
            EXPECT_TRUE(apple <= banana); // <= is igaz-e, ha < igaz
            EXPECT_TRUE(banana > apple);
            EXPECT_TRUE(banana >= apple); // >= is igaz-e, ha > igaz
        }
    ENDM

    TEST(Vector, creation)
        {
            utils::Vector<char> empty;
            EXPECT_EQ((size_t) 0, empty.size());

            utils::Vector<double> fromSize(7);
            EXPECT_EQ((size_t) 7, fromSize.size());

            utils::Vector<int> fromList = {1, 2, 3};
            EXPECT_EQ((size_t) 3, fromList.size());
            EXPECT_EQ(1, fromList[0]);
            EXPECT_EQ(2, fromList[1]);
            EXPECT_EQ(3, fromList[2]);
        };
    ENDM

    TEST(Vector, copyAndAssign)
        {
            utils::Vector<int> v1 = {1, 2, 3};
            utils::Vector<int> v2 = v1;
            utils::Vector<int> v3;
            v3 = v1;
            EXPECT_EQ(v1.size(), v2.size());
            EXPECT_EQ(v1.size(), v3.size());
            for (size_t i = 0; i < v1.size(); i++) {
                EXPECT_EQ(v1[i], v2[i]);
                EXPECT_EQ(v1[i], v3[i]);
            }

            v1[0] = 69;
            EXPECT_NE(69, v2[0]);
            EXPECT_NE(69, v3[0]);
        }
    ENDM

    TEST(Vector, indexing)
        {
            utils::Vector<double> v = {2.72, 1.41, 3.14};
            EXPECT_EQ(2.72, v[0]);
            EXPECT_NO_THROW(v.at(0));
            EXPECT_EQ(2.72, v.at(0));
            EXPECT_EQ(1.41, v[1]);
            EXPECT_NO_THROW(v.at(1));
            EXPECT_EQ(1.41, v.at(1));
            EXPECT_EQ(3.14, v[2]);
            EXPECT_NO_THROW(v.at(2));
            EXPECT_EQ(3.14, v.at(2));

            EXPECT_NO_THROW(v[3]); // túlindexelésnél a subscript operátor nem dob kivételt
            EXPECT_THROW(v.at(3), std::out_of_range &); // az at függvény viszont igen
        }
    ENDM

    TEST(Vector, pushPopAndExtend)
        {
            utils::Vector<char> v;
            v.push('a');
            v.push('b');
            v.push('x');
            v.pop();
            v.push('c');

            EXPECT_EQ((size_t) 3, v.size());
            EXPECT_EQ('c', v[v.size() - 1]);
            v.pop();
            EXPECT_EQ('b', v[v.size() - 1]);
            v.pop();
            EXPECT_EQ('a', v[v.size() - 1]);
            v.pop();
            EXPECT_EQ((size_t) 0, v.size());

            v.extend(10);
            EXPECT_EQ((size_t) 0, v.size()); // nem növelheti a "benne lévő elemek számát", csak a kapacitást
        }
    ENDM

    TEST(Vector, iterators)
        {
            utils::Vector<int> v = {1, 2, 3, 4, 5};

            utils::Vector<int>& ref_v = v;
            for (auto& value: ref_v) // iterátorok működésének tesztelésére range-based for loop
                EXPECT_LE(0, value); // hogy használjuk valamire az értékét (ne legyen warning)

            const utils::Vector<int>& cref_v = v;
            for (const auto& value: cref_v) // konstans iterátorok tesztelése
                EXPECT_LE(0, value);
        }
    ENDM

    TEST(Plan, creation)
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
            EXPECT_THROW(plan = PlanFactory::createPlan("random string"), std::invalid_argument &);
            delete plan;
        }
    ENDM

    TEST(Plan, prices)
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

    TEST(DataUsage, creation)
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

    TEST(Client, creation)
        {
            const utils::String phone = "+36302401782";

            Client client("Tmites Aladár", "1117 Budapest, Magyar Tudósok Körútja 2, I épület IE315", phone, "AllInMax",
                          utils::Vector<DataUsage>(0));
            EXPECT_EQ(phone, client.getPhone());
        }
    ENDM

    TEST(Client, addDataUsage)
        {
            Client client("Tmites Aladár", "1117 Budapest, Magyar Tudósok Körútja 2, I épület IE315", "+36302401782",
                          "AllInMax", utils::Vector<DataUsage>(0));

            DataUsage empty_usage;
            EXPECT_THROW(client.addDataUsage(empty_usage), std::invalid_argument &);

            DataUsage related_usage("+36302401782", "2023.01.", 32, 3, 4320.1);
            EXPECT_NO_THROW(client.addDataUsage(related_usage));
        }
    ENDM

    TEST(Provider, constructionFromStream)
        {
            std::stringstream clients("Tmites Aladár\n"
                                      "1117 Budapest, Magyar Tudósok Körútja 2, I épület IE315\n"
                                      "+36302401782\n"
                                      "AllInMax\n"
                                      "Autos Béla\n"
                                      "1117 Budapest, Magyar Tudósok Körútja 2, Q épület QB207\n"
                                      "+36704206969\n"
                                      "ZoomerNet\n");
            std::stringstream usages("+36302401782\n"
                                     "2023.01.\n"
                                     "32 3 4320.1\n"
                                     "+36704206969\n"
                                     "2022.12.\n"
                                     "89 60 128.37\n"
                                     "+36302401782\n"
                                     "2023.02.\n"
                                     "50 6 1500.8");
            Provider provider(clients, usages);

            std::stringstream report;
            provider.createReport(report);

            const std::string expected_report("Tmites Aladár\n"
                                              "1117 Budapest, Magyar Tudósok Körútja 2, I épület IE315\n"
                                              "+36302401782\n"
                                              " - 2023.01.\n"
                                              "   - fee after minutes: 0 Ft\n"
                                              "   - fee after SMS: 0 Ft\n"
                                              "   - fee after mobile data: 0 Ft\n"
                                              "   - total: 9990 Ft\n"
                                              " - 2023.02.\n"
                                              "   - fee after minutes: 0 Ft\n"
                                              "   - fee after SMS: 0 Ft\n"
                                              "   - fee after mobile data: 0 Ft\n"
                                              "   - total: 9990 Ft\n"
                                              "\n"
                                              "utos Béla\n"
                                              "1117 Budapest, Magyar Tudósok Körútja 2, Q épület QB207\n"
                                              "+36704206969\n"
                                              " - 2022.12.\n"
                                              "   - fee after minutes: 1335 Ft\n"
                                              "   - fee after SMS: 700 Ft\n"
                                              "   - fee after mobile data: 0 Ft\n"
                                              "   - total: 8025 Ft\n");
            EXPECT_EQ(expected_report, report.str());
        }
    ENDM

}
