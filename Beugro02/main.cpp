#include <iostream>
#include <stdio.h>
#include "swap.h"

using namespace std;

int main()
{
    int a = 5;
    int b = 9;
    printf( "a:%d b:%d\n", a, b );
    swap( a, b );
    printf( "a:%d b:%d\n", a, b );

    return 0;
}
