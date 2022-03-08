#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good input"){
    CHECK(mat(9, 7, '@', '-') == "@@@@@@@@@\n"
                                "@-------@\n"
                                "@-@@@@@-@\n"
                                "@-@---@-@\n"
                                "@-@@@@@-@\n"
                                "@-------@\n"
                                "@@@@@@@@@");

    CHECK(mat(13, 5, '@', '-') == "@@@@@@@@@@@@@\n"
                                    "@-----------@\n"
                                    "@-@@@@@@@@@-@\n"
                                    "@-----------@\n"
                                    "@@@@@@@@@@@@@");

    CHECK(mat(3, 5, '$', '+') == "$$$\n"
                                    "$+$\n"
                                    "$+$\n"
                                    "$+$\n"
                                    "$$$");

    CHECK(mat(1, 1, '#', ')') == "#");

    CHECK(mat(5, 5, '@', '$') == "@@@@@\n"
                                    "@$$$@\n"
                                    "@$@$@\n"
                                    "@$$$@\n"
                                    "@@@@@");

    CHECK(mat(5, 5, '@', '$') == "-----\n"
                                    "-@@@-\n"
                                    "-@-@-\n"
                                    "-@-@-\n"
                                    "-@-@-\n"
                                    "-@@@-\n"
                                    "-----");                                                

    CHECK(mat(5, 3, '$', '+') == "$$$$$\n"
                                "$+$+$\n"
                                "$$$$$\n");

    CHECK(mat(1, 5, '&', '-') == "&\n"
                                 "&\n"
                                 "&\n"
                                 "&\n"
                                 "&\n"); 
}

TEST_CASE("Bad input"){
    //row or column number is 0
    CHECK_THROWS(mat(0, 1, '$', '%'));
    CHECK_THROWS(mat(0, 0, '!', '#'));
    CHECK_THROWS(mat(1, 0, '!', '#'));

    //row or column number is negetive
    CHECK_THROWS(mat(-5, 3, '!', '#'));
    CHECK_THROWS(mat(-7, -3, '!', '#'));
    CHECK_THROWS(mat(9, -5, '!', '#'));
    CHECK_THROWS(mat(-231, -5, '!', '#'));


    //row or column number is odd
    CHECK_THROWS(mat(10, 5, '$', '%'));
    CHECK_THROWS(mat(4, 6, '!', '#'));
    CHECK_THROWS(mat(9, 6, '!', '#'));
    CHECK_THROWS(mat(4, 7, '!', '#'));
    CHECK_THROWS(mat(2, 6, '@', '$'));
    CHECK_THROWS(mat(8, 3, '^', '&'));

    //symbols are spaces
    CHECK_THROWS(mat(9, 6, ' ', '#'));
    CHECK_THROWS(mat(4, 7, '\t', '#'));
    CHECK_THROWS(mat(2, 6, '\n', '$'));
    CHECK_THROWS(mat(8, 3, '\r', '&'));

}