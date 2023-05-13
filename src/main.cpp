#include <iostream>
#include <fstream>
#include "Provider.h"

enum Error {
    BAD_USAGE, IO_ERROR, INVALID_DATA
};

/**
 * Az interaktív főprogram belépési pontja.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "Usage: telco [CLIENTS FILE] [DATA USAGES FILE] [REPORT FILE]" << std::endl;
        return Error::BAD_USAGE;
    }

    try {
        // RAII-managed, no need to close after use
        std::fstream client_file(argv[1], std::ios_base::in);

        if (!client_file.is_open())
            throw std::runtime_error("Can't open file.");

        // RAII-managed, no need to close after use
        std::fstream usage_file(argv[2], std::ios_base::in);

        if (!usage_file.is_open())
            throw std::runtime_error("Can't open file.");

        // RAII-managed, no need to close after use
        std::fstream report_file(argv[3], std::ios_base::out);

        if (!report_file.is_open())
            throw std::runtime_error("Can't open file.");

        Provider provider(client_file, usage_file);
        provider.createReport(report_file);
    } catch (std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        return Error::INVALID_DATA;
    }

    return 0;
}
