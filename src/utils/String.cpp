#include "String.h"
#include "utils.hpp"
#include <cstring>
#include <cctype>

#include "../memtrace.h"

namespace utils {

    String::String(const char* cs, size_t max_len) : len(min(max_len, strlen(cs))), data(new char[len + 1]) {
        strncpy(data, cs, len);
        data[len] = '\0';
    }

    String::String(char c) : len(1), data(new char[len + 1]) {
        data[0] = c;
        data[1] = '\0';
    }

    String::String(const String& rhs) : len(rhs.len), data(new char[len + 1]) {
        strcpy(data, rhs.data);
    }

    String& String::operator=(String s) {
        len = s.len;
        swap(data, s.data);
        return *this;
    }

    String::~String() {
        delete[] data;
    }

    size_t String::size() const {
        return len;
    }

    const char* String::c_str() const {
        return data;
    }

    String::operator const char*() const {
        return data;
    }

    char& String::operator[](size_t idx) {
        if (idx >= len)
            throw std::out_of_range("Out of bounds");
        return data[idx];
    }

    const char& String::operator[](size_t idx) const {
        if (idx >= len)
            throw std::out_of_range("Out of bounds");
        return data[idx];
    }

    String& String::operator+=(const String& s) {
        size_t new_len = len + s.len;
        char* new_data = new char[new_len + 1];

        strcpy(new_data, data);
        strcpy(new_data + len, s.data);

        len = new_len;
        delete[] data;
        data = new_data;

        return *this;
    }

    String& String::operator+=(char c) {
        size_t new_len = len + 1;
        char* new_data = new char[new_len + 1];

        strcpy(new_data, data);
        new_data[len] = c;
        new_data[len + 1] = '\0';

        len = new_len;
        delete[] data;
        data = new_data;

        return *this;
    }

    String String::operator+(const String& s) const {
        String rs = *this;
        rs += s;
        return rs;
    }

    String String::operator+(char c) const {
        String rs = *this;
        rs += c;
        return rs;
    }

    bool String::operator==(const char* cs) const {
        return strcmp(data, cs) == 0;
    }

    bool String::operator!=(const char* cs) const {
        return strcmp(data, cs) != 0;
    }

    bool String::operator<(const char* cs) const {
        return strcmp(data, cs) < 0;
    }

    bool String::operator<=(const char* cs) const {
        return strcmp(data, cs) <= 0;
    }

    bool String::operator>(const char* cs) const {
        return strcmp(data, cs) > 0;
    }

    bool String::operator>=(const char* cs) const {
        return strcmp(data, cs) >= 0;
    }

    String operator+(char c, String const& s) {
        String rs = c;
        rs += s;
        return rs;
    }

    std::ostream& operator<<(std::ostream& os, String const& s) {
        return os << s.c_str();
    }

    std::istream& operator>>(std::istream& is, String& s) {
        s = "";

        char c;
        while (is.get(c) && isspace(c));
        if (!is.eof())
            do
                s += c;
            while (is.get(c) && !isspace(c));

        return is;
    }

    std::istream& getline(std::istream& is, String& s) {
        s = "";

        char c;
        while (is.get(c) && c == '\n');
        if (!is.eof())
            do
                s += c;
            while (is.get(c) && c != '\n');

        return is;
    }

}
