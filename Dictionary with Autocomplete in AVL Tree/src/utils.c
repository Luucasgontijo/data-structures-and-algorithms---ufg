#include <stdio.h>
#include "utils.h"

// Check if a string starts with a prefix
// Check if a string starts with a prefix
int startsWith(const char* str, const char* prefix) {
    if (!str || !prefix) return 0;
    
    size_t prefixLen = strlen(prefix);
    size_t strLen = strlen(str);
    
    if (prefixLen > strLen) return 0;
    
    // Use strncasecmp to compare n characters with case insensitivity
    return strncasecmp(str, prefix, prefixLen) == 0;
}

Node* loadDictionaryFromFile(const char* filename) {
    int wordCount = 0;
    char filepath[512];
    
    // Construct the full path to the file in the /data directory
    snprintf(filepath, sizeof(filepath), "data/%s", filename);
    
    // Open the file for reading
    FILE* file = fopen(filepath, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filepath);
        return NULL;
    }
    
    Node* root = NULL;
    char buffer[1024]; // Buffer for reading lines
    
    // Read lines from the file
    while (fgets(buffer, sizeof(buffer), file)) {
        // Remove trailing newline if present
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        }
        
        // Skip empty lines
        if (strlen(buffer) > 0) {
            // This was missing! Insert word into the tree
            root = insertNode(root, buffer);
            wordCount++;
        }
    }
    
    fclose(file);
    printf("Loaded %d words from file\n", wordCount);
    
    return root;
}