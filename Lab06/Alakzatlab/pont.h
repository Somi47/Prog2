/**
 *  \file pont.h
 *  Pont oszt�ly deklar�ci�ja
 */
#ifndef PONT_H
#define PONT_H
#include <iostream>         // ostream miatt kell

/// Pont oszt�ly
/// Az egyszer�s�g kedv��rt minden tagja publikus.
/// �gy nem kell getter, meg setter.
/// Csak azok az operatorok lettek megval�s�tva, melyeket haszn�l a demo
struct Pont {
    int x;
    int y;
    Pont(int x = 0, int y = 0) :x(x), y(y) {}

    /// += operator
    /// @param rhs_p - jobb oldali operandus (Pont)
    /// @return saj�t maga megn�velve
    Pont& operator+=(const Pont& rhs_p);

    /// + operator
    /// @param rhs_p - jobb oldali operandus (Pont)
    /// @return �j objektum (Pont) a k�t pont �sszege
    Pont operator+(const Pont& rhs_p) const;
    /// @return megv� pont
    /// - operator
    /// @param rhs_p - jobb oldali operandus (Pont)
    /// @return �j �j objektum (Pont) a k�t pont k�l�nbs�ge
    Pont operator-(const Pont& rhs_p) const;
};

/// Glob�lis <<< oper�tor
/// @param os - ostream
/// @param p - pont
std::ostream& operator<<(std::ostream& os, const Pont& p);

#endif // PONT_H
