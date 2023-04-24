#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "B_Tree.h"
#include "B_Tree.cpp"

int main(int argc, char* argv[]) {

    // Take in the filename a command line argument and assign it to a string
    string filename = argv[1];

    // Initialize degree integer and ask the user what degree they would like to set for the B-Tree
    int degree;
    cout << "What would you like the degree of this B-Tree to be? Input integer here:";
    cin >> degree;

    // Construct B-Tree
    BTree tree(degree);

    // Call read file function
    read_file(filename, &tree);

    return 0;

}






















return 0;
