//
// Created by Michael Eberhard on 06.02.21.
//

#include "HuffBinTree.h"


/********************************************************************
 * HuffNode (Superclass)
 *******************************************************************/
HuffBinTree::HuffNode::~HuffNode() = default;

bool HuffBinTree::HuffNode::isLeaf() {
    return false;
}


/********************************************************************
 * Node (Subclass)
 *******************************************************************/
HuffBinTree::Node::Node(HuffBinTree::Node *left, HuffBinTree::Node *right, int count): l(left), r(right), cnt(count) { }

HuffBinTree::Node::~Node() { }

bool HuffBinTree::Node::isLeaf() {
    return false;
}


/********************************************************************
 * Leaf (Subclass)
 *******************************************************************/
HuffBinTree::Leaf::Leaf(char value, int count) : val(value), cnt(count) { }

HuffBinTree::Leaf::~Leaf() { }

bool HuffBinTree::Leaf::isLeaf() {
    return true;
}


/********************************************************************
 * Huffman Binary Tree
 *******************************************************************/
HuffBinTree::~HuffBinTree() = default;

bool HuffBinTree::isEmpty() {
    return root == nullptr;
}
