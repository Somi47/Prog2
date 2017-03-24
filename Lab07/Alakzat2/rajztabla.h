/**
 *  \file rajztabla.h
 *  Rajztabla osztály deklarációja
 */

#ifndef RAJZTABLA_H
#define RAJZTABLA_H

#include "alakzat.h"

/// Rajztabla osztály
class Rajztabla  {
    static const int MAXDB = 100;   ///< maximum ennyi fér bele
    Alakzat* tabla[MAXDB];          ///< tároló
    int db;                         ///< aktuális darabszám
    Rajztabla(const Rajztabla&);    ///< ne lehessen használni
    Rajztabla& operator=(const Rajztabla &); ///< ne lehessen használni
public:
    Rajztabla() :db(0) { }

    /// Alakzatot tesz a rajztáblára
    /// @param ap - pointer az alakzatra
    void felrak(Alakzat *ap);       // Alakzatot tesz a rajztáblára

    /// Kirajzolja az összes alakzatot
    void rajzol();                  // Felrajzol minden alakzatot

    /// Az összes alakzatot elmozdítja
    /// @param d - eltolás vektora
    void mozgat(const Pont& d);     // Elmozgat d-vel minden alakzatot

    /// letörli a táblát
    void torol();                   // Letörli a táblát

    ~Rajztabla() { torol(); }
};

#endif // RAJZTABLA_H
