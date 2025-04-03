#include "avl_dictionary.h"
#include "utils.h"

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// In main after loading


// Simple traversal function to display the tree
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%s\n", root->word);
        inorderTraversal(root->right);
    }
}

void freeAVLTree(Node* root) {
    if (root == NULL) {
        return;
    }
    
    // Recursively free left and right subtrees (post-order traversal)
    freeAVLTree(root->left);
    freeAVLTree(root->right);
    
    // Free the word if it was dynamically allocated
    free(root->word);
    
    // Free the node itself
    free(root);
}

int main() {
    // Start with empty tree
    Node* root = loadDictionaryFromFile("words.txt");
    
    printf("Dictionary loaded successfully!\n");

    int treeSize = countNodes(root);
    printf("Tree contains %d nodes\n", treeSize);

    // Add this to the main() function after loading the dictionary

    
    char prefix[100];// Interactive prefix search (limited to 100 chars, what i believe to be a 'good' amount)
    int running = 1; //since it needs to have an interactive interface, i defined this variable running, for control purposes of when the user wants to use the "exit" word to exit or search an prefix
    
    int maxResults = 10000; // i initially set up this var to 10k to be in accordance with 'RNF2 - Escalabilidade' though when this is a lower number, lower memory space is reserved the results variable  

    while (running) {

        printf("\nEnter a prefix to search (or 'exit' to quit): ");
        scanf("%99s", prefix);
        
        // Check for exit command, base case for scaping the while loop
        if (strcasecmp(prefix, "exit") == 0) { 
            running = 0;
            continue;
        }
        
        // Search for words with prefix
        int resultCount = 0;
        
        char** results = searchByPrefix(root, prefix, &resultCount, maxResults);
        
        // Display results
        if (resultCount == 0) {
            printf("No words found with prefix '%s'\n", prefix);
        } else {
            printf("Words starting with '%s':\n", prefix);
            for (int i = 0; i < resultCount; i++) {
                printf("%d. %s\n", i+1, results[i]);
                free(results[i]);  // Libera cada string individual
            }
            free(results);  // Libera o array de ponteiros
        }
        
    }

    freeAVLTree(root);
    printf("Memory freed successfully\n");
    
    return 0;
}