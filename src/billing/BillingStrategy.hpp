#ifndef BILLINGSTRATEGY_HPP
#define BILLINGSTRATEGY_HPP

template <typename T>
class BillingStrategy {
public:
    virtual int cost(T usage) const = 0;
};

#endif // BILLINGSTRATEGY_HPP