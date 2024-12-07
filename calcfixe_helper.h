//
// Created by FAHD on 07/12/2024.
//
/* Ce header file, calcfixe_helper.h, contient les déclarations des fonctions
 auxiliaires utilisées par le programme Calcfixe. Il permet d'organiser le code
 pour le rendre plus clair et facile à maintenir.
 Les fonctions définies ici servent à gérer le traitement des entrées,
 ainsi que les opérations unaires et binaires.
 */
#include <string.h>
#include "Calcfixe.h"
#ifndef CALCFIXE_HELPER_H
#define CALCFIXE_HELPER_H
char* input_cleaner(char input[]);
void toLowerCase(char *str);
void enter(char input[]);
void input_handler(char input[]);
void Unary_op(char input[]);
void Binary_op(char input[]);

#endif //CALCFIXE_HELPER_H
