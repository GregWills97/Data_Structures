#ifndef RBT_H
#define RBT_H

#include <string>

using namespace std;

class Iterator;
class Map;

class Node{
    public:
        Node(int key, string val);
        ~Node();
        Node* mostLeft();
        Node* mostRight();
    private:
        int key;
        string val;
        bool isBlack;
        Node* left;
        Node* right;
        Node* parent;
        friend class Map;
        friend class Iterator;
};

class Iterator{
    public:
        Iterator();
        int getKey() const;
        string getVal() const;
        void next();
        void prev();
        bool equals(Iterator other) const;
    private:
        Node* position;
        Map*  container;
        friend class Map;
};
        
class Map{
    public:
        Map();
        void clear();
        void insert(int key, string val);
        void printInOrder() const;
        void printLevelOrder() const;
        void print2D() const;
        int height() const;
        int max() const;
        int min() const;
        int size() const;
        string find(int key) const;
        Iterator begin();
        Iterator end();
    private:
        Node* root;
        int  m_size;
        int  m_max;
        int  m_min;
        int  heightHelper(Node* n) const;
        void clearHelper(Node* root);
        void insertHelper(Node* parent, Node* new_node);
        void printInOrderHelper(Node* n) const;
        void printLevel(Node* root, int level) const;
        void print2DHelper(Node* root, int space) const;
        void checkColor(Node* n);
        void correctTree(Node* n);
        void chooseRotate(Node* grandparent, Node* n);
        void rotateLeft(Node* n);
        void rotateRight(Node* n);
        friend class Iterator;
};

#endif
