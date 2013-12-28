GTEST_DIR=gtest-1.6.0

CC=g++
CPPFLAGS=-I${GTEST_DIR}/include -I..
CXXFLAGS=-Wall -Wextra -ggdb
LDFLAGS=-lpthread

DEP=../PrimeList.hpp ../PrimeList.ipp
LIBGTEST=libgtest_main.a

TEST_DIR=.
TEST=$(wildcard $(TEST_DIR)/*.cpp)
BIN=$(TEST:.cpp=)

.PHONY: test clean

test: $(BIN)

${LIBGTEST}:
	g++ -I${GTEST_DIR}/include -I${GTEST_DIR} -c ${GTEST_DIR}/src/gtest-all.cc
	g++ -I${GTEST_DIR}/include -I${GTEST_DIR} -c ${GTEST_DIR}/src/gtest_main.cc
	ar -rv ${LIBGTEST} gtest-all.o gtest_main.o

%: %.cpp ${LIBGTEST} ${DEP}
	${CXX} ${CPPFLAGS} ${CXXFLAGS} $< ${LIBGTEST} -o $@ ${LDFLAGS}

clean:
	@ rm -f gtest-all.o gtest_main.o

mrproper: clean
	@ rm -f $(BIN) ${LIBGTEST}
