#ifndef TEGLALAP_H
#define TEGLALAP_H

#include "alakzat.h"

class Teglalap : public Alakzat {
	int m_width, m_height;
public:
	Teglalap( const Pont& p0, int width, int height, Szin sz )
		:Alakzat( p0, sz ), m_width( width ), m_height( height )  /// õs osztály inic.
	{}

	int getw() const { return m_width; }
	int geth() const { return m_height; }

	void rajzol();
};

/// Globális <<< operátor
std::ostream& operator<<( std::ostream& os, const Teglalap& k ) {
	return os << "Teglalap " << (Alakzat&)k << ",w=" << k.getw() << ",h=" << k.geth();
}

void Teglalap::rajzol()
{
	std::cout << "Rajzol: " << *this << std::endl;
}

#endif

