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
Dictionary* createDictionary();
void freeDictionary(Dictionary* dict);
int getHeight(Node* node);
int getBalance(Node* node);
Node* rightRotate(Node* y);
Node* leftRotate(Node* x);
Node* insertNode(Node* node, char* word);
int insertWord(Dictionary* dict, char* word);
Node* findFirstPrefix(Node* root, const char* prefix);
void collectWithPrefix(Node* node, const char* prefix, char** results, int* count, int maxResults);
char** autocomplete(Dictionary* dict, const char* prefix, int* count);
void printInOrder(Node* root);
int loadVocabulary(Dictionary* dict, char** wordList, int wordCount);

#endif /* AVL_DICTIONARY_H */