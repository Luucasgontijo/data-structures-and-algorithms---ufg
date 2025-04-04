# AVL Dictionary with Autocomplete

## Overview
This project implements a dictionary with autocomplete functionality using an AVL tree data structure. The AVL tree ensures efficient searching and insertion operations with O(log n) complexity. The autocomplete feature allows users to enter a prefix and receive suggestions of all words in the dictionary that start with that prefix.

## Features
- Self-balancing AVL tree implementation
- Case-insensitive prefix search
- Memory-efficient data structure
- Input validation with clear error messages
- Scalable to handle large dictionaries

## Project Structure
```
Dictionary with Autocomplete in AVL Tree
├── src
│   ├── main.c             # Main program entry point
│   └── avl_dictionary.c   # AVL tree implementation
├── include
│   └── avl_dictionary.h   # Header file for AVL dictionary
├── obj                    # Object files (created by make)
├── bin                    # Executable (created by make)
├── Makefile
└── README.md
```

## Building the Project

In order to build the project, i set up a MAKEFILE navigate to the project directory and run the following command:

```bash
make
```

This will compile the source files and create the executable in the `bin` directory.

## Running the Application
After building the project, run the application using:

```bash
./bin/dictionary_avl
```

## Usage
1. When prompted, enter a prefix to search for words
2. The program will display all words in the dictionary that start with the entered prefix (inorder)
3. Enter 'exit' to quit the program

## Input Handling
- Empty strings are rejected with an appropriate error message
- Very short prefixes can display a warning about potentially returning many results (since this is optional, i've commented the code responsable to do this, thought it works).
- The search is case-insensitive, so "App" will match "apple", "APPLE", etc.

## Memory Management
The program properly manages memory, freeing all allocated resources before termination.

## Team Members
- Lucas Gontijo de Moraes - 202403082

## License
This project is licensed under the MIT License. See the LICENSE file for more details.