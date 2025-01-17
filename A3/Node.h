/**
 * Brayden Neal
 * CS 3505
*/
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

/**
 * This is the header class for a Node.
*/
class Node
{
public:
    Node();
    Node* branches[26];
    bool isValidWord;
    // Desctuctor
    ~Node();

    // Copy Constructor
    Node(const Node &other);

    // Assignment Operator
    Node &operator=(Node other);
};
#endif