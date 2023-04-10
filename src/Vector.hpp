#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <stdexcept>
#include "utils.hpp"

namespace utils {

    /**
     * Általános célú, vektort (másnéven dinamikus tömböt) megvalósító sablon.
     * @tparam T
     */
    template<typename T>
    class Vector {
    private:
        /**
         * Alapértelmezett nyújtási szorzó.
         */
        static const size_t DEFAULT_EXTENSION_MULTIPLIER = 2;

    protected:
        size_t capacity, n;
        T *data;
    public:
        explicit Vector(size_t n = 0) : capacity(n), n(n), data(new T[capacity]) {}

        Vector(Vector const &rhs) : capacity(rhs.capacity), n(rhs.n), data(new T[capacity]) {
            for (size_t i = 0; i < n; i++)
                data[i] = rhs.data[i];
        }

        Vector &operator=(Vector vector) {
            capacity = vector.capacity;
            n = vector.n;
            utils::swap(data, vector.data);

            return *this;
        }

        ~Vector() {
            delete[] data;
        }

        size_t size() const { return n; }


        void extend(size_t new_n) {
            if (new_n > capacity) {
                size_t new_capacity = new_n * DEFAULT_EXTENSION_MULTIPLIER;
                T *new_data = new T[new_capacity];
                for (size_t i = 0; i < n; i++)
                    new_data[i] = data[i];
                capacity = new_capacity;
                n = new_n;
                delete[] data;
                data = new_data;
            }
        }

        void push(T item) {
            extend(n + 1);
            data[n++] = item;
        }

        void pop() {
            for (size_t i = 1; i < n; i++)
                data[i - 1] = data[i];
            n--;
        }

        T &operator[](size_t idx) {
            return data[idx];
        }

        T const &operator[](size_t idx) const {
            return data[idx];
        }

        T &at(size_t idx) {
            if (idx >= n)
                throw std::runtime_error("Out of range.");
            return data[idx];
        }

        T const &at(size_t idx) const {
            if (idx >= n)
                throw std::runtime_error("Out of range.");
            return data[idx];
        }

        class iterator {
        private:
            T *ptr;
        public:
            iterator(T *ptr = nullptr) : ptr(ptr) {}

            T &operator*() {
                return *ptr;
            }

            T *operator->() {
                return ptr;
            }

            iterator &operator++() {
                ++ptr;
                return *this;
            }

            iterator operator++(int) {
                iterator original = *this;
                ++ptr;
                return original;
            }

            bool operator==(iterator rhs) {
                return ptr == rhs.ptr;
            }

            bool operator!=(iterator rhs) {
                return ptr != rhs.ptr;
            }
        };

        iterator begin() {
            return iterator(data);
        }

        iterator end() {
            return iterator(data + n);
        }
    };

}

#endif // VECTOR_H
