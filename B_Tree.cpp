#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

// Constructor for B-Tree
BTree::BTree(int deg){
    // Initialize the root to a null pointer and set the degree to deg - This constructor is called by the main and degree is a user input
    root = nullptr;  degree = deg;
}

// Constructor for B-Tree node
BTreeNode::BTreeNode(int deg, bool leafYN){
    // Copy the given minimum degree and leaf property and create a new keys array to hold the keys of the node and new child pointer array to store pointers for this node's children
    degree = deg;
    leaf = leafYN;
    numKeys = 0;
    keys = new int[2degree-1];
    child_ptr = new BTreeNode[2*degree];
}
