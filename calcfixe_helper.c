//
// Created by FAHD on 07/12/2024.
//
#include "calcfixe_helper.h"
#include "Calcfixe.h"
void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);  // Convert each character to lowercase
    }
}
char *input_cleaner(char input[]){
    int i=0;
    while(input[i]==' '){
        i++;
    }
    char *c=&input[i];
    toUpperCase(c);
    return c;
   }


void input_handler(char input[]) {
    char *cleaned_input = input_cleaner(input); // Clean and standardize input

    if (strncmp(cleaned_input, "ENTER", 5) == 0) {
        enter(cleaned_input);

    }else if (strncmp(cleaned_input, "CLR", 3) == 0) {
        if(!is_empty()) {
           delete_all();
        }else {
            printf("Stack is already empty!!!\n");
        }

    }else if (strncmp(cleaned_input, "EXIT", 5) == 0) {
        printf("GOODBYE!!!! SEE YOU NEXT TIME!\n");
        exit(1);
    }
    else if (strncmp(cleaned_input, "CLRLAST", 7) == 0) {
        if (!is_empty()) {
            delete_node();
        }else {
            printf("Stack is already empty!\n");
        }

    }else if (strncmp(cleaned_input, "RESUL", 5) == 0) {
        printf("RESULT IS:%.2f  ",result());
    } else if (strcmp(cleaned_input, "LOG") == 0 ||
               strcmp(cleaned_input, "NEG") == 0 ||
               strcmp(cleaned_input, "VALABS") == 0 ||
               strcmp(cleaned_input, "SQRT") == 0 ||
               strcmp(cleaned_input, "SIN") == 0 ||
               strcmp(cleaned_input, "COS") == 0 ||
               strcmp(cleaned_input, "TAN") == 0 ||
               strcmp(cleaned_input, "EXP") == 0 ||
               strcmp(cleaned_input, "LN") == 0 ||
               strcmp(cleaned_input, "SQR") == 0) {
        Unary_op(cleaned_input);
               } else if (strcmp(cleaned_input, "ADD") == 0 ||
                          strcmp(cleaned_input, "SUB") == 0 ||
                          strcmp(cleaned_input, "MUL") == 0 ||
                          strcmp(cleaned_input, "DIV") == 0 ||
                          strcmp(cleaned_input, "POW") == 0) {
                   Binary_op(cleaned_input);
                          } else {
                              printf("Unknown command: %s\n", cleaned_input);
                          }
}


void enter(char input[]) {
    char *str = &input[5];
    float value = atof(str);
    push(value);
}

void Unary_op(char input[]) {
    int op = pop();
    if (strcmp(input, "LOG") == 0) {
        push(calculer_unop('L',op));
    } else if (strcmp(input, "NEG") == 0) {
        push(calculer_unop('N',op));
    } else if (strcmp(input, "VALABS") == 0) {
        push(calculer_unop('V',op));
    } else if (strcmp(input, "SQRT") == 0) {
        push(calculer_unop('S',op));
    } else if (strcmp(input, "SIN") == 0) {
        push(calculer_unop('I',op));
    } else if (strcmp(input, "COS") == 0) {
        push(calculer_unop('C',op));
    } else if (strcmp(input, "TAN") == 0) {
        push(calculer_unop('T',op));
    } else if (strcmp(input, "EXP") == 0) {
        push(calculer_unop('E',op));
    }else {
        printf("Unknown unary operation "
               "exterior function error!!: %s\n", input);
    }
}

void Binary_op(char input[]) {
    if (!is_empty()){
        float op1 = pop();
        if (!is_empty()) {
            float op2 = pop();
             if (strcmp(input, "ADD") == 0) {
                push(calculer_binop("+",op1,op2));
             } else if (strcmp(input, "SUB") == 0) {
                 push(calculer_binop("-",op1,op2));

             } else if (strcmp(input, "MUL") == 0) {
                 push(calculer_binop("*",op1,op2));
             } else if (strcmp(input, "DIV") == 0) {
                 if (op2 != 0) {
                     push(calculer_binop("/",op1,op2));
                 }

             } else if (strcmp(input, "POW") == 0) {
                 push(calculer_binop("^",op1,op2));
             } else {
                    printf("Unknown binary operation: %s\n", input);
             }

        }else {
            printf("stack needs one more element\n\n");
            push(op1);
            return;
        }
    }else {
        printf("Stack is empty!!\n");
        return;
    }



}


