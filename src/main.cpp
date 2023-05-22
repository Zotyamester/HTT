#include <iostream>

//#define CPORTA

#ifndef CPORTA
#include <fstream>
#include "Provider.h"
#else
#include "test.h"
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

    test::run_tests();

#endif

    return 0;
}
