// LUCAS GONTIJO DE MORAES_202403082

#include "avl_dictionary.h"
#include "utils.h"
#include "memory_utils.h"

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}


int main() {
    // Start with empty tree
    Node* root = loadDictionaryFromFile("words.txt");
    
    printf("Dictionary loaded successfully!\n");

    int treeSize = countNodes(root);
    printf("Tree contains %d nodes\n", treeSize);

    // Add this to the main() function after loading the dictionary

    
    char prefix[100];// Interactive prefix search (limited to 100 chars, what i believe to be a 'good' amount)
    
    int maxResults = 10000; // i initially set up this var to 10k to be in accordance with 'RNF2 - Escalabilidade' though when this is a lower number, lower memory space is reserved the results variable  

    while (1) {
        printf("\nEnter a prefix to search (or 'exit' to quit): ");
    
        //i used fgets instead of scanf to properly handle empty inputs
        char input[100];
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input. Please try again.\n");
            continue;
        }
        
        // Remove newline character if present
        size_t len = strlen(input);
        if (len > 0 && input[len-1] == '\n') {
            input[len-1] = '\0';
            len--;
        }

        // Trim leading and trailing whitespace
        char *trimmed = input;
        while (*trimmed && isspace((unsigned char)*trimmed)) {
            trimmed++;
        }

        // Check if the trimmed string is empty
        if (*trimmed == '\0') {
            printf("Error: Empty input is not allowed. Please enter a valid prefix.\n");
            continue;
        }
        
        // Copy to prefix variable
        strcpy(prefix, strlwr(input));
        // i used strlwr function that i created in utils file to get input string to lower case
        
        // Check for exit command
        if (strcasecmp(prefix, "exit") == 0) { 
            break;
        }
        
        // Optional: warning for short prefixes (since i am mocking this with 10k words, short prefixes may result in many results)
        // if (len < 2) {
        //     printf("Warning: Very short prefixes may return too many results.\n");
        // }

        int resultCount = 0;
        
        char** results = searchByPrefix(root, prefix, &resultCount, maxResults);
        
        // Display results
        if (resultCount == 0) {
            printf("No suggestions find with prefix '%s'\n", prefix);
        } else {
            printf("Suggestions starting with '%s':\n", prefix);
            for (int i = 0; i < resultCount; i++) {
                printf("%d. %s\n", i+1, results[i]);
                free(results[i]);  // i am freeing the memory here because i alredy am iterating over results count to print each one, so why not
            }
            free(results);  // Libera o array de ponteiros
        }
    }
    
    freeTree(root);
    printf("Memory freed successfully\n");
    
    return 0;
}