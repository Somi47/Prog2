/**
 *  \file pont.cpp
 *  Pont oszt�ly tagf�ggv�nyeinek megval�s�t�sa
 */

#include "pont.h"

/// += operator
Pont& Pont::operator+=(const Pont& rhs_p) {
    x += rhs_p.x;
    y += rhs_p.y;
    return *this;
}

/// - operator
Pont Pont::operator-(const Pont& rhs_p) const {
    return Pont(x-rhs_p.x, y-rhs_p.y);
}

/// + operator
Pont Pont::operator+(const Pont& rhs_p) const {
    return Pont(x+rhs_p.x, y+rhs_p.y);
}

/// Glob�lis << oper�tor
std::ostream& operator<<(std::ostream& os, const Pont& p) {
    return os << "(" << p.x <<"," << p.y << ")";
}
