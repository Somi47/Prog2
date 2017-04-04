/**
 * Egyszerû program az iterátoros generikus tömb kipróbálásához.
 */

#include <iostream>
#include <stdexcept>

#define TESTLEVEL 4

#include "integer.h"
#include "gen_array_iter3.hpp"

#if TESTLEVEL >= 2
#include "..\sablonok.hpp"
#endif

using std::cout;
using std::endl;


/// Összegzõ funktor
/// TESTLEVEL == 5-höz
struct Sum {
    int sum;
    Sum(int s=0) :sum(s) {}
    void operator()(int i) { sum += i;}
};

/// Egyszerû C tömbök, amibõl majd az adatokat vesszük
int itomb[] = { -5, 11, 13, -2, -1, 0, 1, -82, 3, 4 };
double dtomb[] = { .0,  .1,  .2,  .3,  4.4, -12.4, 8.7  };
const char* txtomb[] = { "C#" , "C", "C++", "Java", "C++11" };

int main() {

    try {
		/// az int tömbbõl létrehozunk egy intarr0-át
		Array<int> intarr0(itomb, itomb+10);
        /// Kiírjuk az elemeket.
/// Készítsen sablont (3. feladat), és helyettesítse a kiírást a sablon hívásával pl:
///  kiir("intarr0", intarr0);
		cout << "intarr0: size=" << intarr0.size()
			 << " capacity=" << intarr0.capacity() << endl;
		cout << "\t data=";
		printEach( intarr0.begin(), intarr0.end(), cout, " " );
		cout << endl;
/// --Eddig tart a kiírás

#if TESTLEVEL == 0  // csak 0-nál, hogy máskor ne zavarjon a kivétel
		/// szándékosan rosszul indexelünk
        cout << intarr0.at(112);
#endif // TESTLEVEL == 0

		/// a double tömbbõl létrehozunk egy dblarr0-át
		Array<double, 20> dblarr0(dtomb, dtomb+7);
        /// Kiírjuk az elemeket.
/// Helyettesítse a kiírást a kiir sablon használatával (3. feladat!)
		cout << "dblarr0: size=" << dblarr0.size()
			 << " capacity=" << dblarr0.capacity() << endl;
		cout << "\t data=";
		printEach( dblarr0.begin(), dblarr0.end(), cout, " " );
		cout << endl;
/// --Eddig tart a kiírás

#if TESTLEVEL >= 1
		/// Ellenõrizzük az Array post-inkremens iterátorát:
        Array<int>::iterator i1, i2;
        i1 = i2 = intarr0.begin();
        if (i1 != i2++) { cout << "** HIBAS az iterator post-inkremens operatora **\n"; }
#endif // TESTLEVEL >= 1

#if TESTLEVEL >=2
        /// intarr0-ból létrehozzuk az intarr1-et
		Array<int, 100> intarr1(intarr0.begin(), intarr0.end());
        /// Kiírjuk az elemeket.
/// Helyettesítse a kiírást a kiir sablon használatával (3. feladat)
		cout << "intarr1: size=" << intarr1.size()
			 << " capacity=" << intarr1.capacity() << endl;
		cout << "\t data= ";
		printEach( intarr1.begin(), intarr1.end(), cout, " " );
		cout << endl;
/// --Eddig tart a kiírás
#endif // TESTLEVEL >= 2

#if TESTLEVEL >= 3
        /// const char* tömbbõl létrehozzuk az txarray-t
        Array<const char*> txarray(txtomb, txtomb+5);
        /// Kiírjuk az elemeket.
		cout << "\ntxarray";
		printEach( txarray.begin(), txarray.end() );

		nagyobb_mint<int> nagyobb( 5 );
        /// Intarr0 kiírása újra.
		cout << "intarr1: size=" << intarr1.size()
			<< " capacity=" << intarr1.capacity() << endl;
		cout << "\t data= ";
		printEach( intarr1.begin(), intarr1.end(), cout, " " );

		cout << "intarr0 5-nel nagyobb: "
			<< szamol_ha( intarr0.begin(), intarr0.end(), nagyobb );
        cout << " db\n";

#endif // TESTLEVEL >= 3

#if TESTLEVEL >= 4
        cout << "intarr0 legnagyobb: "
             << *kivalaszt(intarr1.begin(), intarr1.end(), nagyobbfunct<int>())
             << endl;  // kiírja a legnagyobb értéket a tömbbõl

#endif // TESTLEVEL >= 4

#if TESTLEVEL >= 5
        Sum s = forEach(intarr1.begin(), intarr1.end(), Sum());
        cout << "\nintarr0 osszegzes forEach segitsegevel: " << s.sum << endl;
#endif

#if TESTLEVEL >= 6
        cout << "intarr0 kiiras forEach segtisegevel: ";
        ostreamFunctor<int> out(cout, ",");
        forEach(intarr1.begin(), intarr1.end(), out);
        cout << endl;
#endif

#if TESTLEVEL >= 7
        /// Itt valamilyen memóriaszemét lesz
		cout << "\nMemoriaszemet: " << intarr1.at(12) << endl;

		/// Itt meg nincs memóriaszemét. Miért?
        Array<Integer,100> Ia;
        cout << "Ez meg nulla: "<< Ia.at(12) << endl;
#endif

    } catch (std::exception& e) { // az out_of_range, és a runtime_error is az excetion
                                  // osztályból származik. Így azok kompatibilisek
								  // az alaposztállyal
        cout << e.what() << endl;
    }
}

