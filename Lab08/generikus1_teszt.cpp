/**
 * \file generikus1_teszt.cpp
 *
 * Egyszer� p�lda oszt�lysablonra �s f�ggv�nysablonra.
 *
 */

/**
 * TESTLEVEL == 0 est�n az el�re elk�sz�tett Integer oszt�lyt pr�b�lja ki p�r esetre.
 * TESTLEVEL == 1 est�n az �n �ltal elk�sz�tend� Alaptipus oszt�lysablont pr�b�lja ki.
 * TESTLEVEL >= 2 eset�n pedig egy egyszer� f�ggv�nysablont kell elk�sz�tenie.
*/
#define TESTLEVEL 2

#include <iostream>
#include "integer.h"

#if TESTLEVEL > 0
# include "alaptipus.hpp"
#endif // TESTLEVEL > 0

/// Kor�bban haszn�lt makr�, ami v�grehajt�s el�tt ki�rja a param�ter�t
/// A sor elej�re n�gy sz�k�zt �r, �gy az utas�t�sok, deklar�ci�k j�l elk�l�n�thet�k.
#define _(...)  std::cout << "    " << #__VA_ARGS__ << std::endl; __VA_ARGS__

/// Ebb�l a f�ggv�nyb�l kell sablont k�sz�teni TESTLEVEL >= 2 eset�n (l. �tmutat�)
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

    /// Csak az Integer oszt�lyt mutatja be.
    /// �rtsem meg az oszt�ly m�k�d�s�t �s haszn�lat�t!
_(  Integer a;                          )
_(  a = 10;                             )

    /// Szedje sz�t a kifejez�st oper�toronk�nt k�l�n sorba �s
    /// a debug funkci�val k�vesse a v�grehajt�st!
_(  Integer b = a * 2 + 1 * a + 1;      )

    /// N�h�ny tov�bbi m�velet
_(  std::cout << b / 10 << std::endl;   )

_(  Integer t[] = { 1, 2, 4, 8, 10} ;    )


_( kiir(t, t+5);                        )
    }
#endif // TESTLEVEL >= 0


#if TESTLEVEL >= 1
    {
    std::cout << "\nTESTLEVEL >= 1\n";

    /// Az Alapt�pus sablont p�ld�nyos�tjuk double t�pusra.
_(  Alaptipus<double> a;                          )
_(  a = 10;                                       )
_(  Alaptipus<double> b = a * 2 + 1 * a + 1;      )
    /// N�h�ny tov�bbi m�velet
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
