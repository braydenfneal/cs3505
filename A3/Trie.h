/**
 * Brayden Neal
 * CS 3505
*/
#ifndef TRIE_H
#define TRIE_H
#include <iostream>
#include "Node.h"
#include <vector>

/**
 * This is a the header class for the Trie.
*/
class Trie
{
public:
    Node* rootNode;
    
    Trie();
    
    //Destructor
    ~Trie();

    //Copy Constructor
    Trie(const Trie& other);

    //Assignment Operator
    Trie& operator=(Trie other);

    void addAWord(std::string word);

    bool isAWord(std::string word);

    std::vector<std::string> allWordsBeginningWithPrefix(std::string prefix);

    void allWords(std::vector<std::string> *words, Node *current, std::string currWord);

};
#endif