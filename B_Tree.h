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

};
