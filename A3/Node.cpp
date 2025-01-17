/**
 * Brayden Neal
 * CS 3505
*/
#include <iostream>
#include "Node.h"

// Default Constructor that holds a fixed sized array of Nodes* and a wordEnd flag
Node ::Node()
{
    isValidWord = false;

    // All pointers in array should be filled with null ptrs
    for (int i = 0; i < 26; i++)
    {
        branches[i] = nullptr;
    }
}

// Deconstructor
Node ::~Node()
{
    for (int i = 0; i < 26; i++)
    {
        delete branches[i];
    }
}

// Copy Constructor
Node ::Node(const Node &other)
{
    for (int i = 0; i < 26; i++)
    {
        branches[i] = nullptr;
    }
    for (int i = 0; i < 26; i++)
    {
        if (other.branches[i])
        {
            branches[i] = new Node(*(other.branches[i]));
        }
    }
    isValidWord = other.isValidWord;
}

// Assignment Operator
Node &Node ::operator=(Node other)
{
    for (int i = 0; i < 26; i++)
    {
        std::swap(branches[i], other.branches[i]);
    }
    return *this;
}

