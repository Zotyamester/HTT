#ifndef UTILS_H
#define UTILS_H

#include "../memtrace.h"

namespace utils {

    /**
     * Két azonos típusú objektumot megcserél.
     * @tparam T típus
     * @param a referencia az egyik objektumra
     * @param b referencia a másik objektumra
     */
    template<typename T>
    void swap(T& a, T& b) {
        T tmp = a;
        a = b;
        b = tmp;
    }

    /**
     * Két azonos típusú objektum közül a visszatér a kisebbel.
     * @tparam T típus
     * @param a az egyik objektum
     * @param b a másik objektum
     */
    template<typename T>
    T min(T a, T b) {
        return a < b ? a : b;
    }

    /**
     * Két azonos típusú objektum közül a visszatér a nagyobbal.
     * @tparam T típus
     * @param a az egyik objektum
     * @param b a másik objektum
     */
    template<typename T>
    T max(T a, T b) {
        return a > b ? a : b;
    }

}

#endif // UTILS_H
