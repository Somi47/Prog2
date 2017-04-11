/**
 * \file irodistak.h
 * Minden sz�rmaztatott oszt�ly deklar�ci�j�t ebbe e f�jlba tett�k.
 * Az egyszer�s�g kedv��rt minden tagf�ggv�nyt inline val�s�tottunk meg.
 *
 */
#ifndef IRODISTAK_H
#define IRODISTAK_H

#include <iostream>
#include <string>

#include "alkalmazott.h"

typedef int csop_t;             // csoport tipusa

/**
 * Csoportvezet�
 */
class  CsopVez : virtual       public Alkalmazott {
    csop_t   csoport;           // csoport azon.
public:
    CsopVez(const std::string& n, double f, csop_t cs)
        : Alkalmazott(n, f),     // alaposzt�ly inicializ�l�sa
          csoport(cs)            // csoport inicializ�l�s
    {}

    csop_t getCs() const {               // csoport lek�rdez�se
        return csoport;
    }

    void setCs(csop_t cs) {
        csoport = cs;
    }

    void kiir(std::ostream& os = std::cout) const {
        os << "CsopVez: ";
        Alkalmazott::kiir(os);
    }
};

/**
 * Hat�rozott idej� alkalmazott
 */
class HatIdeju : virtual public Alkalmazott {
protected:
    time_t  ido;                // szerz�d�se lej�r ekkor
public:
    HatIdeju(const std::string& n, double f, time_t t)
        : Alkalmazott(n, f),    // alaposzt�ly inicializ�l�sa
          ido(t)                // ido inicializ�l�s
    {}

    time_t getIdo() const {
        return ido;
    }

    void setIdo(time_t t) {
        ido = t;
    }

    void kiir(std::ostream& os = std::cout) const {
        std::cout << "HatIdeju: ";
        Alkalmazott::kiir(os);
    }
};

/**
 * Hat�rozott idej� csoportvezet�
 */
class HatIdCsV : public CsopVez, public HatIdeju {
public:
    HatIdCsV(const  std::string& n, double f, csop_t cs, time_t t)
        : Alkalmazott( n, f ),   // virtu�lis alaposzt�lyn�l ide kell majd valami
          CsopVez(n, f*2, cs),  // sz�nd�kosan m�s fizet�st kap,
          HatIdeju(n, f*10, t) // hogy l�that� legyen az adatduplik�ci�
             // majd ide kell az Alkalmazott(n, f)
    {}

    void kiir(std::ostream& os = std::cout) const {
        std::cout << "HatIdCsv:" << std::endl << "   ";
        CsopVez::kiir(os);
        std::cout << "   ";
        HatIdeju::kiir(os);
    }
};

/**
 * Hat�rozott idej� csoportvezet� helyettes
 */
class HatIdCsVezH :public HatIdCsV {
public:
    HatIdCsVezH(const std::string& n, double f, time_t t, CsopVez& kit)
        : Alkalmazott( n, f ), // virtu�lis alaposzt�lyn�l ide kell majd valami
          HatIdCsV(n, f, kit.getCs(), t)// alaposzt�ly
    {}

    void kiir(std::ostream& os = std::cout) const {
        std::cout << "HatIdCsVezH: ";
        HatIdCsV::kiir(os);
    }
};
#endif // IRODISTAK_H
