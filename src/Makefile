# DIRECTORIES
HEADDIR = ../headers/
vpath %.h $(HEADDIR)

# COMPILER FLAGS
CXXFLAGS   = -std=c++11 -I $(HEADDIR) -Wall -Wfatal-errors
TESTFLAGS = -DUNIT_TEST -lboost_unit_test_framework

# FILES
EXE = huffman
TESTEXE = huffman_test
SRC = main.cpp
TESTSRC = test_suite.cpp
HEAD = huffman.h

all: $(EXE) $(TESTEXE)

exe: $(EXE)

test: $(TESTEXE)

$(EXE): $(SRC) $(HEAD)
	g++ $(CXXFLAGS) $(filter %.cpp, $^) -o $@

$(TESTEXE): $(SRC) $(TESTSRC) $(HEAD)
	g++ $(CXXFLAGS) $(TESTFLAGS) $(filter %.cpp, $^) -o $@

clean:
	rm $(EXE) $(TESTEXE)




