#ifndef TRAPEZ_H
#define TRAPEZ_H

#include "alakzat.h"

class Trapez : public Alakzat {
	Pont m_offset1, m_offset2, m_offset3;
public:
	Trapez( const Pont& p0, Pont offset1, Pont offset2, Pont offset3, Szin sz )
		:Alakzat( p0, sz ), m_offset1( offset1  ), m_offset2( offset2 ), m_offset3( offset3 )  /// õs osztály inic.
	{}

	Pont getoff1() const { return m_offset1; }
	Pont getoff2() const { return m_offset2; }
	Pont getoff3() const { return m_offset3; }

	void rajzol();
};

/// Globális <<< operátor
std::ostream& operator<<( std::ostream& os, const Trapez& k ) {
	return os << "Trapez " << (Alakzat&)k << ",off1=" << k.getoff1() << ",off2=" << k.getoff2() << ",off3=" << k.getoff3();
}

void Trapez::rajzol()
{
	std::cout << "Rajzol: " << *this << std::endl;
}

#endif

