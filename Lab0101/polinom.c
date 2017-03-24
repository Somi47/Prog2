#include "polinom.h"

double polinom(double x, double a[], int n)
{
    double eredmeny = 0;
    for( int i=n; i > 0; --i )
    {
        eredmeny += a[i];
        eredmeny *= x;
    }
    eredmeny += a[0];

    return eredmeny;
}
