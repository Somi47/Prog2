#ifndef HAROMSZOG_H
#define HAROMSZOG_H

#include "alakzat.h"

class Haromszog : public Alakzat {
	Pont m_offset1, m_offset2;
public:
	Haromszog( const Pont& p0, Pont offset1, Pont offset2, Szin sz )
		:Alakzat( p0, sz ), m_offset1( offset1  ), m_offset2( offset2 )  /// õs osztály inic.
	{}

	Pont getoff1() const { return m_offset1; }
	Pont getoff2() const { return m_offset2; }

	void rajzol();
};

/// Globális <<< operátor
std::ostream& operator<<( std::ostream& os, const Haromszog& k ) {
	return os << "Haromszog " << (Alakzat&)k << ",off1=" << k.getoff1() << ",off2=" << k.getoff2();
}

void Haromszog::rajzol()
{
	std::cout << "Rajzol: " << *this << std::endl;
}

#endif

