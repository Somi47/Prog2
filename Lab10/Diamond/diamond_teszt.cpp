/**
 * \file diamond.cpp
 * Egyszerû program a rombusz (diamond) öröklés problémának bemutatására
 *
 */

#define TESTLEVEL 2

/**
 * Feladatok:
 * 1. Értse meg a programot, majd szüntesse meg a rombusz öröklésbõl
 *    származó adattöbbszörözést!
 * 2. Az Iroda osztály az std::vector osztályt haszálja tárolásra.
 *    A tarolo_tipus módosításával ez könnyen lecsrélhetõ std::list,
 *    vagy std::deque osztályra. Miért?
 * 3. Cserélje le elõször listára, majd sorra!
 * 4. Készítse ez irodistak perzisztens változatát!
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
    HatIdCsV *gore = new HatIdCsV("Mr. Tejfel", 600, 2, 1000);  /// miért nem Alkalmazott*?
#if TESTLEVEL == 0
    munkahely.felvesz(dynamic_cast<CsopVez*>(gore));           /// miért kell a cast ?
    HatIdCsVezH *saf = new HatIdCsVezH("Safranek", 700, 1000, *gore);
    munkahely.felvesz(dynamic_cast<CsopVez*>(saf));            /// miért kell a cast ?
#else
    container.push_back(gore);                // miért nem kell már a cast ?
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

