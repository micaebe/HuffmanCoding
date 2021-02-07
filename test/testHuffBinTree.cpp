#include "testHuffBinTree.h"
#include "gtest/gtest.h"

TEST(BasicTest, IsEmpty) {
    HuffBinTree tree;
    EXPECT_TRUE(tree.isEmpty());
}

TEST(BasicTest, BuildTree) {
    HuffBinTree tree;
    tree.buildTree("testphrase");
}



