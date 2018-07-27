# Genrated binary path
OUT_PATH=~/tmp

UTIL_PATH=../../util/basecpp
THIRD_PARTY_PATH=~/project/third_party/cpp
GTEST_OBJ=${THIRD_PARTY_PATH}/gtest-all.o

CXXFLAGS += -stdlib=libc++ -std=c++11 -g -Wall -Wextra -pthread

binary_search_tree_test	: binary_search_tree_test.o ${GTEST_OBJ}
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o ${OUT_PATH}/$@
	rm -f binary_search_tree_test.o

binary_search_tree_test.o: binary_search_tree_test.cpp binary_search_tree.h ${UTIL_PATH}
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c binary_search_tree_test.cpp

.PHONY : clean

clean:
	rm -f ${OUT_PATH}/*binary* *.o*
