//
// Created by FAHD on 24/11/2024.
//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#ifndef CALCFIXE_H
#define CALCFIXE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the node structure
typedef struct Node {
    float data;
    struct Node *next;
} Node;

typedef Node* sommet; // Pointer to Node (representing the top of the stack)

// Declare the global stack variables
extern sommet main_stack;  // The main operand stack
extern sommet save_stack;  // The saved operand stack

// Function declarations
sommet newNode(float data);    // Function to create a new node
bool is_empty();               // Function to check if the stack is empty
void push(float data);         // Function to push data onto the stack
void display();                // Function to display the stack contents
float pop();                   // Function to pop data from the stack
float result();                // Function to get the value at the top of the stack
void delete_node();            // Function to delete the top node
void delete_all();             // Function to delete all nodes
void rappeler();               // Function to recall the top value from save_stack to main_stack
void sauvegarder();
float calculer_binop(char op,float a , float b);// Function to save the top value from main_stack to save_stack
float calculer_unop(char op, float a);
#endif // CALCFIXE_H
