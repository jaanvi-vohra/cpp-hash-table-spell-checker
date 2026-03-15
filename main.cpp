#include "dictionary.h"
#include <iostream>
using namespace std;

int main()
{
    if (!load("dictionary.txt"))
    {
        cout << "Error loading dictionary\n";
        return 1;
    }

    cout << "Spell Checker Ready\n";
    cout << "Type words to check (type 'exit' to quit)\n";

    string word;

    while (cin >> word)
    {
        if (word == "exit")
            break;

        if (!check(word))
        {
            cout << "Misspelled word: " << word << endl;
            suggest(word);
        }
        else
        {
            cout << word << " is correct\n";
        }
    }

    unload();
}
