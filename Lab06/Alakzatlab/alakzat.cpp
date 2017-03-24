/**
 *  \file kor.cpp
 *  Alakzat oszt�ly tagf�ggv�nyinek megval�s�t�sa
 */
#include "alakzat.h"

/// mozgat - eltolja az alakzat orig�j�t
/// @param d - eltol�s
void Alakzat::mozgat(const Pont& d) {
    Szin tsz = sz; 	/// t�nyleges rajzol�si sz�n elment�se
    sz = BACKGND;   /// rajzol�si sz�n legyen a h�tt�r sz�ne
    rajzol(); 		/// let�rl�s az eredeti helyr�l (rajzol�s h�tt�r sz�nnel)
    p0 += d;  	    /// mozgat�s: a poz�ci� v�ltozik
    sz = tsz;		/// rajzol�si sz�n a t�nyleges sz�n
    rajzol(); 		/// felrajzol�sa az �j poz�ci�ra
}

/// Glob�lis <<< oper�tor
std::ostream& operator<<(std::ostream& os, const Alakzat& a) {
    return os << "p0=" << a.getp0() << ",szin=" << a.getsz();
}
