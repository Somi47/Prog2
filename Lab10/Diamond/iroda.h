/**
 * \file iroda.h
 * Iroda oszt�ly deklar�ci�ja
 * Az egyszer�s�g kedv��rt minden tagf�ggv�nyt inline val�s�tottunk meg.
 *
 */
#ifndef IRODA_H
#define IRODA_H

#include <vector>
#include "alkalmazott.h"
#include "memtrace.h"


/**
 * Iroda oszt�ly.
 * Standard t�rol�t haszn�l
 */
class Iroda {
    /// saj�t t�pus, hogy k�nnyen le tudjuk cser�lni a t�rol�t
    /// a t�rol� POINTERT t�rol (heterog�n gy�jtem�ny)
    typedef std::vector<Alkalmazott*> tarolo_tipus;
    tarolo_tipus t;
public:
    /// Alkalmazottat vesz fel
    /// @param p - alkalmazott pointere
    void felvesz(Alkalmazott *p) {
        t.insert(t.end(), p);  /// insert met�dusa minden standard t�rol�nak van
    }

    /// Megh�vjuk a t�rol�ban lev� �sszes obj. ki�r met�dus�t
    void kiir(std::ostream& os = std::cout) {
        /// iter�tora minden standard t�rol�nak van
        for (tarolo_tipus::iterator i = t.begin(); i != t.end(); ++i)
            (*i)->kiir(os);  /// figyelje meg az indirekci�t!
    }

    /// Megsz�ntetj�k a t�rolt objektumokat
    ~Iroda() {
        for (tarolo_tipus::iterator i = t.begin(); i != t.end(); ++i)
            delete *i;      /// figyelje meg az indirekci�t!
    }
};

#endif // IRODA_H
