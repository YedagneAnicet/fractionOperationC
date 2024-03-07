#include "fraction.h"
#include <stdio.h>

int pgcd(int a, int b)
{
    if (b == 0)
        return a;
    return pgcd(b, a % b);
}

void simplifierFraction(Fraction *simp_frac)
{
    int diviseur = pgcd(simp_frac->numerateur, simp_frac->denominateur);
    simp_frac->numerateur /= diviseur;
    simp_frac->denominateur /= diviseur;
}

Fraction sommeFractions(Fraction frac1, Fraction frac2)
{
    Fraction sum_frac;
    sum_frac.numerateur = frac1.numerateur * frac2.denominateur + frac2.numerateur * frac1.denominateur;
    sum_frac.denominateur = frac1.denominateur * frac2.denominateur;
    simplifierFraction(&sum_frac);
    return sum_frac;
}

Fraction soustractionFractions(Fraction frac1, Fraction frac2)
{
    Fraction dif_frac;
    dif_frac.numerateur = frac1.numerateur * frac2.denominateur - frac2.numerateur * frac1.denominateur;
    dif_frac.denominateur = frac1.denominateur * frac2.denominateur;
    simplifierFraction(&dif_frac);
    return dif_frac;
}

Fraction multiplicationFractions(Fraction frac1, Fraction frac2)
{
    Fraction prod_frac;
    prod_frac.numerateur = frac1.numerateur * frac2.numerateur;
    prod_frac.denominateur = frac1.denominateur * frac2.denominateur;
    simplifierFraction(&prod_frac);
    return prod_frac;
}

Fraction divisionFractions(Fraction frac1, Fraction frac2)
{
    Fraction div_frac;
    div_frac.numerateur = frac1.numerateur * frac2.denominateur;
    div_frac.denominateur = frac1.denominateur * frac2.numerateur;
    simplifierFraction(&div_frac);
    return div_frac;
}

void printFractionSansRetour(Fraction frac)
{
    printf("%d/%d", frac.numerateur, frac.denominateur);
}

void printFractionAvecRetour(Fraction frac)
{
    printf("%d/%d\n", frac.numerateur, frac.denominateur);
}

// Fonction pour saisir une fraction
Fraction saisirFraction()
{
    Fraction frac;
    printf("Saisir le numerateur : ");
    scanf("%d", &frac.numerateur);
    printf("Saisir le denominateur : ");
    scanf("%d", &frac.denominateur);
    return frac;
}

// Fonction pour effectuer une opération sur deux fractions
void effectuerOperation(char operation, Fraction frac1, Fraction frac2)
{
    Fraction resultat;
    switch (operation)
    {
    case '+':
        resultat = sommeFractions(frac1, frac2);
        printf("\nAddition de fraction \n");
        break;
    case '-':
        resultat = soustractionFractions(frac1, frac2);
        printf("\nSoustraction de fraction \n");
        break;
    case '*':
        resultat = multiplicationFractions(frac1, frac2);
        printf("\nMultiplication de fraction \n");
        break;
    case ':':
        resultat = divisionFractions(frac1, frac2);
        printf("\nDivision de fraction \n");
        break;
    default:
        printf("Opération invalide.\n");
        return;
    }

    printFractionSansRetour(frac1);
    printf(" %c ", operation);
    printFractionSansRetour(frac2);
    printf(" = ");
    printFractionAvecRetour(resultat);
    printf("\n");
}
