#include <avl_dictionary.h>
#include "utils.h"

////height
////max
////getbalance
////createnode
// !rightrotate
// !leftrotate
// !insertNode

// retrive the height of a node. handle null nodes as well
static int height(Node* node){
    if (!node) return 0;
    return node->height;
}

// this simply gets the max between two integers
static int max(int a, int b){
    return (a > b) ? a : b;
}

// for calculating the BF (balancing factor of a node)
static int getBalance(Node* node){
    if (!node) return 0;
    return height(node->left) - height(node->right);
}

//this function handles the creation of a new Node 
static Node* createNode(const char* word){
    Node* node = (Node*)malloc(sizeof(Node));

    node->word = strdup(word); 
    // ! there is  a need to explain the use of strdup above: why not to just make node->word equal to word? 
    
    node->left = node->right = NULL;
    node->height = 1;
    // ! why i choosed to use 1 as height?

    return node;
}


// * to do
static Node* rightRotate(Node* node) {
    
}
// * to do
static Node* leftRotate(Node* node) {

}


