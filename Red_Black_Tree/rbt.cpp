#include <iostream>
#include <string>
#include "rbt.h"

using namespace std;

Node::Node(int key, string val){
    this->key = key;
    this->val = val;
    isBlack = false;
    left = nullptr;
    right = nullptr;
}

Map::Map(){
    root = nullptr;
    size = 0;
}

void Map::insert(int key, string val){
    Node* new_node = new Node(key, val);
    if (root == nullptr) {
        new_node->isBlack = true;
        root = new_node;
    } else {
        insertHelper(root, new_node);
    }
    size++;
}

void Map::insertHelper(Node* parent, Node* new_node){
    if (new_node->key < parent->key) {
        if (parent->left == nullptr) {
            parent->left = new_node;
            new_node->parent = parent;
        } else {
            insertHelper(parent->left, new_node);
        }
    }
    else if (new_node->key > parent->key) {
        if (parent->right ==nullptr) {
            parent->right = new_node;
            new_node->parent = parent;
        } else {
            insertHelper(parent->right, new_node);
        }
    }
    checkColor(new_node);
}

void Map::checkColor(Node* n){
    if (n == root){
        return;
    }
    if (!n->isBlack && !n->parent->isBlack){
        correctTree(n);
    }
    checkColor(n->parent);
}
