/**
 *  \file szin.cpp
 *  Szin f�ggv�nyeinek megval�s�t�sa
 */
#include "szin.h"

// Szinek sz�vegkonstansai
static const char* szinek[] = { "BLACK", "WHITE", "RED", "GREEN", "BLUE" } ;

/// Glob�lis <<< oper�tor
/// Nincs ellen�rz�s a t�lindexel�sre !
std::ostream& operator<<(std::ostream& os, Szin sz) {
     return os << szinek[sz];
}
