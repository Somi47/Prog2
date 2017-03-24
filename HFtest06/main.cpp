#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

char myid[]   = "Somorjai Balazs,1MI,8,L3J <extrackto@gmail.com> WGGAW5\n";
char mytask[] = "Feladat = 4\n";

// ^[^#]_?(0x)*[0-9]*W6.*[a-z]+.+mmese(A|b)
bool Matches( string str )
{
    int iPos = 0;

    // [^#]
    if( str[iPos] == '#' )
        return false;
    ++iPos;

    // _?
    if( str[iPos] == '_' )
        ++iPos;

    // (0x)*
    while( str[iPos] == '0' && str[iPos+1] == 'x' )
        iPos += 2;

    // [0-9]*
    while( str[iPos] >= '0' && str[iPos] <= '9' )
        ++iPos;

    cout<<iPos;

    return true;
}

int main()
{
    setbuf(stdout, NULL);        // Kikapcsolja a bufferelest
    printf(myid);
    printf(mytask);

    int iCount = 0;
    string str;
    while( cin >> str )
    {
        if( Matches( str ) )
            ++iCount;
    }

    cout << iCount << endl;

//    for( int i = 1; i < 9; ++i )
//        printf( "a_0x%dW6somorjaibalazsmmeseA\n", i );
//
//    for( int i = 0; i < 181; ++i )
//        printf( "eznemjo\n" );

    return 0;
}
