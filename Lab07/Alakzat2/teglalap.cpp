/**
 *  \file teglalap.cpp
 *  Teglalap oszt�ly tagf�ggv�nyinek megval�s�t�sa
 */
#include "teglalap.h"

/// T�glalapot rajzol� rajzol fv.
void Teglalap::rajzol() {
    std::cout << "Rajzol: " << *this << std::endl;
}

/// Glob�lis << oper�tor
std::ostream& operator<<(std::ostream& os, const Teglalap& t) {
    return os << "Teglalap " << (Alakzat&)t << ",p1=" << t.getp1();
}
