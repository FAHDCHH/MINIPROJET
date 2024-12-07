//
// Created by FAHD on 07/12/2024.
//
#include "calcfixe_helper.h"
void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);  // Convert each character to lowercase
    }
}
void input_cleaner(void){}
void input_handler(char input[]) {
    if (strncmp(input, "ENTER", 4) == 0 ) {
        enter(input);
   }else if (strncmp(input, "EXIT", 4) == 0) {
       exit(EXIT_SUCCESS);
   }else if(strcmp(input, "LOG") == 0 ||
    strcmp(input, "NEG") == 0 ||
    strcmp(input, "VALABS") == 0 ||
    strcmp(input, "SQRT") == 0 ||
    strcmp(input, "SIN") == 0 ||
    strcmp(input, "COS") == 0 ||
    strcmp(input, "TAN") == 0 ||
    strcmp(input, "EXP") == 0 ||
    strcmp(input, "LN") == 0 ||
    strcmp(input, "SQR") == 0) {
       Unary_op(input);
       // Unary operations code here
    } else if (strcmp(input, "ADD") == 0 || strcmp(input, "SUB") == 0 || strcmp(input, "MUL") == 0 || strcmp(input, "DIV") == 0 || strcmp(input, "POW") == 0) {
           Binary_op(input);
        // Binary operations code here
           }


   }
 {}}
void enter(char input[]) {

}

void Unary_op(char input[]){}
void Binary_op(char input[]){}

#include "calcfixe_helper.h"
