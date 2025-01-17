/**
 *
 * Brayden Neal
 * CS 3505
 *
 */
#include <iostream>
#include "Trie.h"
#include <string>
#include <vector>
#include <algorithm>

// Constructor
Trie ::Trie()
{
    rootNode = new Node();
};

// Destructor
Trie ::~Trie()
{
    delete rootNode;
}

// Copy Constructor
Trie ::Trie(const Trie &other)
{
    rootNode = nullptr;
    rootNode = new Node(*(other.rootNode));
}

// Assignment Operator
Trie &Trie ::operator=(Trie other)
{
    std::swap(rootNode, other.rootNode);
    return *this;
}

/**
 * The word passed into the method should be added to the Trie object. Duplicate adds should not change the Trie.
 * You may assume that the word is only made up of lower-case characters from a-z.
 */
void Trie::addAWord(std::string word)
{
    // Start at root of Trie
    Node *current = rootNode;

    // Iterate through all the letters
    for (char c : word)
    {
        int index = c - 'a';
        // If current Node's branch doesn't exist, add new Node there
        if (current->branches[index] == nullptr)
        {
            current->branches[index] = new Node();
        }

        // Goes to the next Node from where the letter's index is
        if (current->branches[index] != nullptr)
        {
            current = current->branches[index];
        }
    }
    // End of the loop means that that is the end of the loop, so the node at that point should be updated to say it is a word.
    current->isValidWord = true;
}

/**
 * The argument is a string. Any character in the string not made up of characters 'a'-'z' cause an immediate return of false.
 * If the word is found in the Trie, the method should return true, otherwise return false.  A Trie should report that an empty
 * string is not in the Trie.
 */
bool Trie ::isAWord(std::string word)
{
    Node *current = rootNode;
    // If the word is an empty string, return false
    if (word.length() < 1)
    {
        return false;
    }
    // Start from first letter, and iterate through Trie until you see if or if not the end node isWord
    for (char c : word)
    {
        int index = c - 'a';

        if (current->branches[index] != nullptr)
        {
            current = current->branches[index];
        }
        else
        {
            return false;
        }
    }
    // If at the end of the word, the current Node is said tobe a valid word, return true
    if (current->isValidWord == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Contains all the words in the Trie that begin with the passed in argument prefix string. Characters int he prefix string should be
 * tested to make sure they are only 'a'-'z'. If the prefix is a word, that should be included. An empty prefix should return all words
 * in the Trie.
 */
std::vector<std::string> Trie::allWordsBeginningWithPrefix(std::string prefix)
{
    std::vector<std::string> words;
    Node *current = rootNode;

    // Loops through all of the characters in prefix to get to the point in the trie where the prefix ends
    for (char c : prefix)
    {
        int index = c - 'a';
        if (current->branches[index] == nullptr)
        {
            return words;
        }
        else
        {
            current = current->branches[index];
        }
    }

    // Calls a recursive Method to get the rest of the words that start with the prefix
    allWords(&words, current, prefix);

    return words;
}

/**
 *  This is a recursive Method, used in the allWordsBeginningWithPrefix method. It recursivly searches through
 *  the Trie to find all the words that have the inputted Prefix.
 */
void Trie ::allWords(std::vector<std::string> *words, Node *current, std::string currWord)
{
    // Base case, if the word at current Node is valid, Adds to the list
    // It also checks if the word is already in the vector or not. If it is, it doesn't add it.
    if (current->isValidWord)
    {
        words->push_back(currWord);
    }
    
    // For loop is so it can search through the current Node's array to find other Nodes.
    for (int i = 0; i < 26; i++)
    {
        // Recursively search through every possible Node, in the rest of the trie to see if
        // a word contains the beginning input prefix.
        if (current->branches[i] != nullptr)
        {
            currWord = currWord + char(i + 'a');
            allWords(words, current->branches[i], currWord);
            // This is here because when we backtrack recursively, we need to make sure the current word is 
            // backtracking as well.
            currWord.pop_back();
        }
    }
}

