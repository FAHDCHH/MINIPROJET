//
// Created by FAHD on 24/11/2024.
//
#include "Calcfixe.h"


sommet main_stack = NULL;
sommet save_stack = NULL;
// Fonction pour créer un nouveau nœud
sommet newNode(float data) {
    sommet node = (sommet)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Échec de la création du nœud!!! Allocation de mémoire échouée\n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Fonction pour vérifier si la pile est vide
bool is_empty() {
    return (main_stack == NULL);
}

// Fonction pour ajouter des données dans la pile
void push(float data) {
    sommet node = newNode(data);
    node->next = main_stack;
    main_stack = node;
}

// Fonction pour retirer des données de la pile
float pop() {
    if (is_empty()) {
        printf("Poussée vide\n");
        exit(EXIT_FAILURE);
    }
    sommet temp = main_stack;
    float poppedData = temp->data;
    main_stack = temp->next;
    free(temp);
    return poppedData;
}

// Fonction pour afficher le contenu de la pile
void display() {
    if (is_empty()) {
        printf("La pile est vide\n");
        return;
    }
    sommet temp = main_stack;
    printf("Contenu de la pile :\n");
    while (temp != NULL) {
        printf("%.2f\n", temp->data);
        temp = temp->next;
    }
}

// Fonction pour obtenir l'élément du sommet de la pile
float result() {
    if (is_empty()) {
        printf("La pile est vide\n");
         // Sortie si la pile est vide
    }
    return main_stack->data;
}

// Fonction pour supprimer un nœud
void delete_node() {
    if (is_empty()) {
        printf("La pile est vide, rien à supprimer\n");
        return;
    }
    sommet temp = main_stack;
    main_stack = temp->next;
    free(temp);
}

// Fonction pour supprimer tous les nœuds de la pile
void delete_all() {
    while (!is_empty()) {
        delete_node();
    }
    printf("Tous les nœuds ont été supprimés, la pile est maintenant vide\n");
}

// Fonction pour transférer de main_stack à save_stack
void sauvegarder() {
    if (is_empty()) {
        printf("main_stack est vide\n");
        return;
    }
    float value = pop();
    sommet new_node = newNode(value);
    new_node->next = save_stack;
    save_stack = new_node;

    printf("Valeur sauvegardee : %.2f\n", value);
}

// Fonction pour transférer la valeur du sommet de save_stack à main_stack
void rappeler() {
    if (save_stack == NULL) {
        printf("save_stack est vide\n");
        return;
    }
    sommet temp = save_stack;
    float value = temp->data;
    save_stack = temp->next;
    free(temp);
    push(value);
    printf("Valeur rappelee : %.2f\n", value);
}

// Fonction pour calculer les opérations binaires
float calculer_binop(char op, float a, float b) {
    switch(op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
                return a / b;

        case '^':
            return pow(a, b);
        default:
            return ;
    }
}

// Fonction pour calculer les opérations unaires
float calculer_unop(char op, float a) {
    switch(op) {
        case 'N':  // NEG: Négation
            return -a;
        case 'A':  // VALABS: Valeur absolue
            return fabs(a);
        case 'S':  // SQRT: Racine carrée
                return sqrt(a);

        case 'I':
            return sin(a);
        case 'C':
            return cos(a);
        case 'T':
            return tan(a);
        case 'L':
            return log(a);
        case 'E':
            return exp(a);
        default:
            return ;
    }
}
