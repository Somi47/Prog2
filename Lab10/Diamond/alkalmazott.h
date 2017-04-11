/**
 * \file alkalmazott.h
 * Alkalmazott alaposzt�ly deklar�ci�ja
 * Az egyszer�s�g kedv��rt minden tagf�ggv�nyt inline val�s�tottunk meg.
 *
 */

#ifndef ALKALMAZOTT_H
#define ALKALMAZOTT_H

#include <iostream>
#include <string>
#include "memtrace.h"


/// header f�jlban ne haszn�ljon using direkt�v�t, mert a hat�sa
/// rejtve marad

/**
 * Alkalmazott
 */
class Alkalmazott {
    std::string   nev;          // nev
    double   fizetes;           // fizet�s
public:
    Alkalmazott() :fizetes(0) {
        std::cout << "Baj van: Az Alkalmazott default konstruktora hivodott!" << std::endl
                  << "         Javitsa a kodot!" << std::endl;
    }

    Alkalmazott(const  std::string& n, double fiz) :nev(n), fizetes(fiz) {
#if TESTLEVEL <= 1
        std::cout << 'A';
#endif
    }

    /// N�v lek�rdez�se
    /// @return - nev
    const std::string& getNev() const { return nev; }

    /// Fizet�s lek�rdez�se
    /// @return - fizet�s
    double getFiz() const { return fizetes; }

    /// N�v be�ll�t�sa
    /// @param nev - n�v
    void setNev(const std::string& n) { nev = n; }


    /// Fizet�s be�ll�t�sa
    /// @param fiz - fizet�s
    void setFiz(double fiz) { fizetes = fiz; }

    /// Adatok ki�r�sa
    /// @param os - output adatfolyam
    virtual void kiir(std::ostream& os = std::cout) const {
        os << nev << " fizetese: " << fizetes << std::endl;
    }

    virtual ~Alkalmazott() {
#if TESTLEVEL <= 1
        std::cout << "Megszunik: ";
        kiir(std::cout);
#endif
    }
};
#endif // ALKALMAZOTT_H

