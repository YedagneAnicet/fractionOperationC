#ifndef FRACTION_H
#define FRACTION_H

typedef struct
{
    int numerateur;
    int denominateur;
} Fraction;

void simplifierFraction(Fraction *simp_frac);
void printFractionSansRetour(Fraction frac);
void printFractionAvecRetour(Fraction frac);
void effectuerOperation(char operation, Fraction frac1, Fraction frac2);

Fraction saisirFraction();
Fraction sommeFractions(Fraction frac1, Fraction frac2);
Fraction soustractionFractions(Fraction frac1, Fraction frac2);
Fraction multiplicationFractions(Fraction frac1, Fraction frac2);
Fraction divisionFractions(Fraction frac1, Fraction frac2);

#endif
