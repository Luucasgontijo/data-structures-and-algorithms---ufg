#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "utils.h"
#include "avl_dictionary.h"

char* strlwr(char* str);

int startsWith(const char* str, const char* prefix);
Node* loadDictionaryFromFile(const char* filename);

#endif // UTILS_H
