// ********************************************************************
// File: findreplace.cpp
// Author: Kirk Saunders, ks825016@ohio.edu
// School: Ohio University EECS
// Last modified: 1/28/2019
// File description: This library declaration file declares a
//                   findreplace function that takes an input stream,
//                   an output stream, a string to find, and a string
//                   to replace with. It reads until EOF the input
//                   string and outputs out to the output stream the
//                   replaced text.
// ********************************************************************

#ifndef FINDREPLACE_HPP
#define FINDREPLACE_HPP

#include <iostream>
#include <string>

void findreplace(std::istream& ins, std::ostream& outs, const std::string& find, const std::string& replace);

#endif