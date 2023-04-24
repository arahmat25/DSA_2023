<h1> CSC212 DSA Project B-Tree </h1>

<h3> Team Members (Group 7): Grant Houatchanthara , Maxwell Krusz, Amir Rahmat, Eason Chen </h3>

<h2> What is a B-tree ? </h2>

<p size = 5> A B-tree is a self-balancing search tree data structure that is commonly used in databases and file systems to store large amounts of data. It is designed to keep the number of disk reads to a minimum by storing more data in each node rather than a binary search tree, which reduces the number of levels needed to reach a leaf node. In a B-tree, each node contains multiple keys and pointers to its child nodes, and the number of keys per node is kept within a certain range. 
 <br></br>
 <br> A B-tree of order t satisfies the following properties: </br>
<br>-Every node has at most m children. </br>
<br>-Every non-leaf node (except root) has at least ⌈m/2⌉ children.</br>
<br>-The root has at least two children if it is not a leaf node.</br>
<br>-A non-leaf node with k children contains m-1 keys.</br>
<br>-All leaves appear in the same level.</br>
<br>-When a node becomes full (i.e., contains max num keys), it is split into two nodes, and the median key is "promoted" to its parent node. This splitting operation can propagate up the tree, this can cause the root to split and a new root to be created recursivley. </br>
<br></br>
B-trees are efficient for large datasets because they have a low depth and minimize disk reads. They are commonly used in file systems, databases, and operating systems where fast access to data on disk drives is critical. </p>

<h2> How to compile our code in CLion </h2>
<p size = 5>


 
 
 
 
 </p>

<h2> How to compile our code in Visual Studio Code </h2>
<p size = 5>


 
 
 
 
 </p>
 
 <h2> How to visualize DOT file </h2>
<p size = 5>
Website used :  https://dreampuf.github.io/GraphvizOnline/#digraph%20G%20%7B%0D%0A%0D%0A%7D%0D%0A 

 
 
 
 
 </p>
 
 
 
<h2> Pseudo Code for BTree header file </h2>
<p size = 5>


 
 
 
 
 </p>
 
 
 <h2> Pseudo Code for BTree CPP file </h2>
<p size = 5>


 
 
 
 
 </p>
 
 
  <h2> Pseudo Code for MAIN CPP file </h2>
<p size = 5>

// Open the file for input
fstream newfile;
newfile.open(filename, std::ios::in);

// Read each line and insert values into the B-Tree
string line;
while (std::getline(newfile, line)){}

// main 
int main(int argc, char* argv[]) {
 
// Take in the filename a command line argument and assign it to a string
string filename = argv[1];

// Initialize degree integer and ask the user what degree they would like to set for the B-Tree
int degree;
cout << "What would you like the degree of this B-Tree to be? Input integer here:";
cin >> degree;

// Construct B-Tree with the given degree
BTree tree(degree);

// Call the read_file function to insert values from the file into the B-Tree
read_file(filename, &tree);

// Initialize integer holder for option number;
int option = 0;

// Loop through the option menu unless the user chooses to exit the program (option 5)
while (option != 5) {

    // Print the option menu
    cout << "Here are the options for this program: " << "\n"
         << "[1] - Insert a new key value." << "\n"
         << "[2] - Search for a key." << "\n"
         << "[3] - Output path of tree." << "\n"
         << "[4] - Generate DOT file for visualization." << "\n"
         << "[5] - Exit the program." << "\n"
         << "\n" << "Which option would you like to choose? Please enter the number:";

    // User inputs option
    cin >> option;

    // Option 1 - Insert a new value into the B-Tree
    if (option == 1){} 
    
     // Option 2 - Search for a value in the B-Tree
    else if (option == 2){} 

     // Option 3 - Output the path of the B-Tree
    else if (option == 3){}

    // Option 4 - Generate a DOT file for visualization of the B-Tree
    else if (option == 4){}
    
    // Option 5 - exits program 
    else if (option == 5){
   
    // Output if user does not enter an integer 1-7
        else { invalid option} 
 </p>
