#include "swap.h"

void swap(bool &a, bool &b)
{
    bool temp = a;
    a = b;
    b = temp;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
