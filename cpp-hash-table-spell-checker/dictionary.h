#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>

using namespace std;

const int N = 50021;

struct Node
{
    string word;
    Node* next;
};

extern vector<Node*> table;

unsigned int hashword(const string& word);
bool load(const string& dictionary);
bool check(string word);
unsigned int size();
bool unload();
bool isSimilar(const string& a, const string& b);
void suggest(const string& word);

#endif
