#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

// B-Tree node class 

class BTreeNode{

    int degree; // degree of tree, used to calculate lower and upper bounds of keys/children
    bool leaf; //true when node is leaf, else false
    int numKeys; // number of keys in node
    int *keys; // vector of keys
    BTreeNode **child_ptr;  // vector of pointers to children

public:
    BTreeNode(int degree, bool leaf); // node constructor
    void insertNonFull(int key); //  inserts a key into a node that is not filled
    void printTree(); // outputs the path
    void printDot(BTreeNode *temp,string fname); // outputs dot visualization
    void splitChild(int i, BTreeNode *y); // split a child node
    BTreeNode *searchTree(int key, int count); // searches for a key in a subtree, count tracks how many nodes have been searched.
    friend class BTree;
};

class BTree{

    int degree;  // degree of tree, used to calculate lower and upper bounds of keys/children
    BTreeNode *root; // root pointer
public:
    explicit BTree(int _degree);// tree constructor
    void printTree(){root->printTree();} // outputs path
    void printDot();
    void insert(int key); // The main function that inserts a new key in this B-Tree
    // function to search a key in this tree
    BTreeNode* search(int key, int count){return root->searchTree(key, count);} // searches for a key, count tracks how many nodes have been searched.
};
