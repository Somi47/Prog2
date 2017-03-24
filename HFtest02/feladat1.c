#include <stdio.h>

char myid[]   = "Somorjai Balazs,1MI,8,L3J <extrackto@gmail.com> WGGAW5\n";
char mytask[] = "Feladat = 5\n";

int main()
{
    setbuf(stdout, NULL);        // Kikapcsolja a bufferelest
    printf(myid);
    printf(mytask);
    return 0;
}
