#ifndef AVL_DICTIONARY_H
#define AVL_DICTIONARY_H

#include <stdlib.h>
#include <string.h>


// Node structure for AVL tree
typedef struct Node {
    char* word;
    int height;
    struct Node* left;
    struct Node* right;
} Node;

// Dictionary structure
typedef struct {
    Node* root;
    int size;
} Dictionary;

// Function prototypes
// Dictionary* createDictionary();
// void freeDictionary(Dictionary* dict);
// In avl_dictionary.h
void collectWordsWithPrefix(Node* root, const char* prefix, char** results, int* count, int maxResults);
char** searchByPrefix(Node* root, const char* prefix, int* resultCount, int maxResults);
int getHeight(Node* node);
int getBalance(Node* node);
Node* rightRotate(Node* y);
Node* leftRotate(Node* x);
Node* insertNode(Node* node, const char* word);
// In avl_dictionary.h
void freeAVLTree(Node* root);
void freeSearchResults(char** results, int count);
// int insertWord(Dictionary* dict, char* word);
// Node* findFirstPrefix(Node* root, const char* prefix);
// void collectWithPrefix(Node* node, const char* prefix, char** results, int* count, int maxResults);
// char** autocomplete(Dictionary* dict, const char* prefix, int* count);
// void printInOrder(Node* root);
// int loadVocabulary(Dictionary* dict, char** wordList, int wordCount);

#endif /* AVL_DICTIONARY_H */