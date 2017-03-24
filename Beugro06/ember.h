/*
 * \file kutato.h
 *
 * Kutato osztály deklarációja
 * Az egyszerűség kedvéért minimális funkcionalitás, inline függvényekkel.
 */
#ifndef EMBER_H
#define EMBER_H

class Ember
{
protected:
	char* nev;
	int szulEv;
public:
    /// Konstruktor
    /// @param n  - név
    /// @param ev - születési év
	Ember( const char *n = "WGGAW5", int ev = 1996 );
	Ember( const Ember& e );

	virtual ~Ember();
	virtual Ember& operator=( const Ember& e );
	virtual const char* getNev() const;
	virtual int getKor( int ev ) const;
	virtual const char* foglalkozas() const;
};

#endif
