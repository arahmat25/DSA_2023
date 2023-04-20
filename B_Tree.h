//B-Tree header file with classes

#ifndef B_TREE_H
#define B_TREE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <set>

// B-Tree node class 

class BTreeNode{
  int *keys : // array/vector of keys
  int t; // min degree that defines the range for the # of keys 
  int numKeys; // number of keys in node 
  BTreeNode **child_ptr;  // array/vector of child pointers
  bool leaf; //true when node is leaf, else false 
  
  public: 
  
  BTreeNode(int temp, bool leaf); // constructor
  
  void insertNonFull(int k); // helper function that inserts a key into a node that isnt filled
  void navigate(); //function that traverses nodes in a subtree that are rooted with this node 
  void splitChild(int i, BTreeNode *y); //helper function to split a child node
  
  BTreeNode *search(int k); // function that searches for a key in a subtree rooted in this node
  
  friend class BTree;
  
  
};






















































































































#endif
