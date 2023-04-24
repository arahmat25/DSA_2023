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
