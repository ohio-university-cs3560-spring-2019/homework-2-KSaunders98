# ********************************************************************
# File: Makefile
# Author: Kirk Saunders, ks825016@ohio.edu
# School: Ohio University EECS
# Last modified: 1/28/2019
# File description: This Makefile compiles the findreplace library
#                   into a static library archive file, and then uses
#                   that archive file to compile and link the prog1
#                   program file that can be used to interface the
#                   find replace functionality.
# ********************************************************************

PROJECT_NAME = prog1
LIBRARY_NAME = findreplace

BIN_DIR		= bin
INCLUDE_DIR	= include
LIBRARY_DIR	= lib
SRC_DIR		= src

CXX			= g++
CXX_FLAGS	= -I$(INCLUDE_DIR)
AR			= ar
AR_FLAGS	= rcs
LD_FLAGS	= -L$(LIBRARY_DIR)
LD_LIBS		= -l$(LIBRARY_NAME)

$(PROJECT_NAME): $(BIN_DIR)/main.o $(LIBRARY_DIR)/lib$(LIBRARY_NAME).a
	$(CXX) $(BIN_DIR)/main.o -o $@ $(LD_FLAGS) $(LD_LIBS)

$(LIBRARY_DIR)/lib$(LIBRARY_NAME).a: $(BIN_DIR)/findreplace.o | $(LIBRARY_DIR)
	$(AR) $(AR_FLAGS) $@ $^

$(BIN_DIR)/main.o: $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/findreplace.hpp | $(BIN_DIR)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(BIN_DIR)/findreplace.o: $(SRC_DIR)/findreplace.cpp $(INCLUDE_DIR)/findreplace.hpp | $(BIN_DIR)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(BIN_DIR):
	mkdir -p $@

$(LIBRARY_DIR):
	mkdir -p $@

clean:
	rm -f -r $(BIN_DIR)
	rm -f -r $(LIBRARY_DIR)

# tell make that the clean target isn't a file
.PHONY: clean