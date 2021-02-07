#ifndef HUFFMANCODING_HUFFBINTREE_H
#define HUFFMANCODING_HUFFBINTREE_H


class HuffBinTree {
private:

    class HuffNode {
    public:
        virtual ~HuffNode();

        virtual bool isLeaf();
    };

    class Node : public HuffNode {
        friend HuffBinTree;

    private:
        HuffNode *l; //represents 1
        HuffNode *r; // represents 0
        const int cnt;

    public:
        Node(Node *, Node *, int);

        ~Node() override;

        bool isLeaf() override;
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
    };

    Node *root = nullptr;

public:
    ~HuffBinTree();

    bool isEmpty();

};


#endif //HUFFMANCODING_HUFFBINTREE_H
