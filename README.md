# C++ Hash Table Spell Checker

![Language](https://img.shields.io/badge/Language-C++-blue)
![Data Structure](https://img.shields.io/badge/Data%20Structure-Hash%20Table-green)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

---

A command-line **spell checker implemented in C++** using a **hash table with separate chaining**.

The program loads words from a dictionary, checks whether user-entered words exist in the dictionary, and suggests similar words when a spelling mistake is detected.  
This project demonstrates hashing, linked lists, file I/O, and simple string-similarity logic.

---

## Table of contents

- [Features](#features)  
- [Project structure](#project-structure)  
- [How it works](#how-it-works)  
- [Compile & Run](#compile--run)  
- [Example session](#example-session)  
- [Functions implemented](#functions-implemented)  
- [Future improvements](#future-improvements)  
- [Author & License](#author--license)

---

## Features

- Fast dictionary lookup using a **hash table**  
- **Separate chaining** (linked lists) to handle collisions  
- Case-insensitive word checking  
- Simple **word suggestion** system for misspelled words  
- Loads dictionary from a text file (`dictionary.txt`)  
- Manual memory cleanup (`unload()`)

---

## Project structure
cpp-hash-table-spell-checker
```
├── main.cpp # Program entry point
├── dictionary.cpp # Dictionary loading, lookup, suggestions
├── dictionary.h # Structures & function declarations
├── dictionary.txt # Word list used as dictionary
├── sample_input.txt # Example input for testing
└── README.md
```

---

## How it works

1. `load("dictionary.txt")` reads words one-by-one and inserts them into the hash table.  
2. `hashWord()` (djb2) computes an index: `index = hash % N`.  
3. Each bucket is a linked list (separate chaining) — new words are inserted at the head.  
4. When a user types a word, `check()` lowercases and searches the linked list at the hashed index.  
5. If not found, `suggest()` scans nearby buckets (or whole table) and prints similar words found by `isSimilar()`.

---

## Compile & Run

Compile:

```
g++ main.cpp dictionary.cpp -o speller
```
Run:
```
./speller
```
---

## Example session
```
Spell Checker Ready
Type words to check (type 'exit' to quit)

helo
Misspelled word: helo
Did you mean: hello help hero

cat
cat is correct

exit
```
---

## Functions implemented
unsigned int hashWord(const string& word); — djb2 hash, returns index.

bool load(const string& dictionary); — read file and populate hash table.

bool check(string word); — return true if word exists.

unsigned int size(); — number of words loaded.

bool unload(); — free memory.

bool isSimilar(const string& a, const string& b); — simple similarity (len diff ≤1 and ≤1 mismatch).

void suggest(const string& word); — print up to 3 suggestions.

---

## Future improvements

Use Levenshtein (edit) distance for better suggestions.

Replace suggestion scanning with a Trie for faster suggestions.

Add example output screenshot and demo video link.

Add a .gitignore and small LICENSE (MIT or similar).

---

## Author

Jaanvi Vohra
