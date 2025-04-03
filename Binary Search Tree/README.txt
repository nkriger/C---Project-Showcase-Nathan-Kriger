PROJECT GOALS

Write a binary search tree class (called BST) that is a tree of C++ strings. A binary search tree (BST), is a binary tree (two children) where for every node in the tree, all the values in the node's left subtree are less than the node's value and all the values in the node's right subtree are greater than the node's value.


Required functions to implement
-------------------------------------------------------------------------------------------------------------------------------------------
Command	Argument	Action (see below for output formatting)	Potential Error (see below for message)
-------------------------------------------------------------------------------------------------------------------------------------------

echo	string	Write the string to standard output. Do not insert into tree. Used for commenting tests. Has nothing to do with the tree.	none
-------------------------------------------------------------------------------------------------------------------------------------------

insert	string	Insert the given string into the binary search tree. The tree must maintain the BST property after insert.	Print error if string already in tree.
-------------------------------------------------------------------------------------------------------------------------------------------

size	none	Print the number of elements (also number of nodes) in the tree.	none (size of 0 if tree is empty)
-------------------------------------------------------------------------------------------------------------------------------------------

find	string	Print if the given string is or is not in the tree (both messages to stdout)	none
-------------------------------------------------------------------------------------------------------------------------------------------

print	none	Use a depth-first traversal (DFT) to print all elements in the tree. When you use an inorder DFT, the values will be printed in ascending order (for strings, the values will be in alphabetical order)	none (empty brackets if tree is empty)
-------------------------------------------------------------------------------------------------------------------------------------------

breadth	none	Use a breadth-first traversal (BFT) to print all elements in the tree. This prints one level of the tree at a time (left to right within a given level)	none (empty brackets if tree is empty)
-------------------------------------------------------------------------------------------------------------------------------------------

distance	none	Print the average distance nodes are from the root. The root's distance is 0. The root's children are distance == 1, the root's grandchildren are distance == 2, and so on. Calculate the distance for ALL nodes and then take the average.	none (0 distance if tree contains zero or one nodes)
-------------------------------------------------------------------------------------------------------------------------------------------

balanced	none	Print if the tree is balanced or not balanced (this type of balanced is called "height-balanced".	none (considered balanced if tree is empty)
-------------------------------------------------------------------------------------------------------------------------------------------

rebalance	none	Modify the tree so it is balanced.	none
-------------------------------------------------------------------------------------------------------------------------------------------


Core goal of the project was learning Binary Search tree and best practices for them.