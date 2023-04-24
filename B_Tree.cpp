#include "B_Tree.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

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
    keys = new int[2*degree-1];
    child_ptr = new BTreeNode *[2*degree];
}

// Output Tree
void BTreeNode::printTree(){
    int i;
    for (i = 0; i < numKeys; i++){
        // If the node is not a leaf, output all keys within that node.
        if (!leaf) child_ptr[i]->printTree();
        // If it is not a leaf, move to it's next child node
        std::cout << " " << keys[i];
    }
    // Output the keys of the last child node
    if (leaf == false) child_ptr[i]->printTree();
}

//outputs tree in dot file
void BTreeNode::printDot(BTreeNode* temp,string fname){
    //makes sure the inputed node is not a leaf
    if(temp->leaf == false){
        ofstream output_file(fname,ios::app); //opens the file
        if(output_file.is_open()){

            for(int i = 0;i <= temp->numKeys;i++){
                //writes a parent pointed to  all its children
                output_file << "node" << temp << "->" << "node" << temp->child_ptr[i] << "\n";
                output_file << "node" << temp->child_ptr[i] << "[label=" << '"';
                for(int j = 0; j < temp->child_ptr[i]->numKeys; j++){ // prints out the children's keys
                    output_file << temp->child_ptr[i]->keys[j] << " ";
                }
                output_file << '"' << "]" << "\n";
                if(!temp->child_ptr[i]->leaf){
                    printDot(temp->child_ptr[i], fname); // calls the function again for every child in the
                }

            }
        }

        output_file.close();
    }
}

//outputs tree in dot file
void BTree::printDot(){
    //makes sure there is a btree
    if(root != NULL) {
        //opens the file
        string fname = "dot_file.txt";
        ofstream output_file(fname);
        output_file << "digraph G {"<< "\n"; //starts the dot file
        output_file << "\n";
        output_file << "node" << root << "[label=" << '"';
        for(int i = 0; i < root->numKeys;i++){
            output_file << root->keys[i] << " ";
        }
        output_file << '"' << "]" << "\n";
        output_file.close();
        root->printDot(root,fname); //has the root call the BTreeNode's printdot function
    }
    ofstream output_file("dot_file.txt",ios::app); //opens the file to add the ending and closes the file
    if(output_file.is_open()){
        output_file << "}" << endl;
    }
    output_file.close();
}

// Find a specific key in the tree
BTreeNode *BTreeNode::searchTree(int key, int count){
    // Loop through the keys until the correct key is found, or you reach the last key
    count +=1; // count is incremented by 1
    int i = 0;
    while (keys[i] < key && i < numKeys) i++;
    // If the key is found, return the node pointer OR if the node is a leaf and the key is not found, return a null pointer, as the key is not in the tree.
    if (keys[i] == key || (leaf && keys[i] != key)) {
        cout << "The count of nodes searched is " << count << "."<< endl; // this is the last check, output how many nodes were checked. 
        return (keys[i] == key) ? this : nullptr;
    }
        // If the key is not found, and it is not a leaf, move to the child node that has contains the range value of the key
    else return child_ptr[i]->searchTree(key, count);
}

// The main function that inserts a new key in this B-Tree
void BTree::insert(int key){
    // Create the root if the tree is empty
    if (root == nullptr) root = new BTreeNode(degree, true), root->keys[0] = key, root->numKeys = 1;
    else{
        if (root->numKeys == 2*degree-1){ // If the number of keys in the root is equal to the maximum allowed by the degree
            BTreeNode *new_node = new BTreeNode(degree, false); // Create a new empty node
            new_node->child_ptr[0] = root; // Make the previous root of the tree a child of the new node
            new_node->splitChild(0, root); // Split the old root, move the median key to the new node
            int i = 0;
            if (new_node->keys[0] < key) i++; // Find the index of the key that is just before the key that is greater than the key being inserted
            new_node->child_ptr[i]->insertNonFull(key); // Insert the key into the appropriate root
            root = new_node; // Change the root node to the new node
        }
        else root->insertNonFull(key); // Else, insert the key into the non-full root.
    }
}

void BTreeNode::insertNonFull(int key) {
    int i = numKeys;
    if (leaf) { // If the node is a leaf, locate where the key needs to be inserted and move all keys to the right one from that location
        while (i-- && keys[i] > key) keys[i + 1] = keys[i];
        keys[i + 1] = key, ++numKeys; // insert the key
    } else {
        while (i-- && keys[i] > key) {} // find the child node that is going to hold the new key
        if (child_ptr[i + 1]->numKeys == 2 * degree - 1) // if the child node is full, execute the split function
            splitChild(i + 1, child_ptr[i + 1]), i += keys[i + 1] < key;
        child_ptr[i + 1]->insertNonFull(key); // Recurse this function on the child node
    }
}

void BTreeNode::splitChild(int i, BTreeNode *old_node) {
    BTreeNode *new_node = new BTreeNode(old_node->degree, old_node->leaf); // Create a new node, the node should hold half of the keys in the old node
    new_node->numKeys = degree - 1; // Change the number of keys
    for (int j = 0; j < degree-1; j++) new_node->keys[j] = old_node->keys[j+degree]; // copy the keys to the new node
    if (!old_node->leaf) for (int j = 0; j < degree; j++) new_node->child_ptr[j] = old_node->child_ptr[j+degree]; // If the old node was not a leaf, copy last half of the keys to the new node
    old_node->numKeys = degree - 1; // Change the number of keys
    for (int j = numKeys; j >= i+1; j--) child_ptr[j+1] = child_ptr[j]; // Create array space for the new child
    child_ptr[i+1] = new_node; // Assign new node as a child of old node
    for (int j = numKeys-1; j >= i; j--) keys[j+1] = keys[j]; // locate where the key needs to be inserted and move all keys to the right one from that location
    keys[i] = old_node->keys[degree-1]; // insert key
    numKeys++;
}
