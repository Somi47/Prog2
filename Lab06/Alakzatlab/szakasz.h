/**
 *  \file szakasz.h
 *  Szakasz oszt�ly deklar�ci�ja
 */
#ifndef SZAKASZ_H
#define SZAKASZ_H

#include "alakzat.h"

/// szakasz
class Szakasz : public Alakzat {
    Pont pv;    /// szakasz v�gpontja a P0-hoz k�pest
public:
    /// konstruktor 2 pontb�l
    /// @param p0 - kezd�pont
    /// @param pv - v�gpont
    /// @param sz - sz�n �s �tl�tsz�s�g
    Szakasz(const Pont& p0, const Pont& pv, Szin sz)
                     : Alakzat(p0, sz), pv(p0-pv) { }

    /// konstruktor 1 pontb�l �s 2 hosszb�l
    /// @param p0 - kezd�pont
    /// @param xl - x ir�ny� hossz
    /// @param yl - y ir�ny� hossz
    /// @param sz - sz�n �s �tl�tsz�s�g
    Szakasz(const Pont& p0, int xl, int yl, Szin sz)
                     : Alakzat(p0, sz), pv(getp0()+Pont(xl, yl)) { }

    /// Szakasz v�gpontj�nak lek�rdez�se
    /// @return szakasz v�gpontjaa
    Pont getpv() const { return getp0()+pv; }

    /// szakaszt rajzol
    void rajzol();	    // �tdefini�ljuk a virt. fv-t.
};

/// Glob�lis <<< oper�tor
/// @param os - ostream
/// @param sz - szakasz
std::ostream& operator<<(std::ostream& os, const Szakasz& sz);

#endif // SZAKASZ_H
