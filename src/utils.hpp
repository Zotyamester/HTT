#ifndef UTILS_H
#define UTILS_H

namespace utils {

    /**
     * Két azonos típusú objektumot megcserélni képes függvény.
     * @tparam T - típus
     * @param a - referencia az egyik objektumra
     * @param b - referencia a másik objektumra
     */
    template <typename T>
    void swap(T& a, T& b) {
        T tmp = a;
        a = b;
        b = tmp;
    }

    template <typename T>
    T min(T a, T b) {
        return a < b ? a : b;
    }

    template <typename T>
    T max(T a, T b) {
        return a > b ? a : b;
    }

}

#endif // UTILS_H
