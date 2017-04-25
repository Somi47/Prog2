/**
 * Egyszerû program az iterátoros generikus tömb kipróbálásához.
 */

#include <iostream>
#include <algorithm>
#include <functional>
#include "gen_array_iter4.hpp"
#include "sablonok4.hpp"

using std::cout;
using std::endl;

int main() {
    /// Egyszerû C tömbök, amibõl majd az adatokat vesszük
    int it1[] = {-5, -4, -3, -2, -1, 0, 1, -82, 3, 4 };
    double dt1[] = { .0,  234.1,  .2,  .3,  -444.4, -12.4, 128.799 };

    try {
        /// létrehozunk egy funktort az intek  kiíráshoz
        ostreamFunctor<int> intout(cout, ", ");

        /// segítségével kiírjuk az it1 adatait
        cout << "it1: ";
		std::for_each(it1, it1+10, intout);
		cout << endl;

        /// létrehozunk egy funktort a double adatok kiíráshoz
        ostreamFunctor<double> dblout(cout, ", ");

        /// es kiirjuk az dt1 adatait is
        cout << "dt1: ";
		std::for_each(dt1, dt1+7, dblout);
		cout << endl;

		/// az it1 tömbbõl létrehozunk egy intarr1-et
		Array<int, 100> intarr1(it1, it1+10);

		/// kiírjuk az adatait
        cout << "intarr1: ";
		forEach(intarr1.begin(), intarr1.end(), intout);
		cout << endl;

        /// a dt1 tömbbõl létrehozunk egy dblarr1-et
		Array<double, 20> dblarr1(dt1, dt1+7);

		/// kiírjuk az adatait
        cout << "dblarr1: ";
		forEach(dblarr1.begin(), dblarr1.end(), dblout);
		cout << endl;

/// IDE IRJA A FELADATOKHOZ TARTOZÓ TESZTEKET:
		/// Számoljuk meg, hogy hány 1-nél nagyobb elem van (2. feladat)
		cout << std::count_if( it1, it1 + 10, std::bind2nd( std::greater<int>(), 1 ) ) << endl;
		cout << std::count_if( intarr1.begin(), intarr1.end(), std::bind2nd( std::greater<int>(), 1 ) ) << endl;


		dblarr1.erase( remove_if( dblarr1.begin(), dblarr1.end(), std::bind2nd( std::less<double>(), 1 ) ) ); // egynél kisebb elemek törlése
		dblarr1.erase( remove_if( dblarr1.begin(), dblarr1.end(), std::bind2nd( std::less<double>(), 1 ) ) );
		for_each( dblarr1.begin(), dblarr1.end(), dblout );  // megjelenik a szemét a tároló végén.
		cout << endl;

    } catch (std::exception& e) {	// az out_of_range, és a runtime_error is
								// ez excetionból származik. Így azok kompatibbilisek
								// az alaposztállyal
        cout << e.what() << endl;
    }
}
