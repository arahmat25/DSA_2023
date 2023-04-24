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

void BTree::printDot(){
    if(root != NULL) {
        string fname = "dot_file.txt";
        ofstream output_file(fname);
        output_file << "digraph G {"<< "\n";
        output_file << "\n";
        output_file << "node" << root << "[label=" << '"';
        for(int i = 0; i < root->numKeys;i++){
            output_file << root->keys[i] << " ";
        }
        output_file << '"' << "]" << "\n";
        output_file.close();
        root->printDot(root,fname);
    }
    ofstream output_file("dot_file.txt",ios::app);
    if(output_file.is_open()){
        output_file << "}" << endl;
    }
}

void BTreeNode::printDot(BTreeNode* temp,string fname){
    if(temp->leaf == false){
        ofstream output_file(fname,ios::app);
        if(output_file.is_open()){

            for(int i = 0;i <= temp->numKeys;i++){

                output_file << "node" << temp << "->" << "node" << temp->child_ptr[i] << "\n";
                output_file << "node" << temp->child_ptr[i] << "[label=" << '"';
                for(int j = 0; j < temp->child_ptr[i]->numKeys; j++){
                    output_file << temp->child_ptr[i]->keys[j] << " ";
                }
                output_file << '"' << "]" << "\n";
                if(!temp->child_ptr[i]->leaf){
                    printDot(temp->child_ptr[i], fname);
                }

            }
        }

        output_file.close();
    }
}
// Find a specific key in the tree
BTreeNode *BTreeNode::searchTree(int key){
    // Loop through the keys until the correct key is found, or you reach the last key
    int i = 0;
    while (keys[i] < key && i < numKeys) i++;
    // If the key is found, return the node pointer OR if the node is a leaf and the key is not found, return a null pointer, as the key is not in the tree.
    if (keys[i] == key || (leaf && keys[i] != key)) return (keys[i] == key) ? this : nullptr;
    // If the key is not found, and it is not a leaf, move to the child node that has contains the range value of the key
    else return child_ptr[i]->searchTree(key);
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
