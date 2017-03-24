/**
 * \file komplex.cpp
 *
 * Komplex osztályt megvalósító függvények definíciója
 *
 * Folytassa a megvalósítást a complex.h fájlban levő
 * feladatoknak megfelelően!
 *
 */

// Valószínű, hogy a kiíráshoz majd kell
#include <iostream>
// ... és ez is.
#include <iomanip>
// Valószínű, hogy az abszolútértékhez majd kell.
#include <cmath>
// Ebben van a Komplex osztály, és néhány globális függvény deklarációja
#include "komplex.h"
//using namespace std;  // ha nagyon kell, akkor csak itt nyissuk ki a névteret

#define ABS( x ) x < 0 ? -(x) : x

// 0, 1 és 2 paraméteres konstruktor
// Figyelje meg, hogy a default argumentumokat CSAK a deklarációnál
// adtuk meg!
Komplex::Komplex()
	: re( 0.0 )
	, im( 0.0 )
{
}

Komplex::Komplex( double r )
	: re( r )
	, im( 0.0 )
{
}

Komplex::Komplex(double r, double im) {
    re = r; // ha nincs névütközés, nem kell kiírni a this-t
    this->im = im;
}

double Komplex::getRe() const
{
    return re;
}

double Komplex::getIm() const
{
    return im;
}

void Komplex::setRe(double re)
{
    this->re = re;
}

void Komplex::setIm(double im)
{
    this->im = im;
}

bool Komplex::operator==(const Komplex& rhs_k) const
{
    if( ABS( this->re - rhs_k.re ) > 0.00001 )
        return false;

    if( ABS( this->im - rhs_k.im ) > 0.00001 )
        return false;

    return true;
}

// Előre elkészített tagfüggvények

#if ELKESZULT >= 3
// 3. feladathoz (ELKESZULT 3)
// összehasonlítás
/// Egyenlőtlenség vizsgálat
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return hamis - ha a képzeets és a valós rész is azonos, egyébként false
bool Komplex::operator!=(const Komplex& rhs_k) const {  // visszavezetjük az egyenlőség vizsgálatra
    return !(*this == rhs_k);
}
#endif

Komplex Komplex::operator+(const Komplex& rhs_k) const
{
    double newre = this->re + rhs_k.re;
    double newim = this->im + rhs_k.im;

    return Komplex( newre, newim );
}

Komplex Komplex::operator+(double rhs_d) const
{
    double newre = this->re + rhs_d;
    double newim = this->im;

    return Komplex( newre, newim );
}

Komplex operator+(double lhs_d, const Komplex& rhs_k)
{
    double newre = rhs_k.getRe() + lhs_d;
    double newim = rhs_k.getIm();

    return Komplex( newre, newim );
}

#if ELKESZULT >= 5
// 5. feladathoz (ELKESZULT 5)
// a += művelet viszont módosítja önmagát!
/// Komplex + double
/// @param rhs_d - jobb oldali operandus (double)
/// @return eredeti (bal oldali) objektum ref., amihez hozzáadtuk rhd_d-t
Komplex& Komplex::operator+=(double rhs_d) {
    re += rhs_d;
    return *this;
}
#endif

Komplex& Komplex::operator+=(const Komplex& rhs_k)
{
    re += rhs_k.re;
    im += rhs_k.im;
    return *this;
}

double Komplex::abs() const
{
    double r = sqrt( re * re + im * im );
    return r;
}

std::ostream& operator<<(std::ostream& os, const Komplex& rhs_k)
{
    os << rhs_k.getRe();
    if( rhs_k.getIm() >= 0 )
        os << '+';
    os << rhs_k.getIm() << 'j';
    return os;
}

std::istream& operator>>(std::istream& is, Komplex& rhs_k)
{
    double re = 0.0;
    double im = 0.0;
    is >> re;
    is >> im;
    rhs_k.setRe( re );
    rhs_k.setIm( im );

    char dump;
    is >> dump;

    return is;
}

Komplex Komplex::operator~() const
{
    return Komplex( re, -im );
}

Komplex Komplex::operator*(const Komplex& rhs_k) const
{
    double aa = + re * rhs_k.re;
    double ab = + re * rhs_k.im;
    double ba = + im * rhs_k.re;
    double bb = - im * rhs_k.im;

    return Komplex( aa + bb, ab + ba );
}

Komplex Komplex::operator*(double rhs_d) const
{
    return Komplex( re * rhs_d, im * rhs_d );
}

Komplex& Komplex::operator*=(const Komplex& rhs_k)
{
    double aa = + re * rhs_k.re;
    double ab = + re * rhs_k.im;
    double ba = + im * rhs_k.re;
    double bb = - im * rhs_k.im;

    re = aa + bb;
    im = ab + ba;

    return *this;
}

Komplex& Komplex::operator*=(double rhs_d)
{
    re = re * rhs_d;
    im = im * rhs_d;

    return *this;
}

// TODO: A hiányzó tag- és globális függvények itt következnek

