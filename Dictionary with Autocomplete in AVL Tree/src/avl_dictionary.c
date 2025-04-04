#include "avl_dictionary.h"
#include "utils.h"

////height
////max
////getbalance
////createnode
//// rightrotate
//// leftrotate
//// insertNode
//! validade word

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



static Node* rightRotate(Node* node) {
    if (!node || !node->left) return node;

    Node* Lchild = node->left;
    Node* Rsubtree_of_Lchild = Lchild->right;

    Lchild->right = node;
    node->left = Rsubtree_of_Lchild;

    node->height = 1 + max(height(node->left), height(node->right));
    Lchild->height = 1 + max(height(Lchild->left), height(Lchild->right));

    return Lchild;
}


static Node* leftRotate(Node* node) {
    if (!node || !node->right) return node;

    Node* Rchild = node->right;
    Node* Lsubtree_of_Rchild = Rchild->left;

    Rchild->left = node;
    node->right = Lsubtree_of_Rchild;

    node->height = 1 + max(height(node->left), height(node->right));
    Rchild->height = 1 + max(height(Rchild->left), height(Rchild->right));

    return Rchild;
}


Node* insertNode(Node* node, const char* word){
    // base case, since this is a recursive approuch
    if (!node) return createNode(word);
    //?falls here

    //! compare banana and cherry ok 
    //? now it compares banana with orange, and gets comparasion > 0
    //? compare again (cherry with orange), and gets comparasion > 0
    int comparasion = strcmp(word, node->word);
    /*  
            the strcmp() func. above takes two string arguments, compares the two strings in lexicographical order, and then returns a integer value:
        •	negative -> if str1 comes before str2 in lexicographical order.
        •	zero -> if str1 and str2 are equal.
        •	positive -> if f str1 comes after str2.
    */
            
    //standard bst insert
    if (comparasion > 0){
        node->right = insertNode(node->right, word); //? so it falls here / falls here again
    } 
    else if (comparasion < 0){
        node->left = insertNode(node->left, word);
    } 
    else {
        return node;
    }
    // ? calculate banana height (1+2) = 3
    node->height = 1 + max(height(node->left), height(node->right)); //! banana height was 1, now is 2 (1+1)

    int balance = getBalance(node); //! bf for banana -> -1 / bf for cherry is / banna height = 0-2 =-2
    // 4. If unbalanced, handle the four cases:
    
   
    /* 
        argument explanation for LL case: 
        •  bf is greater than 1 ? (meaning that the node has at least a left imbalance), but it can also be a LR at this point, so need to check the condition bellow
        •  strcmp(LAST_INSERTED_WORD, LEFT_CHILD_WORD) is less than 0? (it confirms that node has a leftChild that has a left child too) so, it is a left imbalance for sure
    */
    // Left Left Case (LEFT IMBALANCE)
    if (balance > 1 && strcmp(word, node->left->word) < 0)
        return rightRotate(node);
    
    // Right Right Case (RIGHT IMBALANCE) 
    if (balance < -1 && strcmp(word, node->right->word) > 0) //falls here compare orange with cherry and gets +1 
        return leftRotate(node);
    
   
    /* 
        argument explanation for LR case:
        •  bf is greater than 1 ? (meaning that the node has at least a left imbalance)
        •   strcmp(LAST_INSERTED_WORD, LEFT_CHILD_WORD) is greater than 0? meaning that the node has a left child that has a right child, so: LR case for sure

    */
    // Left Right Case
    if (balance > 1 && strcmp(word, node->left->word) > 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    // Right Left Case
    if (balance < -1 && strcmp(word, node->right->word) < 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // ! so it just returns node
    return node;

}

static Node* findPrefixSubtree(Node* root, const char* prefix) {
    if (!root) return NULL;
    
    int cmp = strncasecmp(prefix, root->word, strlen(prefix));
    
    if (cmp == 0) {
        // Current node starts with prefix - this is our subtree root
        return root;
    } else if (cmp < 0) {
        // Prefix is lexicographically smaller, go left
        return findPrefixSubtree(root->left, prefix);
    } else {
        // Prefix is lexicographically larger, go right
        return findPrefixSubtree(root->right, prefix);
    }
}

// Collect words from a subtree that match the prefix
static void collectMatchingWords(Node* node, const char* prefix, char** results, int* count, int maxResults) {
    if (!node || *count >= maxResults) return;
    
    // Check left subtree (smaller words)
    collectMatchingWords(node->left, prefix, results, count, maxResults);
    
    // Check current node
    if (startsWith(node->word, prefix)) {
        results[*count] = strdup(node->word);
        (*count)++;
    } else if (strcmp(node->word, prefix) > 0 && !startsWith(prefix, node->word)) {
        // If current word is greater than prefix but doesn't share the prefix,
        // we don't need to check right subtree if we're looking for exact prefix
        return;
    }
    
    // Check right subtree (larger words)
    if (*count < maxResults) {
        collectMatchingWords(node->right, prefix, results, count, maxResults);
    }
}

char** searchByPrefix(Node* root, const char* prefix, int* resultCount, int maxResults) {
    if (!root || !prefix) {
        *resultCount = 0;
        return NULL;
    }
    
    // Allocate memory for results
    char** results = (char**)malloc(maxResults * sizeof(char*));
    if (!results) {
        *resultCount = 0;
        return NULL;
    }
    
    // Initialize count
    *resultCount = 0;
    
    // Find the subtree that might contain our prefix
    Node* prefixSubtree = findPrefixSubtree(root, prefix);
    
    // Collect matching words from that subtree
    collectMatchingWords(prefixSubtree, prefix, results, resultCount, maxResults);
    
    return results;
}
