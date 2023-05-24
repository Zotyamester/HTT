#include "Provider.h"

#include "memtrace.h"

Provider::Provider(std::istream& client_is, std::istream& usage_is) {
    while (!client_is.eof()) {
        Client client;
        client.read(client_is);
        clients.push(client);
    }

    while (!usage_is.eof()) {
        DataUsage usage;
        usage.read(usage_is);

        for (Client& client : clients) {
            if (client.getPhone() == usage.getPhone()) {
                client.addDataUsage(usage);
                break;
            }
        }
    }
}

void Provider::createReport(std::ostream& os) {
    auto iter = clients.begin();
    if (iter == clients.end())
        return;
    iter->writeBilling(os);
    while (++iter != clients.end()) {
        os << std::endl;
        iter->writeBilling(os);
    }
}

void Provider::addClient(const Client& client) {
    clients.push(client);
}
