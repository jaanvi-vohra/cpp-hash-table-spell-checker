C++ Hash Table Spell Checker

A command-line spell checker implemented in C++ using a hash table with separate chaining.

The program loads words from a dictionary, checks whether user-entered words exist in the dictionary, and suggests similar words when a spelling mistake is detected.

This project demonstrates core data structures and algorithm concepts, including hashing, linked lists, and efficient word lookup.

Demo

Example program interaction:

Spell Checker Ready
Type words to check (type 'exit' to quit)

helo
Misspelled word: helo
Did you mean: hello help hero

cat
Correct word: cat
Features

Fast dictionary lookup using a hash table

Separate chaining using linked lists to resolve collisions

Case-insensitive word checking

Word suggestion system for misspelled words

Dictionary loaded from a text file

Modular project structure

Dynamic memory allocation and cleanup

Project Structure
cpp-hash-table-spell-checker
│
├── main.cpp
├── dictionary.cpp
├── dictionary.h
├── dictionary.txt
├── sample_input.txt
└── README.md
File Description
File	Description
main.cpp	Entry point of the program
dictionary.cpp	Implements dictionary loading and lookup
dictionary.h	Contains structures and function declarations
dictionary.txt	Word list used as dictionary
sample_input.txt	Example input words
README.md	Project documentation
Data Structures Used
Hash Table

A hash table is used to store dictionary words for fast lookup.

index → linked list of words

Example:

table[42] → apple → angle → apart
Linked Lists (Separate Chaining)

When multiple words map to the same hash index, they are stored in a linked list.

table[index] → word1 → word2 → word3

This technique is called separate chaining.

Hash Function

The project uses the djb2 hash function, a well-known hashing algorithm for strings.

Example logic:

hash = ((hash << 5) + hash) + character

Properties:

Fast computation

Simple implementation

Good distribution for text data

Compilation

Compile the program using g++:

g++ main.cpp dictionary.cpp -o speller
Running the Program

Run the executable:

./speller

You will see:

Spell Checker Ready
Type words to check (type 'exit' to quit)
Example Input
helo
wrld
cat
exit

Example Output:

Misspelled word: helo
Did you mean: hello help hero

Misspelled word: wrld
Did you mean: world

Correct word: cat
Functions Implemented
Function	Purpose
hashWord()	Computes hash index for a word
load()	Loads dictionary into hash table
check()	Checks if a word exists
size()	Returns number of words in dictionary
unload()	Frees allocated memory
isSimilar()	Checks if two words are similar
suggest()	Suggests possible corrections
Concepts Demonstrated

This project applies several fundamental computer science concepts:

Hash tables

Collision handling

Linked lists

File I/O

Dynamic memory management

Modular C++ programming

Possible Improvements

Future enhancements could include:

Levenshtein distance for better suggestions

Support for larger dictionaries

Performance benchmarking

GUI-based spell checker

Multi-language dictionary support

Author

Jaanvi Vohra
