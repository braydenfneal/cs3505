/**
 * Brayden Neal
 * CS 3505
*/
#include <fstream>
#include <iostream>
#include <string>
#include "Trie.h"
using namespace std;

/**
 * This is my tester class, that takes in two file arguments, and tests my Trie methods based on them.
*/
int main(int argc, char **args)
{
    Trie myTrie;

    string word;
    string query;

    ifstream wordFile(args[1]);
    ifstream queryFile;

    // Check to see if there is a wrong amount of aguments
    if (argc != 3)
    {
        cout << "Incorrect amount of Arguments" << endl;
        return 0;
    }

    // Add all of the words from file to my Trie
    if (wordFile.is_open())
    {
        while (getline(wordFile, word))
        {
            myTrie.addAWord(word);
        }
        wordFile.close();
    }
    // If something wrong with File, display message
    else
    {
        cout << "File 1 Does Not Exist" << endl;
    }

    queryFile.open(args[2]);
    if (queryFile.is_open())
    {
        while (getline(queryFile, query))
        {
            bool result = myTrie.isAWord(query);

            if (result == true)
            {
                cout << "Tested Text: " << query << '\n'
                     << "Found" << endl;

            }
            else
            {
                cout << "Tested Text: " << query << '\n'
                     << "Not Found" << endl;
            }
            vector<string> beginWithPrefix = myTrie.allWordsBeginningWithPrefix(query);

            for (string word : beginWithPrefix)
            {
                cout << word << endl;
            }
            cout << endl;    
        }
        queryFile.close();
    }
    else
        cout << "Querie File Does Not Exist";

    Trie one;
    one.addAWord("test");
    Trie two(one);

    if (two.isAWord("test"))
        cout << "Copy Constructor Works!" << endl;
    else
        cout<< "Copy Constructor Doesn't Work :(" << endl;
}