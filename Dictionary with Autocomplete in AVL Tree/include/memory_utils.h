// memory_utils.h
#ifndef MEMORY_UTILS_H
#define MEMORY_UTILS_H

#include "avl_dictionary.h"  // needed for Node* type

void freeTree(Node* root);
static void freeNode(Node* node);
void freeSearchResults(char** results, int count);
#endif