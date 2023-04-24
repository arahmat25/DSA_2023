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
    vector<int> *keys; // vector of keys
    vector<BTreeNode> **child_ptr;  // vector of pointers to children

public:

    BTreeNode(int degree, bool leaf); // node constructor

    void insertNonFull(int key); //  inserts a key into a node that is not filled
    void navigate(); // outputs the path the
    void splitChild(int i, BTreeNode *y); // split a child node

    BTreeNode *search(int key); // searches for a key in a subtree

    friend class BTree;


};

class BTree{
    
int degree;  // degree of tree, used to calculate lower and upper bounds of keys/children
    BTreeNode root; // root pointer

public:
    explicit BTree(int _degree);// tree constructor
    void printTree(){root->printTree();} // outputs path
    void printDot();
    void insert(int key); // The main function that inserts a new key in this B-Tree
    // function to search a key in this tree
    BTreeNode search(int key){return root->searchTree(key);}
};
