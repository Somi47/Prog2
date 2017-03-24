#include <iostream>

#ifndef RESISTOR_H
#define RESISTOR_H


#define ARAM_FESZULTSEG

/**
 * Ohmikus ellenállás
 */
class Resistor {
    double R;              	// az ellenállás értéke ohmban
    static double defR;  	// ellenállások alapértelmezett értéke ohmban
                            // ezt a statikus adattagot külön meg kell valósítani
                            // az osztályon kívül.
public:

    /// Kontstruktor.
    /// R alapértelmezett értéket (defR-t) kap
    Resistor();
	Resistor( const Resistor &r );

    /// Kontstruktor.
    /// @param r - ellenállás értéke [ohm]
    Resistor(double r);

    /// Default ellenállásérték beállítása
    /// @param r - ellenállás értéke [ohm]
    static void setDef(double r);

    /// Ellenállás értékének lekérdezése.
    /// @return - ellenállás értéke [ohm]
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

    /// Két ellenállás soros kapcsolása.
    /// @param r - ellenállás
    /// @return  - eredõ ellenállás
    Resistor operator+(const Resistor& r) const;

	Resistor operator=( const Resistor& r );

	bool operator==( const Resistor& r ) const;
	bool operator!=( const Resistor& r ) const;

    /// Két ellenállás párhuzamos kapcsolása.
    /// @param r - ellenállás
    /// @return  - eredõ ellenállás
    Resistor operator%(const Resistor& r) const;

};

/// Többszörös: n darab egyforma r ellenállás összege (soros kapcsolása).
/// @param n - darabszám
/// @param r - ellenállás
/// @return  - eredõ ellenállás
Resistor operator*(int n, const Resistor& r);

std::ostream &operator<<( std::ostream &o, const Resistor& r );

#endif

