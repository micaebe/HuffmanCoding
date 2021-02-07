//
// Created by Michael Eberhard on 06.02.21.
//

#include <map>
#include <queue>
#include "HuffBinTree.h"


/********************************************************************
 * HuffNode (Superclass)
 *******************************************************************/
HuffBinTree::HuffNode::~HuffNode() = default;

bool HuffBinTree::HuffNode::isLeaf() {
    return false;
}

int HuffBinTree::HuffNode::getCount() {
    return 0;
}


/********************************************************************
 * Node (Subclass)
 *******************************************************************/
HuffBinTree::Node::Node(HuffBinTree::HuffNode *left, HuffBinTree::HuffNode *right, int count): l(left), r(right), cnt(count) { }

HuffBinTree::Node::~Node() { }

bool HuffBinTree::Node::isLeaf() {
    return false;
}

int HuffBinTree::Node::getCount() {
    return cnt;
}


/********************************************************************
 * Leaf (Subclass)
 *******************************************************************/
HuffBinTree::Leaf::Leaf(char value, int count) : val(value), cnt(count) { }

HuffBinTree::Leaf::~Leaf() { }

bool HuffBinTree::Leaf::isLeaf() {
    return true;
}

int HuffBinTree::Leaf::getCount() {
    return cnt;
}


/********************************************************************
 * Huffman Binary Tree
 *******************************************************************/
HuffBinTree::~HuffBinTree() = default;

bool HuffBinTree::isEmpty() {
    return root == nullptr;
}

void HuffBinTree::buildTree(std::basic_string<char> toEncode) {
    if (root != nullptr) {
        return;
    }

    // count appearance of each character
    std::map<char, int> char_count;
    for (int i = 0; i < (int)toEncode.size(); ++i) {
        auto it = char_count.find(toEncode[i]);
        if (it != char_count.end()) {
            it->second = it->second + 1;
        } else {
            char_count.insert({toEncode[i], 1});
        }
    }

    auto it = char_count.begin();
    if (char_count.size() == 1) {
        root = new Node(new Leaf(it->first, it->second), nullptr, it->second);
        return;
    }

    std::priority_queue<HuffNode*, std::vector<HuffNode*>, Compare> pq;

    // add leaves
    while (it != char_count.end()) {
        pq.push((HuffNode*)(new Leaf(it->first, it->second)));
        ++it;
    }

    // add inner nodes
    while (pq.size() > 1) {
        HuffNode* h1 = pq.top();
        pq.pop();
        HuffNode* h2 = pq.top();
        pq.pop();
        pq.push((HuffNode*)(new Node(h1, h2, h1->getCount() + h2->getCount())));
    }
    root = (Node*)pq.top();
}

bool HuffBinTree::Compare::operator()(HuffBinTree::HuffNode* h1, HuffBinTree::HuffNode* h2) {
    return h1->getCount() > h2->getCount();
}
