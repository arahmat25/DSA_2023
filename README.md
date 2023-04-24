<h1> CSC212 DSA Project B-Tree </h1>

<h3> Team Members (Group 7): Grant Houatchanthara , Maxwell Krusz, Amir Rahmat, Eason Chen </h3>

<h2> What is a B-tree ? </h2>

<p size = 5> A B-tree is a self-balancing search tree data structure that is commonly used in databases and file systems to store large amounts of data. It is designed to keep the number of disk reads to a minimum by storing more data in each node rather than a binary search tree, which reduces the number of levels needed to reach a leaf node. In a B-tree, each node contains multiple keys and pointers to its child nodes, and the number of keys per node is kept within a certain range. A B-tree of order t satisfies the following properties:
 <br>                            </br>
<br>-Every node has at most m children. </br>
<br>-Every non-leaf node (except root) has at least ⌈m/2⌉ children.</br>
<br>-The root has at least two children if it is not a leaf node.</br>
<br>-A non-leaf node with k children contains m-1 keys.</br>
<br>-All leaves appear in the same level.</br>
<br>-When a node becomes full (i.e., contains max num keys), it is split into two nodes, and the median key is "promoted" to its parent node. This splitting operation can propagate up the tree, this can cause the root to split and a new root to be created recursivley. </br>
<br>                      </br>
B-trees are efficient for large datasets because they have a low depth and minimize disk reads. They are commonly used in file systems, databases, and operating systems where fast access to data on disk drives is critical. </p>

<h2> How to compile our code </h2>

<p size = 5>


 </p>
