/**
 *  \file poligon.h
 *  Poligon osztály deklarációja
 */

#ifndef POLIGON_H
#define POLIGON_H

#include "alakzat.h"

/// Poligon osztály
/// dinamikusan tárolja a csúcspontokat
class Poligon : public Alakzat {
    Pont *pontok;       ///< csúcspontok tárolója
    unsigned int np;    ///< ennyi csúcsból áll
public:
    /// Konstruktor
    /// @param p0 - kezdőpont
    /// @param sz - szín és átlátszóság
    Poligon(const Pont& p0, const Szin sz) :Alakzat(p0, sz), np(1)
           { pontok = new Pont[np-1]; } // eggyel kevesebbet foglal, mert a p0 az alaposztályban van

	Poligon( const Poligon &other )
		: Alakzat( other )
	{
		np = other.np;
		pontok = new Pont[ np - 1 ];
		for( int i = 1; i < np; ++i )
			pontok[ i ] = other.pontok[ i ];
	}

    /// Csúcspontok darabszámának lekérdezése
    /// @return darab
    int getnp() const { return np; }

    /// Adott csúcspont koordinátájának lekérdezése
    /// Nem létező csp. esetén kivételt dob
    /// @param i - i. csúcspont lekérdezése
    /// @return csúcspont koordinátai
    Pont getcsp(unsigned int i) const;

    /// Új csúcspont felvétele
    /// @param p - új csúcspont koordinátai
    void add(const Pont& p);

    /// Poligont rajzol
    void rajzol();

    ~Poligon() { delete[] pontok; }
};

/// Globális << operátor
std::ostream& operator<<(std::ostream&, const Poligon&);

#endif // POLIGON_H
