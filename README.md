<h1> CSC212 DSA Project B-Tree </h1>

<h4> Team Members: Grant Houatchanthara , Maxwell Krusz, Amir Rahmat, Eason Chen </h4>


<h3> Specifications </h3>
limit = 2

Implement the Data Structure (using classes)

ensure at least insert & serach methods are correct

search must also return/print the count

generate a DOT file for visualization

Store the words of an input text file

for the word (node) in the tree, a count with the number of repeats must also be store


<h4> What is a B-tree ? </h4>

<p size = 8> A B-tree is a self-balancing search tree data structure that is commonly used in databases and file systems to store large amounts of data. It is designed to keep the number of disk reads to a minimum by storing more data in each node than a binary search tree, which reduces the number of levels needed to reach a leaf node.

In a B-tree, each node contains multiple keys and pointers to its child nodes, and the number of keys per node is kept within a certain range. A B-tree of order m satisfies the following properties:

Every node has at most m children.
Every non-leaf node (except root) has at least ⌈m/2⌉ children.
The root has at least two children if it is not a leaf node.
A non-leaf node with k children contains k-1 keys.
All leaves appear in the same level.
When a node becomes full (i.e., contains m keys), it is split into two nodes, and the median key is promoted to its parent node. This splitting operation can propagate up the tree, potentially causing the root to split and a new root to be created.

B-trees are efficient for large datasets because they have a low depth and minimize disk reads. They are commonly used in file systems, databases, and operating systems where fast access to data is critical. </p>
