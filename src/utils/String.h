#ifndef STRING_H
#define STRING_H

#include <cstddef>
#include <iostream>
#include "Vector.hpp"

namespace utils {

    /**
     * Egy dinamikusan növelhető sztringet megvalósító osztály.
     */
    class String {
    private:
        // a hossz (a null-karaktertől
        size_t len;
        // a tényleges adattároló
        char* data;
    public:
        /**
         * Alapértelmezett és C-sztring konverziós konstruktor.
         * @param cs C-sztring
         * @param max_len a maximálisan felhasználandó hossza @p cs -nek
         */
        String(const char* cs = "", size_t max_len = SIZE_MAX);

        /**
         * Karakter konverziós konstruktor.
         * @param c karakter
         */
        String(char c);

        /**
         * Másoló konstruktor.
         * @param rhs a másolandó példány
         */
        String(const String& rhs);

        /**
         * Destruktor, melynek felelőssége, hogy felszabadítsa a dinamikusan létrehozott @p data -t.
         */
        ~String();

        /**
         * Az érékadás operátor megvalósítása copy-and-swap módszerrel.
         * @param vector az érték szerint átvett sztring, amellyel egyenlővé tenni való a példány
         * @return referencia a példányra
         */
        String& operator=(String s);

        /**
         * Indexelő operátor, mely visszatér a sztring @p idx -edik karakterére mutató referenciával.
         *
         * Nem hajt végre futási idejű ellenőrzést a túlindexelés elkerülésére!
         * @param idx index
         * @return referencia a karakterre
         */
        char& operator[](size_t idx);

        /**
         * Indexelő operátor, mely visszatér a konstans sztring @p idx -edik karakterére mutató
         * konstans referenciával.
         *
         * Nem hajt végre futási idejű ellenőrzést a túlindexelés elkerülésére!
         * @param idx index
         * @return referencia a karakterre
         */
        const char& operator[](size_t idx) const;

        /**
         * Láncolható konkatenáló operátor.
         * @param s a példányhoz hozzáfűzendő sztring referenciája
         * @return a példány referenciája
         */
        String& operator+=(const String& s);

        /**
         * Láncolható konkatenáló operátor.
         * @param s a példányhoz hozzáfűzendő karakter
         * @return a példány referenciája
         */
        String& operator+=(char c);

        /**
         * Új sztringet készítő konkatenáló operátor.
         * @param s a példányhoz hozzáfűzendő sztring referenciája
         * @return új sztring
         */
        String operator+(const String& s) const;

        /**
         * Új sztringet készítő konkatenáló operátor.
         * @param s a példányhoz hozzáfűzendő karakter
         * @return új sztring
         */
        String operator+(char c) const;

        bool operator==(const char* cs) const;

        bool operator!=(const char* cs) const;

        bool operator<(const char* cs) const;

        bool operator<=(const char* cs) const;

        bool operator>(const char* cs) const;

        bool operator>=(const char* cs) const;

        /**
         * Visszatér a szöveg hosszával.
         * @return a szöveg hossza
         */
        size_t size() const;

        /**
         * Visszatér a sztring belső reprezentációjával, mint C-sztringgel.
         * @return C-sztring
         */
        const char* c_str() const;

        /**
         * C-sztringgé kasztoló operátor
         * @return C-sztring
         */
        operator const char*() const;
    };

    String operator+(char c, String const& s);

    std::ostream& operator<<(std::ostream& os, String const& s);

    std::istream& operator>>(std::istream& is, String& s);

    /**
     * Beolvas egy egész sornyi sztringet
     * @param is bemeneti adatfolyam
     * @param s a cél sztring
     * @return @p is
     */
    std::istream& getline(std::istream& is, String& s);
}

#endif // STRING_H
