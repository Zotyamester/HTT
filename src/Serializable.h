#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <iostream>

/**
 * Szerializálható (folyamra kírható/folyamról beolvasható) típusok közös interfésze.
 */
class Serializable {
public:
    virtual ~Serializable() {}

    /**
     * Kiírja a megadott folyamra az objektumot.
     * @param os - kimeneti adatfolyam
     */
    virtual void write(std::ostream &os) const = 0;

    /**
     * Beolvassa a megadott folyamról az objektumot.
     * @param is - bemeneti adatfolyam
     */
    virtual void read(std::istream &is) = 0;
};

#endif // SERIALIZABLE_H