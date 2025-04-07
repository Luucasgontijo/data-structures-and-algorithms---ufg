// memory_utils.c
#include <stdlib.h>
#include "memory_utils.h"

// Free a single node
static void freeNode(Node* node) {
    if (node) {
        free(node->word);
        free(node);
    }
}

// Free the entire tree recursively
void freeTree(Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        freeNode(root);
    }
}
