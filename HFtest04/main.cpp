#include <iostream>
#include <stdio.h>

using namespace std;

char myid[]   = "Somorjai Balazs,1MI,8,L3J <extrackto@gmail.com> WGGAW5\n";
char mytask[] = "Feladat = 4\n";

int main()
{
    setbuf(stdout, NULL);        // Kikapcsolja a bufferelest
    printf(myid);
    printf(mytask);

    for( int i = 1; i < 9; ++i )
        printf( "a_0x%dW6somorjaibalazsmmeseA\n", i );

    for( int i = 0; i < 181; ++i )
        printf( "eznemjo\n" );

    return 0;
}
