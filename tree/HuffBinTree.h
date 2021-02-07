#ifndef HUFFMANCODING_HUFFBINTREE_H
#define HUFFMANCODING_HUFFBINTREE_H


#include <string>

class HuffBinTree {
private:

    class HuffNode {
    public:
        virtual ~HuffNode();

        virtual bool isLeaf();

        virtual int getCount();
    };

    class Node : public HuffNode {
        friend HuffBinTree;

    private:
        HuffNode *l; //represents 1
        HuffNode *r; // represents 0
        const int cnt;

    public:
        Node(HuffNode*, HuffNode*, int);

        ~Node() override;

        bool isLeaf() override;

        int getCount() override;
    };

    class Leaf : public HuffNode {
        friend HuffBinTree;

    private:
        const char val;
        const int cnt;

    public:
        Leaf(char, int);

        ~Leaf() override;

        bool isLeaf() override;

        int getCount() override;
    };

    struct Compare {
    public:
        bool operator() (HuffNode*, HuffNode*);
    };

    Node *root = nullptr;
    std::map<char, std::basic_string<char>> codebook; // build probably only temporarely

public:
    ~HuffBinTree();

    bool isEmpty();

    void buildTree(std::basic_string<char>);

};


#endif //HUFFMANCODING_HUFFBINTREE_H
