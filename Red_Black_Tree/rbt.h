#ifndef RBT_H
#define RBT_H

#include <string>

using namespace std;

class Map;

class Node{
    public:
        Node(int key, string val);
    private:
        int key;
        string val;
        bool isBlack;
        Node* left;
        Node* right;
        Node* parent;
        friend class Map;
};

class Map{
    public:
        Map();
        void insert(int key, string val);
        void printInOrder() const;
        void printLevelOrder() const;
        string find(int key) const;
    private:
        Node* root;
        int size;
        void insertHelper(Node* parent, Node* new_node);
        void printInOrderHelper(Node *n) const;
        void checkColor(Node* n);
        void correctTree(Node* n);
        void rotateLeft(Node* n);
        void rotateRight(Node* n);
};

#endif
