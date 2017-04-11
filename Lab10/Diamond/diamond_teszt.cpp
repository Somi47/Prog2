/**
 * \file diamond.cpp
 * Egyszer� program a rombusz (diamond) �r�kl�s probl�m�nak bemutat�s�ra
 *
 */

#define TESTLEVEL 2

/**
 * Feladatok:
 * 1. �rtse meg a programot, majd sz�ntesse meg a rombusz �r�kl�sb�l
 *    sz�rmaz� adatt�bbsz�r�z�st!
 * 2. Az Iroda oszt�ly az std::vector oszt�lyt hasz�lja t�rol�sra.
 *    A tarolo_tipus m�dos�t�s�val ez k�nnyen lecsr�lhet� std::list,
 *    vagy std::deque oszt�lyra. Mi�rt?
 * 3. Cser�lje le el�sz�r list�ra, majd sorra!
 * 4. K�sz�tse ez irodistak perzisztens v�ltozat�t!
 *
 *
 */
#include <iostream>
#include "iroda.h"
#include "alkalmazott.h"
#include "irodistak.h"
#include "memtrace.h"
#include <vector>
#include <list>
#include <deque>


using std::cin;
using std::cout;
using std::endl;

int main() {
  try {
	std::deque<Alkalmazott*> container;

	container.push_back(new Alkalmazott("Lusta Dick", 100));
    container.push_back(new HatIdeju("Grabovszki", 300, 1000));
    container.push_back(new CsopVez("Mr. Gatto", 500, 1));
    HatIdCsV *gore = new HatIdCsV("Mr. Tejfel", 600, 2, 1000);  /// mi�rt nem Alkalmazott*?
#if TESTLEVEL == 0
    munkahely.felvesz(dynamic_cast<CsopVez*>(gore));           /// mi�rt kell a cast ?
    HatIdCsVezH *saf = new HatIdCsVezH("Safranek", 700, 1000, *gore);
    munkahely.felvesz(dynamic_cast<CsopVez*>(saf));            /// mi�rt kell a cast ?
#else
    container.push_back(gore);                // mi�rt nem kell m�r a cast ?
    container.push_back(new HatIdCsVezH("Safranek", 700, 1000, *gore));
#endif
    cout << endl;
	for( std::deque<Alkalmazott*>::iterator iter = container.begin(); iter != container.end(); ++iter )
		( *iter )->kiir();
#if TESTLEVEL >= 2
    void perzTeszt();
    perzTeszt();
#endif
  } catch (std::exception& e) {
    std::cout << "*** Kivetel: *** " << e.what() << std::endl;
  }
  return 0;
}

