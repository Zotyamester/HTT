#include "Provider.h"

Provider::Provider(std::istream &client_is, std::istream &usage_is) : clients(), data_usages() {
    size_t client_count;
    (client_is >> client_count).ignore(1);
    clients.extend(client_count);
    for (size_t i = 0; i < client_count; i++)
        clients[i].read(client_is);

    size_t usage_count;
    (client_is >> usage_count).ignore(1);
    data_usages.extend(usage_count);
    for (size_t i = 0; i < usage_count; i++)
        data_usages[i].read(usage_is);
}

void Provider::listBills(std::ostream &os) {
    for (Client &client: clients) {
        int total = 0;

        for (DataUsage &usage: data_usages)
            if (usage.getPhone() == client.getPhone())
                total += client.getDataPlan().totalCost(usage);

        client.write(os);
        os << "Total payment required: " << total << " HUF" << std::endl;
    }
}
