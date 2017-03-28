/**
 * \file generikus1_teszt.cpp
 *
 * Egyszerû példa osztálysablonra és függvénysablonra.
 *
 */

/**
 * TESTLEVEL == 0 estén az elõre elkészített Integer osztályt próbálja ki pár esetre.
 * TESTLEVEL == 1 estén az Ön által elkészítendõ Alaptipus osztálysablont próbálja ki.
 * TESTLEVEL >= 2 esetén pedig egy egyszerû függvénysablont kell elkészítenie.
*/
#define TESTLEVEL 2

#include <iostream>
#include "integer.h"

#if TESTLEVEL > 0
# include "alaptipus.hpp"
#endif // TESTLEVEL > 0

/// Korábban használt makró, ami végrehajtás elõtt kiírja a paraméterét
/// A sor elejére négy szóközt ír, így az utasítások, deklarációk jól elkülöníthetõk.
#define _(...)  std::cout << "    " << #__VA_ARGS__ << std::endl; __VA_ARGS__

/// Ebbõl a függvénybõl kell sablont készíteni TESTLEVEL >= 2 esetén (l. útmutató)
template<typename T>
void kiir(T* first, T* last, std::ostream& os = std::cout) {
    while (first != last)
        os << *first++ << ' ';
    os << std::endl;
}

int main() {
#if TESTLEVEL >= 0
    {
    std::cout << "\nTESTLEVEL >= 0\n";

    /// Csak az Integer osztályt mutatja be.
    /// Értsem meg az osztály mûködését és használatát!
_(  Integer a;                          )
_(  a = 10;                             )

    /// Szedje szét a kifejezést operátoronként külön sorba és
    /// a debug funkcióval kövesse a végrehajtást!
_(  Integer b = a * 2 + 1 * a + 1;      )

    /// Néhány további mûvelet
_(  std::cout << b / 10 << std::endl;   )

_(  Integer t[] = { 1, 2, 4, 8, 10} ;    )


_( kiir(t, t+5);                        )
    }
#endif // TESTLEVEL >= 0


#if TESTLEVEL >= 1
    {
    std::cout << "\nTESTLEVEL >= 1\n";

    /// Az Alaptípus sablont példányosítjuk double típusra.
_(  Alaptipus<double> a;                          )
_(  a = 10;                                       )
_(  Alaptipus<double> b = a * 2 + 1 * a + 1;      )
    /// Néhány további mûvelet
_(  std::cout << b / 10 << std::endl;             )

_(  Alaptipus<double> t[] = { 1.1, 2.2, 4.4, 8.8};)

#if TESTLEVEL >= 2
    std::cout << "\nTESTLEVEL >= 2\n";

_(  kiir(t, t+4);                                 )
#endif // TESTLEVEL >= 2
    }
#endif // TESTLEVEL >= 1

    return 0;
}
