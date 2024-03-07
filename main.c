#include <stdio.h>
#include "fraction.h"

int main()
{
    Fraction frac1;
    Fraction frac2;
    char choix;
    char operation;

    do
    {
        printf("Quelle opération souhaitez-vous effectuer ?\n");
        printf("1. Addition\n");
        printf("2. Soustraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Quitter le programme\n");
        printf("Votre choix : ");
        scanf(" %c", &choix);

        switch (choix)
        {
        case '1':
            operation = '+';
            break;
        case '2':
            operation = '-';
            break;
        case '3':
            operation = '*';
            break;
        case '4':
            operation = ':';
            break;
        case '5':
            printf("Au revoir !\n");
            return 0;

        default:
            printf("Choix invalide. Veuillez choisir une option valide.\n");
            continue;
        }

        printf("Saisir la premiere fraction \n");
        frac1 = saisirFraction();
        printf("\nSaisir la seconde fraction \n");
        frac2 = saisirFraction();

        effectuerOperation(operation, frac1, frac2);

        printf("Voulez-vous effectuer une autre opération ? (O/N) : ");
        scanf(" %c", &choix);
    } while (choix == 'O' || choix == 'o');

    return 0;
}
