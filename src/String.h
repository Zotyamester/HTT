#ifndef STRING_H
#define STRING_H

#include <cstddef>
#include <iostream>

namespace utils {

    /**
     * Egy dinamikusan növelhető sztringet (másnéven karakterláncot) megvalósító osztály.
     */
    class String {
    private:
        size_t len;
        char *data;
    public:
        String(const char *cs = "", size_t max_len = SIZE_MAX);

        String(char c);

        String(String const &rhs);

        ~String() { delete[] data; }

        String &operator=(String s);

        char &operator[](size_t idx);

        char const &operator[](size_t idx) const;

        String &operator+=(String const &s);

        String &operator+=(char c);

        String operator+(String const &s) const;

        String operator+(char c) const;

        bool operator==(const char *cs) const;

        bool operator!=(const char *cs) const;

        bool operator<(const char *cs) const;

        bool operator<=(const char *cs) const;

        bool operator>(const char *cs) const;

        bool operator>=(const char *cs) const;

        size_t size() const;

        const char *c_str() const;

        operator const char *() const;
    };

    String operator+(char c, String const &s);

    std::ostream &operator<<(std::ostream &os, String const &s);

    std::istream &operator>>(std::istream &is, String &s);

    std::istream &getline(std::istream &is, String &s);

}

#endif // !STRING_H
