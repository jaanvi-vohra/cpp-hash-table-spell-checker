#include "dictionary.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

vector<Node*> table(N , nullptr);
unsigned int word_count = 0;

// Hash function (djb2)
unsigned int hashword(const string& word)
{
    unsigned long hash = 5381;

    for (char c : word)
    {
        hash = ((hash << 5) + hash) + tolower(c);
    }

    return hash % N;
}

// Load dictionary into hash table
bool load(const string& dictionary)
{
    ifstream file(dictionary);

    if (!file.is_open())
        return false;

    string word;

    while (file >> word)
    {
        int index = hashword(word);

        Node* newNode = new Node;
        if (newNode == nullptr)
            return false;

        newNode->word = word;
        newNode->next = table[index];

        table[index] = newNode;

        word_count++;
    }

    file.close();
    return true;
}

// Check if word is in dictionary
bool check(string word)
{
    // Convert word to lowercase
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    int index = hashword(word);

    Node* cursor = table[index];

    while (cursor != nullptr)
    {
        if (cursor->word == word)
            return true;

        cursor = cursor->next;
    }

    return false;
}

// Return number of words in dictionary
unsigned int size()
{
    return word_count;
}


// Free memory
bool unload()
{
    for (int i = 0; i < N; i++)
    {
        Node* cursor = table[i];

        while (cursor != nullptr)
        {
            Node* temp = cursor;
            cursor = cursor->next;
            delete temp;
        }
    }

    return true;
}

bool isSimilar(const string& a, const string& b)
{
    int lenDiff = abs((int)a.length() - (int)b.length());

    if (lenDiff > 1)
        return false;

    int mismatches = 0;
    int len = min(a.length(), b.length());

    for (int i = 0; i < len; i++)
    {
        if (a[i] != b[i])
            mismatches++;
    }

    return mismatches <= 1;
}


// Suggest similar words by searching buckets near the hashed index
// instead of scanning the entire table for better performance
void suggest(const string& word)
{
    cout << "Did you mean: ";

    int suggestions = 0;
    int index = hashword(word);

    int range = 50;   // number of nearby buckets to search

    for (int i = max(0, index - range); i < min((int)N, index + range); i++)
    {
        Node* cursor = table[i];

        while (cursor != nullptr)
        {
            if (isSimilar(word, cursor->word))
            {
                cout << cursor->word << " ";
                suggestions++;

                if (suggestions == 3)
                {
                    cout << endl;
                    return;
                }
            }

            cursor = cursor->next;
        }
    }

    if (suggestions == 0)
        cout << "No suggestions";

    cout << endl;
}
