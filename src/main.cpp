#include <iostream>
#include <fstream>

#include "Provider.h"

/**
 * Az interaktív főprogram belépési pontja.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
//    if (argc != 4) {
//        std::cout << "Usage: telco [CLIENTS FILE] [DATA USAGES FILE] [REPORT FILE]" << std::endl;
//        return 1;
//    }
//
//    // RAII-managed, no need to close after use
//    std::fstream client_file(argv[1], std::ios_base::in);
//
//    if (!client_file.is_open())
//        return 2;
//
//    // RAII-managed, no need to close after use
//    std::fstream usage_file(argv[2], std::ios_base::in);
//
//    if (!usage_file.is_open())
//        return 2;
//
//    // RAII-managed, no need to close after use
//    std::fstream report_file(argv[3], std::ios_base::out);
//
//    if (!report_file.is_open())
//        return 2;
//
//    Provider provider(client_file, usage_file);
//    provider.listBills(report_file);

    Client client("John Doe", "2031 Bivalybasznad", "+361234567", "MobiNet");
    client.write(std::cout);

    DataUsage usage("+361234567", 80, 69);
    std::cout << "Total: " << client.getDataPlan().totalCost(usage) << std::endl;

    return 0;
}
