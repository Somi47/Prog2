#include <stdio.h>
#include "polinom.h"

int main()
{
    double an[] = { 3, 2, 1 };
    double res[] = { 3, 6, 11, 18, 27, 38, 51 };
    int hibak = 0;
    int i;
    for (i = 0; i < 7; i++)
    if (res[i] != polinom(i, an, 2)) {
        printf("Hibas: %f != %f", res[i], polinom(i, an, 2));
        hibak++;
    }
    if (hibak == 0)
        printf("Nem volt elteres\n");
    return 0;
}
