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

Node::~Node(){
};

Node* Node::mostLeft() {
    Node* current_node = this;
    while(current_node->left != nullptr) {
        current_node = current_node->left;
    }
    return current_node;
}

Node* Node::mostRight() {
    Node* current_node = this;
    while(current_node->right != nullptr) {
        current_node = current_node->right;
    }
    return current_node;
}

Iterator::Iterator(){
    position  = nullptr;
    container = nullptr;
    cout << "Iterator Created" << endl;
}

Iterator::~Iterator(){
    cout << "Iterator Destroyed" << endl;
}

Map::Map(){
    root = nullptr;
    m_size = 0;
}

void Map::clear(){
    clearHelper(root);
}

void Map::clearHelper(Node* root){
    if (root == nullptr){
        return;
    }
    clearHelper(root->left);
    clearHelper(root->right);
    delete root;
}
void Map::insert(int key, string val){
    Node* new_node = new Node(key, val);
    if (root == nullptr) {
        new_node->isBlack = true;
        root = new_node;
    } else {
        insertHelper(root, new_node);
    }
    m_size++;
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
    if (n != root){
        checkColor(n->parent);
    }
}

void Map::correctTree(Node* n){
    //if parent is grandparents left child
    if (n->parent == n->parent->parent->left){
        //if aunt is black rotate 
        if ((n->parent->parent->right == nullptr) || (n->parent->parent->right->isBlack)){
            chooseRotate(n->parent->parent, n);
            return;
        } else {
            if (n->parent->parent != root){     //else color flip
                n->parent->parent->isBlack = false;
            }
            n->parent->isBlack = true;
            n->parent->parent->right->isBlack = true;
        }
    } else {
        if ((n->parent->parent->left == nullptr) || (n->parent->parent->left->isBlack)){
            chooseRotate(n->parent->parent, n);
            return;
        } else {
            if (n->parent->parent != root){
                n->parent->parent->isBlack = false;
            }
            n->parent->isBlack = true;
            n->parent->parent->left->isBlack = true;
        }
    }
}

void Map::chooseRotate(Node* grandparent, Node* n){
    //if grandparent left exists
    if (grandparent->left != nullptr) {
        //relation to grandparent is left left
        if (grandparent->left->left == n){
            rotateRight(grandparent);
            return;
        }
        //relation to grandparent is left right
        else if (grandparent->left->right == n){
            rotateLeft(n->parent);
            rotateRight(grandparent);
            return;
        }
    }
    //if grandparent right exists
    if (grandparent->right != nullptr) {
        //relation to grandparent is right right
        if (grandparent->right->right == n){
            rotateLeft(grandparent);
            return;
        }
        //relation to grandparent is right left
        else if (grandparent->right->left == n){
            rotateRight(n->parent);
            rotateLeft(grandparent);
            return;
        }
    }
}

void Map::rotateLeft(Node* n){
    Node* temp = n->right;
    n->right = temp->left;
    if (n->right != nullptr) {
        n->right->parent = n;
    }
    if (n->parent == nullptr) {
        root = temp;
        temp->parent = nullptr;
    } else {
        temp->parent = n->parent;
        //if n is left child
        if (n->parent->left == n) {
            temp->parent->left = temp;
        } else {
            temp->parent->right = temp;
        }
    }
    temp->left = n;
    n->parent = temp;
    temp->isBlack = true;
    temp->left->isBlack = false;
    if (temp->right != nullptr){
        temp->right->isBlack = false;
    }
}

void Map::rotateRight(Node* n){
    Node* temp = n->left;
    n->left = temp->right;
    if (n->left != nullptr) {
        n->left->parent = n;
    }
    if (n->parent == nullptr){
        root = temp;
        temp->parent = nullptr;
    } else {
        temp->parent = n->parent;
        //if n is left child
        if (n->parent->left == n){
            temp->parent->left = temp;
        } else {
            temp->parent->right = temp;
        }
    }
    temp->right = n;
    n->parent = temp;
    temp->isBlack = true;
    temp->right->isBlack = false;
    if (temp->left != nullptr){
        temp->left->isBlack = false;
    }
}

void Map::printInOrder() const {
    if (root == nullptr){
        cout << "empty tree" << endl;
    } else {
        printInOrderHelper(root);
    }
}

void Map::printInOrderHelper(Node* n) const {
    if (n->left != nullptr) {
        printInOrderHelper(n->left);
    }
    string color;
    if (n->isBlack){
        color = "Black";
    } else {
        color = "Red";
    }
    cout << n->key << " : " << n->val << " : " << color << endl;

    if (n->right != nullptr) {
        printInOrderHelper(n->right);
    }
}

string Map::find(int key) const{
    Node* search_node = root;
    while (search_node != nullptr){
        if (key < search_node->key){
            search_node = search_node->left;
        }
        else if (key > search_node->key){
            search_node = search_node->right;
        }
        else{
            return search_node->val;
        }
    }
    return "Not in tree";
}

int Map::height() const {
    return heightHelper(root);
}

int Map::heightHelper(Node* n) const{
    if (n == nullptr){
        return 0;
    } else {
        int leftHeight  = heightHelper(n->left);
        int rightHeight = heightHelper(n->right);
        
        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }
}

int Map::max() const {
    Node* current_node = root;
    while(current_node->right != nullptr){
        current_node = current_node->right;
    }
    return current_node->key;
}

void Map::printLevelOrder() const {
    int h = this->height();
    for(int i = 0; i < h; i++){
        printLevel(root, i);
    }
}

void Map::printLevel(Node* root, int level) const {
    if (root == nullptr){
        return;
    }
    if (level == 0) {
        string color;
        if (root->isBlack){
            color = "Black";
        } else {
            color = "Red";
        }
        cout << root->key << " : " << root->val << " : " << color << endl;
    }
    else if (level > 0) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void Map::print2D() const {
    print2DHelper(root, 0);
}

void Map::print2DHelper(Node* root, int space) const {
    int count = 3;
    if (root == nullptr){
        return;
    }
    space += count;
    print2DHelper(root->right, space);
    cout << endl;
    for(int i = count; i < space; i++){
        cout << " ";
    }
    cout << root->key << endl;
    print2DHelper(root->left, space);
}


Iterator Map::begin() {
    Iterator it;
    it.position  = root->mostLeft();
    it.container = this;
    return it;
}

Iterator Map::end() {
    Iterator it;
    it.position  = nullptr;
    it.container = this;
    return it;
}

int Iterator::getKey() const {
    return position->key;
}

string Iterator::getVal() const {
    return position->val;
}

void Iterator::next() {
    if(position->key == container->max()){
        position = nullptr;
        return;
    }
    if (position->right == nullptr){
        int current_key = position->key;
        position = position->parent;
        while(current_key > position->key){
            position = position->parent;
        }
    } else {
        position = position->right->mostLeft();
    }
}

void Iterator::prev() {
    if (position->left == nullptr){
        position = position->parent;
    } else {
        position = position->left->mostRight();
    }
}

bool Iterator::equals(Iterator other) const{
    return position == other.position;
}
