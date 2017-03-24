/**
 *  \file main.cpp
 *  Demo program az alakzat osztályok kipróbálására.
 *  Felrajzol pár alakzatot, majd elmozgatja kicsit.
 */

#include <iostream>
#include "szakasz.h"
#include "kor.h"
#include "teglalap.h"
#include "haromszog.h"
#include "trapez.h"

using std::cout;
using std::endl;

int main(int argc, char** argv) {

    const int N = 100;           // maximum 100 alakzatunk lehet
    Alakzat *idom[N];
    int db = 0;                  // most nincs egy se

    Szakasz sz1(Pont(20,40), 100, 0, WHITE);
    sz1.rajzol();
    idom[db++] = &sz1;			// nem kell cast, mert kompatibilis

    Kor k1(Pont(120,140), 50, BLUE);
    k1.rajzol();
    idom[db++] = &k1;

	Teglalap t1( Pont( 53, 87 ), 20, 10, GREEN );
	t1.rajzol();
	idom[ db++ ] = &t1;

	Haromszog h1( Pont( 32, 997 ), Pont( 48723, 87 ), Pont( 53, 87 ), RED );
	h1.rajzol();
	idom[ db++ ] = &h1;

	Trapez trap1( Pont( 32, 997 ), Pont( 58, 82 ), Pont( 48723, 87 ), Pont( 53, 87 ), RED );
	trap1.rajzol();
	idom[ db++ ] = &trap1;

    cout << "\nMost kirajzoljuk alaposztaly pointerrel:" << endl;
    for (int i = 0; i < db; i++)  // végigmegyünk az összes alakzaton
        idom[i]->rajzol();        // kirajzoljuk

    cout << "\nMost mozgatunk (x+100, y+100) (pointerrel):" << endl;
    for (int i = 0; i < db; i++)  // az összes alakzatra
        idom[i]->mozgat(Pont(100, 100));  // kicsit mozdítunk rajta

    return 0;
}
