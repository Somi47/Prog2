/**
 *  \file kor.h
 *  Kor oszt�ly deklar�ci�ja
 */
#ifndef KOR_H
#define KOR_H

#include "alakzat.h"

class Kor : public Alakzat {
    int r;  /// sug�r
public:
    /// Konstruktor
    /// @param p0 - kezd�pont
    /// @param r - sug�r
    /// @param sz - sz�n �s �tl�tsz�s�g
    Kor(const Pont& p0, int r, Szin sz)
                    :Alakzat(p0, sz), r(r)  /// �s oszt�ly inic.
                    {}

    /// Sug�r lek�rdez�se
    /// @return k�r sugara
    int getr() const { return r; }

    /// k�rt rajzol
    void rajzol();
};

/// Glob�lis <<< oper�tor
/// @param os - ostream
/// @param k - kor
std::ostream& operator<<(std::ostream& os, const Kor& k);

#endif // KOR_H
