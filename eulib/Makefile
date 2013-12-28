CPPFLAGS=-I.
CXXFLAGS=-Wall -Wextra -ggdb
LDFLAGS=

TEST_DIR=tests
TEST_SRC=$(wildcard $(TEST_DIR)/*.cpp)
TEST=$(TEST_SRC:.cpp=)

GTEST_DIR=gtest

.PHONY: test gtest clean

all: test gtest

test: ${TEST}

gtest:
	@${MAKE} -C ${GTEST_DIR}

%: %.cpp PrimeList.ipp PrimeList.hpp
	${CXX} ${CPPFLAGS} ${CXXFLAGS} $< -o $@ ${LDFLAGS}

clean:
	@ find . -name "*~" -delete
	@ make -C ${GTEST_DIR} clean

mrproper: clean
	@ rm -f $(TEST)
	@ make -C ${GTEST_DIR} mrproper
