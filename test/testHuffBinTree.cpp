#include "testHuffBinTree.h"
#include "gtest/gtest.h"

TEST(BasicTest, IsEmpty) {
    HuffBinTree tree;
    EXPECT_TRUE(tree.isEmpty());
}

TEST(BasicTest, BuildTree) {
    HuffBinTree tree;
    tree.buildTree("testphrase");
    EXPECT_TRUE(!tree.isEmpty());
}

TEST(BasicTest, EncodeBasic) {
    HuffBinTree tree;
    std::basic_string<char> toEncode = "testphrase";
    int bitSize = toEncode.size() * 8;
    tree.buildTree(toEncode);
    std::basic_string<char> encoded = tree.encode(toEncode);
    EXPECT_TRUE(encoded.size() < bitSize);
}



