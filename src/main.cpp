// ********************************************************************
// File: main.cpp
// Author: Kirk Saunders, ks825016@ohio.edu
// School: Ohio University EECS
// Last modified: 1/28/2019
// File description: This main program uses a findreplace library to
//                   provide an interface for finding and replacing
//                   text from the stdin/stdout streams. Thus, it can
//                   also be used to find and replace in files using
//                   file redirection from the command line.
// ********************************************************************

#include <iostream>
#include "findreplace.hpp"

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Error: Incorrect number of arguments." << std::endl
                  << "Usage: ./prog1 [find string] [replace string]" << std::endl;
                  
        return -1;
    }

    findreplace(std::cin, std::cout, argv[1], argv[2]);

    return 0;
}