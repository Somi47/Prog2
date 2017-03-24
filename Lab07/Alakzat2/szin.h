/**
 *  \file szin.h
 *  Szin deklar�ci�ja
 */
#ifndef SZIN_H
#define SZIN_H

#include <iostream>     // ostream miatt kell

/// Sz�n
enum Szin { BLACK, WHITE, RED, GREEN, BLUE };

/// H�tt�rsz�n
const Szin BACKGND = BLACK;

/// Glob�lis << oper�tor
std::ostream& operator<<(std::ostream& os, Szin sz);
#endif // SZIN_H
