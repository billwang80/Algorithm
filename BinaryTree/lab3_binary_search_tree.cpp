#include <iostream>
#include "lab3_binary_search_tree.hpp"
#include <queue>

using namespace std;

// PURPOSE: Default/empty constructor
BinarySearchTree::BinarySearchTree() {
    root = NULL;
    size = 0;
}

// PURPOSE: Explicit destructor of the class BinarySearchTree
BinarySearchTree::~BinarySearchTree() {
    while(root)
        remove(*root);
}

// PURPOSE: Returns the number of nodes in the tree
unsigned int BinarySearchTree::get_size() const {
	return size;
}

// PURPOSE: Returns the maximum value of a node in the tree
// if the tree is empty, it returns (-1, "N/A")
// finished
BinarySearchTree::TaskItem BinarySearchTree::max() const {
	if(size == 0)
        return BinarySearchTree::TaskItem(-1, "N/A");

	TaskItem* current = root;
	while(current -> right)
    {
        current = current -> right;
    }
    return *current;
}

// PURPOSE: Returns the minimum value of a node in the tree
// if the tree is empty, it returns (-1, "N/A")
BinarySearchTree::TaskItem BinarySearchTree::min() const {
	return BinarySearchTree::TaskItem(-1, "N/A");
}

// PURPOSE: Returns the tree height
unsigned int BinarySearchTree::height() const {
	if(size == 0)
        return 0;

    // setting up height variable and queue
    int height = 0;
    queue<TaskItem*> q;
    q.push(root);

    // iterate until the height is returned
    while(true)
    {
        // the number of nodes in the queue
        int nodesLeft = q.size();
        // once all nodes have been traversed, height is returned
        if(nodesLeft == 0)
            return height;

        // increment height each time
        height++;
        // iterate until no more nodes on the level
        // push the left and right and pop the current nodes
        while(nodesLeft > 0)
        {
            if(q.front() -> left)
                q.push(q.front() -> left);
            if(q.front() -> right)
                q.push(q.front() -> right);
            q.pop();
            nodesLeft--;
        }
    }
}

// PURPOSE: Prints the contents of the tree; format not specified
void BinarySearchTree::print() const {
}

// PURPOSE: Returns true if a node with the value val exists in the tree
// otherwise, returns false
bool BinarySearchTree::exists( BinarySearchTree::TaskItem val ) const {
	return false;
}

// PURPOSE: Optional helper function that returns a pointer to the root node
BinarySearchTree::TaskItem* BinarySearchTree::get_root_node() {
    return root;
}

// PURPOSE: Optional helper function that returns the root node pointer address
BinarySearchTree::TaskItem** BinarySearchTree::get_root_node_address() {
    return &root;
}

// PURPOSE: Optional helper function that gets the maximum depth for a given node
int BinarySearchTree::get_node_depth( BinarySearchTree::TaskItem* n ) const {
	if(size == 0)
        return 0;

    int depth;
    queue<TaskItem*> q;
    q.push(root);

    while(true)
    {
        int nodesLeft = q.size();

        if(nodesLeft == 0)
            return depth;

        depth++;

        while(nodesLeft > 0)
        {
            if(q.front() -> left)
                q.push(q.front() -> left);
            if(q.front() -> right)
                q.push(q.front() -> right);
            q.pop();
            nodesLeft--;
        }
    }
}

// PURPOSE: Inserts the value val into the tree if it is unique
// returns true if successful; returns false if val already exists
bool BinarySearchTree::insert( BinarySearchTree::TaskItem val ) {
    return false;
}

// PURPOSE: Removes the node with the value val from the tree
// returns true if successful; returns false otherwise
bool BinarySearchTree::remove( BinarySearchTree::TaskItem val ) {
    TaskItem* current = root;
    TaskItem* preCurrent;
    TaskItem* valPointer = &val;
    while((current -> priority != valPointer -> priority) && (current -> right && valPointer -> priority > current -> priority) || (current -> left && valPointer -> priority < current -> priority))
    {
        if(valPointer -> priority > current -> priority)
            current = current -> right;
        else if(valPointer -> priority > current -> priority)
            current = current -> left;
    }

    if(current -> priority != valPointer -> priority)
    {
        return false;
    }

    if(current -> left && current -> right)
    {
        TaskItem* temp = current;
        if(temp -> left)
        {
            temp = temp -> left;
            while(temp -> right -> right)
                temp = temp -> right;
        }

        // swap them
        // temp -> right is the leaf node
        TaskItem* leaf = temp;
        if(temp -> right)
            leaf = temp -> right;


    }
}
