#include <iostream>

#ifndef RESISTOR_H
#define RESISTOR_H


#define ARAM_FESZULTSEG

/**
 * Ohmikus ellen�ll�s
 */
class Resistor {
    double R;              	// az ellen�ll�s �rt�ke ohmban
    static double defR;  	// ellen�ll�sok alap�rtelmezett �rt�ke ohmban
                            // ezt a statikus adattagot k�l�n meg kell val�s�tani
                            // az oszt�lyon k�v�l.
public:

    /// Kontstruktor.
    /// R alap�rtelmezett �rt�ket (defR-t) kap
    Resistor();
	Resistor( const Resistor &r );

    /// Kontstruktor.
    /// @param r - ellen�ll�s �rt�ke [ohm]
    Resistor(double r);

    /// Default ellen�ll�s�rt�k be�ll�t�sa
    /// @param r - ellen�ll�s �rt�ke [ohm]
    static void setDef(double r);

    /// Ellen�ll�s �rt�k�nek lek�rdez�se.
    /// @return - ellen�ll�s �rt�ke [ohm]
    double getR() const {
        return R;
    }

	double getI( double U ) const {
		if( R == 0.0 )
			throw "WGGAW5";

		return U / R;
	}

	double getU( double I ) const {
		return I * R;
	}

    /// K�t ellen�ll�s soros kapcsol�sa.
    /// @param r - ellen�ll�s
    /// @return  - ered� ellen�ll�s
    Resistor operator+(const Resistor& r) const;

	Resistor operator=( const Resistor& r );

	bool operator==( const Resistor& r ) const;
	bool operator!=( const Resistor& r ) const;

    /// K�t ellen�ll�s p�rhuzamos kapcsol�sa.
    /// @param r - ellen�ll�s
    /// @return  - ered� ellen�ll�s
    Resistor operator%(const Resistor& r) const;

};

/// T�bbsz�r�s: n darab egyforma r ellen�ll�s �sszege (soros kapcsol�sa).
/// @param n - darabsz�m
/// @param r - ellen�ll�s
/// @return  - ered� ellen�ll�s
Resistor operator*(int n, const Resistor& r);

std::ostream &operator<<( std::ostream &o, const Resistor& r );

#endif

