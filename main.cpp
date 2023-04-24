#include <iostream>
#include "B_Tree.h"
#include <string>
using namespace std;

void read_file(const string& filename, BTree *tree){
    fstream newfile;
    newfile.open(filename, std::ios::in);
    string line;
    while (std::getline(newfile, line)){
        std::string hold;
        std::stringstream streamline(line);
        while (std::getline(streamline, hold,' ')) {
            tree->insert(stoi(hold));
        }
    }
}


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

    // Initialize integer holder for option number;
    int option = 0;

    // Loop through the option menu unless the user chooses to exit the program (option 7)
    while (option != 5) {
        // OPTION MENU
        cout << "Here are the options for this program: " << "\n"
             << "[1] - Insert a new key value." << "\n"
             << "[2] - Search for a key and output how many nodes were searched." << "\n"
             << "[3] - Output path of tree." << "\n"
             << "[4] - Generate DOT file for visualization." << "\n"
             << "[5] - Exit the program." << "\n"
             << "\n" << "Which option would you like to choose? Please enter the number:";

        // User inputs option
        cin >> option;

        // Option 1 - Insert a value into the tree
        if (option == 1){
            int insert_val;
            cout << "What value would you like to insert? Please enter an integer. " << endl;
            cin >> insert_val;
            tree.insert(insert_val);
            cout << endl;
        }

            // Option 2 - Search for a value in the tree, output if it is in the tree or not.
        else if (option == 2){
            int search_val;
            cout << "What value would you like to search for? Please enter an integer. " << endl;
            cin >> search_val;
            if (tree.search(search_val, 0) == nullptr){
                cout << "The value " << search_val << " is not in this B-Tree.";
            }
            else{
                cout << "The value " << search_val << " is in this B-Tree.";
            }
            cout << endl;
        }

            // Option 3 - Output the path of the tree
        else if (option == 3){
            cout << "Here is the tree path:" << endl;
            tree.printTree();
            cout << endl;
        }
            // Option 4 - Output DOT visualization
        else if (option == 4){
            cout << "DOT Visualization file created." << endl;
            tree.printDot();
            cout << endl;
        }
            // Option 5 - Exit the program
        else if (option == 5){
            cout << "Exiting program, goodbye." << endl;
            cout << endl;
        }

            // Output if user does not enter an integer 1-7
        else {
            cout << "Invalid option, please try again." << endl;
            cout << endl;
        }
    }



    return 0;
}
