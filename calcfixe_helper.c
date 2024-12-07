//
// Created by FAHD on 07/12/2024.
//
#include "calcfixe_helper.h"
#include "Calcfixe.h"

// Fonction pour convertir une chaîne en majuscules
void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);  // Convertit chaque caractère en majuscule
    }
}

// Fonction pour nettoyer l'entrée et la convertir en majuscules
char *input_cleaner(char input[]) {
    int i = 0;
    while (input[i] == ' ') {  // Ignore les espaces au début de l'entrée
        i++;
    }
    char *c = &input[i];
    toUpperCase(c);  // Convertit la chaîne nettoyée en majuscules
    return c;
}

// Fonction pour gérer l'entree
void input_handler(char input[]) {
    char *cleaned_input = input_cleaner(input);

    if (strncmp(cleaned_input, "ENTER", 5) == 0) {
        enter(cleaned_input);
    } else if (strncmp(cleaned_input, "CLRLAST", 7) == 0) {
        if (!is_empty()) {
            delete_node();  // Supprime le dernier élément de la pile si elle n'est pas vide
        } else {
            printf("La pile est déjà vide !\n");
        }
    } else if (strncmp(cleaned_input, "CLR", 3) == 0) {
        if (!is_empty()) {
            delete_all();  // Supprime tous les éléments de la pile si elle n'est pas vide
        } else {
            printf("La pile est déjà vide !!!\n");
        }
    } else if (strncmp(cleaned_input, "EXIT", 4) == 0) {
        printf("AU REVOIR!!!! À LA PROCHAINE!\n");
        exit(1);  // Quitte le programme si l'entrée est "EXIT"
    } else if (strncmp(cleaned_input, "RESUL", 5) == 0) {
        printf("LE RESULTAT EST: %.2f  ", result());  // Affiche le résultat
    } else if (strncmp(cleaned_input, "LOG", 3) == 0 ||
               strncmp(cleaned_input, "NEG", 3) == 0 ||
               strncmp(cleaned_input, "VALABS", 6) == 0 ||
               strncmp(cleaned_input, "SQRT", 4) == 0 ||
               strncmp(cleaned_input, "SIN", 3) == 0 ||
               strncmp(cleaned_input, "COS", 3) == 0 ||
               strncmp(cleaned_input, "TAN", 3) == 0 ||
               strncmp(cleaned_input, "EXP", 3) == 0) {
        Unary_op(cleaned_input);  // Appelle la fonction Unary_op pour les opérations unaires
    } else if (strncmp(cleaned_input, "SUM", 3) == 0 ||
               strncmp(cleaned_input, "SUB", 3) == 0 ||
               strncmp(cleaned_input, "MUL", 3) == 0 ||
               strncmp(cleaned_input, "DIV", 3) == 0 ||
               strncmp(cleaned_input, "POW", 3) == 0) {
        Binary_op(cleaned_input);  // Appelle la fonction Binary_op pour les opérations binaires
    } else {
        printf("Commande inconnue: %s\n", cleaned_input);  // Affiche un message si la commande est inconnue
    }
}

// Fonction pour entrer une valeur dans la pile
void enter(char input[]) {
    char *str = &input[5];  // Récupère la valeur après  "ENTER"
    float value = atof(str);  // Convertit la chaîne en un nombre flottant
    push(value);  // Ajoute la valeur dans la pile
}

// Fonction pour effectuer des opérations unaires
void Unary_op(char input[]) {
    int op = pop();  // Retire un élément de la pile
    if (strncmp(input, "LOG", 3) == 0) {
        if (op <= 0) {
            printf("Le nombre est inférieur ou égal à 0");  // Vérifie si la valeur est valide pour le logarithme
        } else {
            push(calculer_unop('L', op));  // Applique l'opération LOG et ajoute le résultat dans la pile
        }
    } else if (strncmp(input, "NEG", 3) == 0) {
        push(calculer_unop('N', op));  // Applique l'opération NEG et ajoute le résultat dans la pile
    } else if (strncmp(input, "VALABS", 6) == 0) {
        push(calculer_unop('A', op));  // Applique l'opération VALABS et ajoute le résultat dans la pile
    } else if (strncmp(input, "SQRT", 4) == 0) {
        if (op < 0) {
            printf("Le nombre est inférieur à 0");  // Vérifie si la valeur est valide pour la racine carrée
        } else {
            push(calculer_unop('S', op));  // Applique l'opération SQRT et ajoute le résultat dans la pile
        }
    } else if (strncmp(input, "SIN", 3) == 0) {
        push(calculer_unop('I', op));  // Applique l'opération SIN et ajoute le résultat dans la pile
    } else if (strncmp(input, "COS", 3) == 0) {
        push(calculer_unop('C', op));  // Applique l'opération COS et ajoute le résultat dans la pile
    } else if (strncmp(input, "TAN", 3) == 0) {
        push(calculer_unop('T', op));  // Applique l'opération TAN et ajoute le résultat dans la pile
    } else if (strncmp(input, "EXP", 3) == 0) {
        push(calculer_unop('E', op));  // Applique l'opération EXP et ajoute le résultat dans la pile
    } else {
        printf("Opération unaire inconnue extérieur erreur!!: %s\n", input);  // Affiche un message d'erreur pour une opération inconnue
    }
}

// Fonction pour effectuer des opérations binaires
void Binary_op(char input[]) {
    if (!is_empty()) {
        float op1 = pop();  // Retire le premier élément de la pile
        if (!is_empty()) {
            float op2 = pop();  // Retire le deuxième élément de la pile
            if (strncmp(input, "SUB", 3) == 0) {
                push(calculer_binop('-', op1, op2));  // Applique l'opération SUB et ajoute le résultat dans la pile
            } else if (strncmp(input, "SUM", 3) == 0) {
                push(calculer_binop('+', op1, op2));  // Applique l'opération SUM et ajoute le résultat dans la pile
            } else if (strncmp(input, "MUL", 3) == 0) {
                push(calculer_binop('*', op1, op2));  // Applique l'opération MUL et ajoute le résultat dans la pile
            } else if (strncmp(input, "DIV", 3) == 0) {
                if (op2 != 0) {
                    push(calculer_binop('/', op1, op2));  // Applique l'opération DIV et ajoute le résultat dans la pile
                } else {
                    printf("Division par zéro !!!\n");
                    return;
                }
            } else if (strncmp(input, "POW", 3) == 0) {
                push(calculer_binop('^', op1, op2));  // Applique l'opération POW et ajoute le résultat dans la pile
            } else {
                printf("Opération binaire inconnue: %s\n", input);  // Affiche un message d'erreur pour une opération inconnue
            }
        } else {
            printf("La pile a besoin d'un autre élément\n\n");
            push(op1);  // Rétablit l'élément popé si la pile n'a pas assez d'éléments
            return;
        }
    } else {
        printf("La pile est vide !!\n");
        return;
    }
}


