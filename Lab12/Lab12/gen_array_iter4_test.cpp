/**
 * Egyszer� program az iter�toros generikus t�mb kipr�b�l�s�hoz.
 */

#include <iostream>
#include <algorithm>
#include <functional>
#include "gen_array_iter4.hpp"
#include "sablonok4.hpp"

using std::cout;
using std::endl;

int main() {
    /// Egyszer� C t�mb�k, amib�l majd az adatokat vessz�k
    int it1[] = {-5, -4, -3, -2, -1, 0, 1, -82, 3, 4 };
    double dt1[] = { .0,  234.1,  .2,  .3,  -444.4, -12.4, 128.799 };

    try {
        /// l�trehozunk egy funktort az intek  ki�r�shoz
        ostreamFunctor<int> intout(cout, ", ");

        /// seg�ts�g�vel ki�rjuk az it1 adatait
        cout << "it1: ";
		std::for_each(it1, it1+10, intout);
		cout << endl;

        /// l�trehozunk egy funktort a double adatok ki�r�shoz
        ostreamFunctor<double> dblout(cout, ", ");

        /// es kiirjuk az dt1 adatait is
        cout << "dt1: ";
		std::for_each(dt1, dt1+7, dblout);
		cout << endl;

		/// az it1 t�mbb�l l�trehozunk egy intarr1-et
		Array<int, 100> intarr1(it1, it1+10);

		/// ki�rjuk az adatait
        cout << "intarr1: ";
		forEach(intarr1.begin(), intarr1.end(), intout);
		cout << endl;

        /// a dt1 t�mbb�l l�trehozunk egy dblarr1-et
		Array<double, 20> dblarr1(dt1, dt1+7);

		/// ki�rjuk az adatait
        cout << "dblarr1: ";
		forEach(dblarr1.begin(), dblarr1.end(), dblout);
		cout << endl;

/// IDE IRJA A FELADATOKHOZ TARTOZ� TESZTEKET:
		/// Sz�moljuk meg, hogy h�ny 1-n�l nagyobb elem van (2. feladat)
		cout << std::count_if( it1, it1 + 10, std::bind2nd( std::greater<int>(), 1 ) ) << endl;
		cout << std::count_if( intarr1.begin(), intarr1.end(), std::bind2nd( std::greater<int>(), 1 ) ) << endl;


		dblarr1.erase( remove_if( dblarr1.begin(), dblarr1.end(), std::bind2nd( std::less<double>(), 1 ) ) ); // egyn�l kisebb elemek t�rl�se
		dblarr1.erase( remove_if( dblarr1.begin(), dblarr1.end(), std::bind2nd( std::less<double>(), 1 ) ) );
		for_each( dblarr1.begin(), dblarr1.end(), dblout );  // megjelenik a szem�t a t�rol� v�g�n.
		cout << endl;

    } catch (std::exception& e) {	// az out_of_range, �s a runtime_error is
								// ez excetionb�l sz�rmazik. �gy azok kompatibbilisek
								// az alaposzt�llyal
        cout << e.what() << endl;
    }
}
