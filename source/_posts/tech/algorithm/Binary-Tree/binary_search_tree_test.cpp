/*
 * Unittest for BinarySearchTree class, the based unittest engine is googletest.
 */
#include "binary_search_tree.h"

#include <typeinfo>
#include "gtest/gtest.h"

namespace tree {

// // test fixture
class BinarySearchTreeTest : public ::testing::Test {
 protected:
  // Check initialization
  void SetUp() override {
    ASSERT_EQ(0u, string_bst_.size());

    // init for string type
    string_bst_.put("H", "H");
    string_bst_.put("C", "C");
    string_bst_.put("S", "S");
    string_bst_.put("A", "A");
    string_bst_.put("E", "E");
    string_bst_.put("R", "R");
    string_bst_.put("X", "X");
  }
  // member variables
  BinarySearchTree<std::string, std::string> string_bst_ {""};
};

TEST_F(BinarySearchTreeTest, Put) {
  EXPECT_EQ(7u, string_bst_.size());
  string_bst_.put("Y", "Y");
  EXPECT_EQ("Y", string_bst_.get("Y"));
  string_bst_.put("Y", "Y1");
  EXPECT_EQ("Y1", string_bst_.get("Y"));
  EXPECT_EQ(8u, string_bst_.rank("Y"));
}

TEST_F(BinarySearchTreeTest, Get) {
  // string type
  EXPECT_EQ(7u, string_bst_.size());
  EXPECT_EQ("", string_bst_.get("not exist"));
  EXPECT_EQ("X", string_bst_.get("X"));
}

TEST_F(BinarySearchTreeTest, Remove) {
  EXPECT_EQ(7u, string_bst_.size());
  // not exist key
  string_bst_.remove("not exist key");

  string_bst_.remove("X");
  EXPECT_EQ(6u, string_bst_.size());
  EXPECT_EQ("", string_bst_.get("X"));
}

TEST_F(BinarySearchTreeTest, Rank) {
  EXPECT_EQ(6u, string_bst_.rank("S"));
  string_bst_.remove("A");
  EXPECT_EQ(5u, string_bst_.rank("S"));
}

TEST_F(BinarySearchTreeTest, Floor) {
  EXPECT_EQ("H", string_bst_.floor("H"));
  string_bst_.remove("E");
  EXPECT_EQ(3u, string_bst_.rank("H"));
}

TEST_F(BinarySearchTreeTest, Ceiling) {
  EXPECT_EQ("H", string_bst_.ceiling("H"));
  string_bst_.remove("S");
  EXPECT_EQ(5u, string_bst_.rank("R"));
}
} // namespace Tree


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
