/**
 *  \file alakzat.h
 *  Alakzat alaposzt�ly deklar�ci�ja
 */
#ifndef ALAKZAT_H
#define ALAKZAT_H

#include <iostream>         // ostream miatt kell
#include "pont.h"
#include "szin.h"

/// Alakzat abszrakt oszt�ly
class Alakzat {
     Pont p0;                   /// alakzat orig�ja
     Szin sz;                   /// alakzat sz�ne
public:
    /// Konstruktor
    /// @param p0 - kezd�pont
    /// @param sz - sz�n �s �tl�tsz�s�g
    Alakzat(const Pont& p0, const Szin& sz) :p0(p0), sz(sz) {}

    /// Poz�ci� lek�rdez�se
    /// @return alakzat orig�ja
    Pont getp0() const { return p0; }

    /// Szin lek�rdez�se
    /// @return alakzat sz�ne
    Szin getsz() const { return sz; }

    /// mozgat: orig�j�t eltolja az �j pontba
    /// @param d - eltol�s vektora
    void mozgat(const Pont& d);

    /// rajzol
    virtual void rajzol() = 0;

    /// Destruktor virtu�lis, hogy lehessen dinamikus adattagja
    /// a sz�rmaztatottnak
    virtual ~Alakzat() {}
};

/// Glob�lis <<< oper�tor
/// @param os - ostream
/// @param a - alakzat
std::ostream& operator<<(std::ostream& os, const Alakzat& a);

#endif // ALAKZAT_H
