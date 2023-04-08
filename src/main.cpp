#include <iostream>

#include "String.h"
#include "gtest_lite.h"

using utils::String;
using std::cin;
using std::cout;
using std::endl;

int main() {

//    TEST(String, emptyStr) {
//        String s;
//        EXPECT_EQ((size_t)0, s.size()) << "Incorrect size." << endl;
//        EXPECT_STREQ("", s.c_str()) << "Incorrect size." << endl;
//    } ENDM
//
//    TEST(String, fromStr) {
//        const char* cs = "Test";
//
//        String s = cs;
//        EXPECT_EQ(strlen(cs), s.size()) << "Incorrect size." << endl;
//        EXPECT_STREQ(cs, s.c_str()) << "Wrong answer." << endl;
//    } ENDM
//
//    TEST(String, fromChr) {
//        const char* c_as_str = "A";
//        char c = c_as_str[0];
//
//        String s = c;
//        EXPECT_EQ(c, s[0]) << "First character mismatch." << endl;
//        EXPECT_EQ(strlen(c_as_str), s.size()) << "Incorrect size." << endl;
//        EXPECT_STREQ(c_as_str, s.c_str()) << "Wrong answer." << endl;
//    } ENDM
//
//    TEST(String, copyStr) {
//        const char* start = "This is a string.";
//
//        String s1 = start;
//        String s2 = s1;
//        EXPECT_EQ(s1.size(), s2.size()) << "Incorrect size." << endl;
//        EXPECT_STREQ(s1.c_str(), s2.c_str()) << "Wrong answer." << endl;
//    } ENDM
//
//    TEST(String, assignStr) {
//        const char* start1 = "This is a string.";
//        const char* start2 = "This is another string.";
//
//        String s1 = start1;
//        String s2 = start2;
//        s2 = s1;
//        EXPECT_EQ(s1.size(), s2.size()) << "Incorrect size." << endl;
//        EXPECT_STREQ(s1.c_str(), s2.c_str()) << "Wrong answer." << endl;
//    } ENDM
//
//    TEST(String, index) {
//        const char* cs = "ABCDEF";
//        char c = 'X';
//        const char* c_cs = "XBCDEF";
//
//        String s1 = cs;
//        s1[0] = c;
//        String const& ref_s1 = s1;
//        EXPECT_EQ(c, ref_s1[0]) << "Incorrect size." << endl;
//        EXPECT_STREQ(c_cs, ref_s1.c_str()) << "Wrong answer." << endl;
//
//        EXPECT_NO_THROW(s1[0]);
//        EXPECT_NO_THROW(s1[3]);
//        EXPECT_NO_THROW(s1[5]);
//        EXPECT_THROW(s1[-1], const char *);
//        EXPECT_THROW(s1[6], const char *);
//        EXPECT_THROW(s1[7], const char *);
//    } ENDM

    return 0;
}
