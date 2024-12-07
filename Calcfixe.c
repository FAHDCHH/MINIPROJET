//
// Created by FAHD on 24/11/2024.
//
#include "Calcfixe.h"


sommet main_stack = NULL;  // Initialize main_stack to NULL
sommet save_stack = NULL;  // Initialize save_stack to NULL
// Function to create a new node
sommet newNode(float data) {
    sommet node = (sommet)malloc(sizeof(Node)); // Allocate memory for the new node
    if (node == NULL) {
        printf("Node creation failure!!! Memory allocation failed\n");
        exit(EXIT_FAILURE); // Exit if memory allocation fails
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to check if the stack is empty
bool is_empty() {
    return (main_stack == NULL); // Stack is empty if the top pointer is NULL
}

// Function to push data onto the stack
void push(float data) {
    sommet node = newNode(data); // Create a new node
    node->next = main_stack;    // Link the new node to the current top
    main_stack = node;          // Update the top pointer
}

// Function to pop data from the stack
float pop() {
    if (is_empty()) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE); // Exit if pop is attempted on an empty stack
    }
    sommet temp = main_stack;      // Temporary pointer to the top node
    float poppedData = temp->data; // Retrieve data from the top node
    main_stack = temp->next;       // Update the top pointer to the next node
    free(temp);                    // Free the memory of the popped node
    return poppedData;             // Return the popped data
}

// Function to display the stack
void display() {
    if (is_empty()) {
        printf("Stack is empty\n");
        return;
    }
    sommet temp = main_stack; // Temporary pointer to traverse the stack
    printf("Stack contents:\n");
    while (temp != NULL) {
        printf("%.2f\n", temp->data); // Print data in the current node
        temp = temp->next;           // Move to the next node
    }
}

// Function to get the top element of the stack
float result() {
    if (is_empty()) {
        printf("Stack is empty\n");
         // Exit if the stack is empty
    }
    return main_stack->data; // Return the data at the top
}

// Function to delete the top node
void delete_node() {
    if (is_empty()) {
        printf("Stack is empty, nothing to delete\n");
        return; // No action if the stack is empty
    }
    sommet temp = main_stack; // Temporary pointer to the top node
    main_stack = temp->next;  // Update the top pointer to the next node
    free(temp);               // Free the memory of the removed node
}

// Function to delete all nodes in the stack
void delete_all() {
    while (!is_empty()) {
        delete_node(); // Repeatedly delete the top node until the stack is empty
    }
    printf("All nodes deleted, stack is now empty\n");
}

// Function to transfer from main_stack to save_stack
void sauvegarder() {
    if (is_empty()) {
        printf("main_stack is empty, nothing to save\n");
        return;
    }
    float value = pop(); // Pop the top value from main_stack
    sommet new_node = newNode(value); // Create a new node with the popped value
    new_node->next = save_stack; // Link it to the current save_stack
    save_stack = new_node; // Update the save_stack top
    printf("Saved value: %.2f\n", value);
}

// Function to transfer the top value from save_stack to main_stack
void rappeler() {
    if (save_stack == NULL) {
        printf("save_stack is empty, nothing to recall\n");
        return;
    }
    sommet temp = save_stack; // Pointer to the top node of save_stack
    float value = temp->data; // Get the value
    save_stack = temp->next; // Update save_stack top to the next node
    free(temp); // Free the popped node
    push(value); // Push the recalled value onto main_stack
    printf("Recalled value: %.2f\n", value);
}
float calculer_binop(char op, float a, float b) {
    switch(op) {
        case '+':
            return a + b;  // Addition
        case '-':
            return a - b;  // Subtraction
        case '*':
            return a * b;  // Multiplication
        case '/':
            if (b != 0) {
                return a / b;  // Division, check for division by zero
            } else {
                return nan("");  // Return NaN for division by zero
            }
        case '^':
            return pow(a, b);  // Power operation (a raised to the power of b)
        default:
            return nan("");  // Return NaN for an invalid operator
    }
}
float calculer_unop(char op, float a) {
    switch(op) {
        case 'N':  // NEG: Negation
            return -a;
        case 'A':  // VALABS: Absolute value
            return fabs(a);
        case 'S':  // SQRT: Square root
            if (a >= 0) {
                return sqrt(a);  // Square root, check for negative value
            } else {
                return nan("");  // Return NaN for negative values
            }
        case 'I':  // SIN: Sine
            return sin(a);  // Sine of a (in radians)
        case 'C':  // COS: Cosine
            return cos(a);  // Cosine of a (in radians)
        case 'T':  // TAN: Tangent
            return tan(a);  // Tangent of a (in radians)
        case 'L':  // LOG: Natural logarithm
            if (a > 0) {
                return log(a);  // Logarithm of a
            } else {
                return nan("");  // Return NaN for non-positive values
            }
        case 'E':  // EXP: Exponential
            return exp(a);  // Exponential function e^a
        default:
            return nan("");  // Return NaN for an invalid operator
    }
}