// ********************************************************************
// File: findreplace.cpp
// Author: Kirk Saunders, ks825016@ohio.edu
// School: Ohio University EECS
// Last modified: 1/28/2019
// File description: This library definition file defines a findreplace
//                   function that performs a find replace operation
//                   on a given input stream. See findreplace.hpp for
//                   more info.
// ********************************************************************

#include "findreplace.hpp"

// This method of find and replace _should_ preserve all characters that don't get replaced,
// including newlines.
void findreplace(std::istream& ins, std::ostream& outs, const std::string& find, const std::string& replace) {
    unsigned long index = 0;
    std::string found = "";

    char ch = ins.get();
    while (!ins.eof()) {
        found += ch;
        if (ch == find[index]) {
            ++index;
            if (index == find.size()) {
                outs << replace;
                index = 0;
                found = "";
            }
        } else {
            outs << found;
            index = 0;
            found = "";
        }

        ch = ins.get();
    }
}
