#include "Calcfixe.h"
#include <stdio.h>
#include"calcfixe_helper.h"
int main() {
    printf("Bienvenue sur le calculateur!\n");
    printf("Voici ce que ce calculateur peut faire:\n");
    printf("1. Ajouter (ADD)\n");
    printf("2. Soustraire (SUB)\n");
    printf("3. Multiplier (MUL)\n");
    printf("4. Diviser (DIV)\n");
    printf("5. Puissance (POW)\n");
    printf("6. Logarithme naturel (LOG)\n");
    printf("7. Negatif (NEG)\n");
    printf("8. Valeur absolue (VALABS)\n");
    printf("9. Racine carree (SQRT)\n");
    printf("10. Sinus (SIN)\n");
    printf("11. Cosinus (COS)\n");
    printf("12. Tangente (TAN)\n");
    printf("13. Exponentielle (EXP)\n");
    printf("16. Entrer une valeur (ENTER)\n");
    printf("17. Effacer la pile (CLR)\n");
    printf("18. Effacer le dernier élément (CLRLAST)\n");
    printf("19. Afficher le dernier résultat (RESULT)\n");
    printf("Pour quitter, tapez EXIT.\n\n");
    char input[100];

    while (1) {
        display();
        printf("\n");
        fgets(input, sizeof(input), stdin); // Get the input from the user
        input_handler(input); // Pass it to the input handler for processing
    }
    return 0;
}
