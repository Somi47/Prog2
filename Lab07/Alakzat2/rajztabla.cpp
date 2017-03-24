/**
 *  \file rajztabla.cpp
 *   Rajztábla osztály tagfüggvényinek megvalósítása
 */

#include <stdexcept>
#include "rajztabla.h"

// felrak
void Rajztabla::felrak(Alakzat *a) {
    if (db >= MAXDB) throw std::out_of_range("Rajztabla: megtelt");
    tabla[db++] = a;
}

// rajzol
void Rajztabla::rajzol() {
    for (int i = 0; i < db; i++)
        tabla[i]->rajzol();
}

// mozgat
void Rajztabla::mozgat(const Pont& d) {
    for (int i = 0; i < db; i++)
        tabla[i]->mozgat(d);
}

// töröl
void Rajztabla::torol() {
    for (int i = 0; i < db; i++)
        delete tabla[i];
    db = 0;
}
