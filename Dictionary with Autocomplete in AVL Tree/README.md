# Dictionary with Autocomplete in AVL Tree

## Overview
This project implements a dictionary with autocomplete functionality using a self-balancing AVL tree data structure. The implementation ensures efficient searching, insertion, and retrieval operations with O(log n) complexity. Users can query words by entering prefixes, and the system returns all matching entries in alphabetical order.

## Features
- Self-balancing AVL tree implementation for efficient dictionary operations
- Case-insensitive prefix search with autocomplete suggestions
- Memory-efficient data structure with proper cleanup
- Support for loading dictionary words from a file
- Interactive command-line interface for querying
- Fast lookup with logarithmic time complexity

## Project Structure
```
Dictionary with Autocomplete in AVL Tree/
├── data/
│   └── words.txt          # Dictionary word list
├── include/
│   ├── avl_dictionary.h   # AVL tree implementation header
│   ├── memory_utils.h     # Memory management utilities
│   └── utils.h            # General utility functions
├── src/
│   ├── avl_dictionary.c   # AVL tree implementation
│   ├── main.c             # Main program entry point
│   ├── memory_utils.c     # Memory management functions
│   └── utils.c            # Utility functions implementation
├── bin/                   # Compiled binaries
├── obj/                   # Object files
├── Makefile               # Build configuration
└── README.md              # This file
```

## Requirements
- C compiler (GCC recommended)
- Standard C libraries

## Compilation

### Using Make (recommended)
```bash
make
```

### Without Make (manual compilation)
```bash
mkdir -p bin
gcc -Wall -g -I./include ./src/avl_dictionary.c ./src/main.c ./src/memory_utils.c ./src/utils.c -o ./bin/dictionary_avl
```

## Running the Application
After compilation, run the program:

```bash
./bin/dictionary_avl
```

## Usage
1. The program loads a dictionary of words from words.txt
2. Enter a prefix to search for words
3. The program displays all dictionary words that start with your prefix
4. To exit, type `exit` or use Ctrl+D

## Example

```
Dictionary loaded successfully with 10000 words.
Enter a prefix to search for (or 'exit' to quit): ap
Suggestions starting with 'ap':
1. apacibilities
2. apanaging
3. aparejo
4. aparithmesis
5. apart
6. apartment
7. apathaton
8. apathetically
...

Enter a prefix to search for (or 'exit' to quit): exit
Memory freed successfully
```

## Implementation Details
- The AVL tree maintains balance after each insertion by performing rotations
- Search operations traverse the tree efficiently in O(log n) time
- Autocomplete collects all words with matching prefixes through a partial traversal of the tree
- Memory is dynamically allocated for all dictionary entries and properly freed when exiting

## Troubleshooting
- If you encounter warnings about unused static functions, these can be safely ignored as they are internal helper functions
- For better performance with very large dictionaries, consider increasing your system's stack size

## Author
- Lucas Gontijo de Moraes

## License
This project is provided as-is under the MIT License. Feel free to use and modify as needed.