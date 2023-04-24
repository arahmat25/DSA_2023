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
<br>- Click the drop down for the run configuration located in the top right your application.</br>
<br>- Click "Edit Configurations..."</br>
<br>- The only section that needs to be changed is the 'Program Arguments:' input box. This is where you input the text file you wish to run.</br>
<br>- Once the text file name is input, click "Apply" and then "OK"</br>
<br>- Here is a video demonstrating these steps: https://streamable.com/zni7vc</br>
<br>- The input text files must be located in the "cmake-build-debug" folder of the project.</br>
![image](https://user-images.githubusercontent.com/98424311/233893999-77cd04eb-348b-4adb-a802-d7ee21dd323d.png)
</p>

<h2> How to compile our code in Visual Studio Code </h2>
<p size = 5>
<br>- Make sure that all the files,(main.cpp, btree.cpp btree.h) plus the data file are in the same folder. </br>
<br>- Compile the main.cpp and the btree.cpp in your terminal. Ex: g++ main.cpp btree.cpp -o exec </br>
<br>- Run the executable with the data file name as the CLA. EX: ./exec "data.txt" </br>
 </p>
 
 <h2> Requirements for both compilers: </h2>
 <p size = 5>
<br>- The input text files for this program should be a list of integer numbers on a single line, each seperated by a single space. For example:</br>
<br> 3 6 9 -10 5 2 7 11 8 1 4</br>
 </p>
 
  <h2> Runtime Requirements: </h2>
 <p size = 5>
<br>- After compiling and running the code this message will be displayed in the terminal:</br>
<br> "What would you like the degree of this B-Tree to be? Input integer here:" </br>
<br>- The user should input an integer that is to be the degree their tree is to be organized by. After doing so, the user will be presented with this list of options:</br>
<br>![image](https://user-images.githubusercontent.com/98424311/234093497-e2f29f80-7d84-4a42-894e-c96165addee6.png)</br>
<br>- The user should then enter the integer that corresponds with the option they wish to choose. </br>
<br>- This functionality is the exact same for both IDEs. </br>
 </p>
 
 <h2> How to visualize DOT file </h2>
<p size = 5>
 <br>If the user picks option 4 at any point during the program runtime, the program will create a file named "dot_file.txt" and within that file it will output the code needed to visualize the BTree on a website that we have used for one of our labs. The "dot_file.txt" is saved in the same place the input files should be located, which is different for both IDEs, so refer to the sections above if you are not certain where the file has been created and placed. </br>
<br>Website used :  https://dreampuf.github.io/GraphvizOnline/#digraph%20G%20%7B%0D%0A%0D%0A%7D%0D%0A </br>
 </p>
 
 
 
<h2> Pseudo Code for BTree header file </h2>

    class BTreeNode:
        degree // degree of tree
        leaf // true when node is leaf, else false
        numKeys // number of keys in node
        keys // array of keys
        child_ptr // array of pointers to children

        constructor(degree, leaf) // node constructor
        insertNonFull(key) // insert a key into a node that is not filled
        printTree() // output the path
        printDot(temp, fname) // output dot visualization
        splitChild(i, y) // split a child node
        searchTree(key) // search for a key in a subtree

    class BTree:
        degree // degree of tree
        root // root pointer

        constructor(degree) // tree constructor
        printTree() // output path
        printDot() // output DOT visualization file
        insert(key) // main function to insert a new key in the B-Tree
        search(key) // function to search for a key in the tree
 
 <h2> Pseudo Code for BTree CPP file </h2>
 
       B-TreeInsert(Node root, int key):
          if root is null:
              // If the tree is empty, create a new root node with the key
              set root to createNewNode(key)
          else if root is full:
              // If the root is full, split it and create a new root
              set new_node to createNewNode()
              children[0] of new_node = root
              splitChild(0, root)
              if new_node.keys[0] < key:
                  // Determine which child to insert the key into
                  insertNonFull(children[1] of new_node, key)
              else:
                  insertNonFull(children[0] of new_node, key)
              root = new_node
          else:
              // If the root is not full, insert the key into the non-full root
              insertNonFull(root, key)

      insertNonFull(Node node, int key):
          if node is a leaf node:
              // If the node is a leaf, insert the key into the node
              find position i for key in node.keys
              shift keys[i] to keys[node.numKeys] one position to the right
              set keys[i] to key
              increment node.numKeys by 1
          else:
              // If the node is not a leaf, insert the key into the appropriate child
              find position i for key in node.keys
              if node.children[i] is full:
                  // If the child is full, split it and insert the key into the appropriate child
                  splitChild(i, node.children[i])
                  if node.keys[i] < key:
                      // Determine which child to insert the key into
                      increment i by 1
              insertNonFull(node.children[i], key)

      splitChild(int index, Node node):
          // Split a full child node of a B-Tree node
          create new_node
          set new_node as a child of node
          move keys and children of node at positions index+1 to node.numKeys one position to the right
          copy keys and children of node.children[index] to new_node
          update node.numKeys and new_node.numKeys

      createNewNode():
          // Create a new B-Tree node
          create a new node with initialized keys, children, and other properties
          return the new node


 
 
  <h2> Pseudo Code for MAIN CPP file </h2>

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
   
    // Output if user does not enter an integer 1-5
        else { invalid option} 
