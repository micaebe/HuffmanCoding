#include "testHuffBinTree.h"
#include "gtest/gtest.h"

TEST(BasicTest, Constructor) {
    HuffBinTree tree;
    EXPECT_TRUE(tree.isEmpty());
}



