#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <stdexcept>
#include "utils.hpp"

#include "../memtrace.h"

namespace utils {

    /**
     * Általános célú, vektort (másnéven dinamikus tömböt) megvalósító sablon.
     * @tparam T a tárolandó elemek típusa
     */
    template<typename T>
    class Vector {
    private:
        /**
         * Az alapértelmezett nyújtási szorzó.
         */
        static const size_t DEFAULT_EXTENSION_MULTIPLIER = 2;

    protected:
        /**
         * a fizikai tároló kapacitása
         */
        size_t capacity;
        /**
         * a fizikai tároló tényleges mérete
         */
        size_t n;
        /**
         * a fizikai tároló
         */
        T* data;
    public:
        /**
         * Az explicit egy paraméteres és egyben alapértelmezett konstruktor egy @p n méretű és egyben kapacitású
         * vektort inicializál.
         * @param n méret
         */
        explicit Vector(size_t n = 0) : capacity(n), n(n), data(new T[capacity]) {}

        /**
         * Az inicializáló listás konstruktor, mely az adattagok inicializálását delegálja
         * az egy paraméteres, méret szerint inicializáló konstruktornak, majd átmásolja
         * az adatokat az inicializáló listáról a fizikai tárolóba.
         * @param init_list inicializáló lista
         */
        Vector(std::initializer_list<T> init_list) : Vector(init_list.size()) {
            std::copy(init_list.begin(), init_list.end(), data);
        }

        /**
         * A másoló konstruktor megvalósítása.
         * @param rhs a másolandó példányra mutató konstans referencia
         */
        Vector(Vector const& rhs) : capacity(rhs.capacity), n(rhs.n), data(new T[capacity]) {
            for (size_t i = 0; i < n; i++)
                data[i] = rhs.data[i];
        }

        /**
         * Az érékadás operátor megvalósítása copy-and-swap módszerrel.
         * @param vector az érték szerint átvett vektor, amellyel egyenlővé tenni való a példány
         * @return referencia a példányra
         */
        Vector& operator=(Vector vector) {
            capacity = vector.capacity;
            n = vector.n;
            utils::swap(data, vector.data);

            return *this;
        }

        /**
         * A destruktor megvalósítása, mely felszabadítja a fizikai tárolót,
         * és azzal együtt az érték szerint tárolt elemeket.
         */
        ~Vector() {
            delete[] data;
        }

        /**
         * Visszaadja a tároló ténylegesen kihasznált méretét.
         * @return a méret
         */
        size_t size() const { return n; }

        /**
         * Biztosítja, hogy a vektor mindenképp legyen képes @p min_size sok elem tárolására
         * (az tároló újraallkolásának mellőzésével).
         *
         * A vektor méretét nem növeli, csak a kapacitását (és azzal együtt a fizikai tárolót is), ha szükséges.
         * @param min_size az igénylendő mennyiség
         */
        void extend(size_t min_size) {
            if (min_size > capacity) {
                size_t new_capacity = min_size * DEFAULT_EXTENSION_MULTIPLIER;
                T* new_data = new T[new_capacity];
                for (size_t i = 0; i < n; i++)
                    new_data[i] = data[i];
                capacity = new_capacity;
                delete[] data;
                data = new_data;
            }
        }

        /**
         * Betesz egy elemet a vektorba.
         * @param item az elem
         */
        void push(const T& item) {
            extend(n + 1);
            data[n++] = item;
        }

        /**
         * Kiveszi az utolsó elemet a vektorból.
         *
         * Nem ellenőrzi, hogy van-e még benne elem!
         */
        void pop() {
            n--;
        }

        /**
         * Indexelő operátor, mely visszatér a tároló @p idx -edik elemére mutató referenciával.
         *
         * Nem hajt végre futási idejű ellenőrzést a túlindexelés elkerülésére!
         * @param idx index
         * @return referencia az elemre
         */
        T& operator[](size_t idx) {
            return data[idx];
        }

        /**
         * Indexelő operátor a konstans példányra, mely visszatér a tároló @p idx -edik elemére mutató
         * konstans referenciával.
         *
         * Nem hajt végre futási idejű ellenőrzést a túlindexelés elkerülésére!
         * @param idx index
         * @return konstans referencia az elemre
         */
        const T& operator[](size_t idx) const {
            return data[idx];
        }

        /**
         * Visszatér a tároló @p idx -edik elemére mutató referenciával, amennyiben az létezik.
         *
         * Az index helyességének ellenőrzése (boundary-check) biztosított!
         * Túlindexelés esetén kivételt dob!
         * @param idx index
         * @return referencia az elemre
         * @throw std::out_of_range
         */
        T& at(size_t idx) {
            if (idx >= n)
                throw std::out_of_range("Vector index is out of bounds");
            return data[idx];
        }

        /**
         * Visszatér a konstans tároló @p idx -edik elemére mutató konstans referenciával, amennyiben az létezik.
         *
         * Az index helyességének ellenőrzése (boundary-check) biztosított!
         * Túlindexelés esetén kivételt dob!
         * @param idx index
         * @return konstans referencia az elemre
         * @throw std::out_of_range
         */
        const T& at(size_t idx) const {
            if (idx >= n)
                throw std::out_of_range("Vector index is out of bounds");
            return data[idx];
        }

    private:
        /**
         * A bejáró (iterátor) sablonos megvalósítása.
         * @tparam ITEM a bejárandó elemek típusa, alapértelmezetten a vektor által tárolt elemek @p T típusa
         */
        template<typename ITEM = T>
        class inner_iterator {
        private:
            // a bejáró mutatója a tároló adott elemére
            ITEM* ptr;
        public:
            explicit inner_iterator(ITEM* ptr = nullptr) : ptr(ptr) {}

            ITEM& operator*() {
                return *ptr;
            }

            ITEM* operator->() {
                return ptr;
            }

            inner_iterator& operator++() {
                ++ptr;
                return *this;
            }

            inner_iterator operator++(int) {
                inner_iterator original = *this;
                ++ptr;
                return original;
            }

            bool operator==(inner_iterator rhs) {
                return ptr == rhs.ptr;
            }

            bool operator!=(inner_iterator rhs) {
                return ptr != rhs.ptr;
            }
        };

    public:
        /**
         * A nem konstans példány bejárója, mely a sablonos általános bejáró
         * egy specializációja @p T típusú elemekre.
         */
        using iterator = inner_iterator<T>;

        /**
         * Visszatér a tároló kezdetét jelző bejáróval.
         * @return kezdő iterátor
         */
        iterator begin() { return iterator(data); }

        /**
         * Visszatér a tároló végét jelző bejáróval.
         * @return befejező iterátor
         */
        iterator end() { return iterator(data + n); }

        /**
         * A konstans példány bejárója, mely a sablonos általános bejáró
         * egy specializációja konstans @p T típusú elemekre.
         */
        using const_iterator = inner_iterator<const T>;

        /**
         * Visszatér a konstans tároló kezdetét jelző bejáróval.
         * @return kezdő iterátor
         */
        const_iterator begin() const { return const_iterator(data); }

        /**
         * Visszatér a konstans tároló végét jelző bejáróval.
         * @return befejező iterátor
         */
        const_iterator end() const { return const_iterator(data + n); }
    };

}

#endif // VECTOR_H
