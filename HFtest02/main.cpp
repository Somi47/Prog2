#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

char myid[]   = "Somorjai Balazs,1MI,8,L3J <extrackto@gmail.com> WGGAW5\n";
char mytask[] = "Feladat = 2\n";

double f( double x )
{
    if( x > 50 )
        return x / 108.65;
    else
        return 0.424*pow( x, 4 ) - 0.848*pow( x, 3 ) + 54.25*pow( x, 2 ) + 2*x - 50;
}

int main()
{
    setbuf(stdout, NULL);        // Kikapcsolja a bufferelest
    printf(myid);
    printf(mytask);

    double dValue = 0;
    while( cin>>dValue )
        printf( "%fl\n", f( dValue ) );

    return 0;
}
