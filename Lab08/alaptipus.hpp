#ifndef ALAPTIPUS_H
#define ALAPTIPUS_H

template<typename T>
class Alaptipus {
	T adat;
public:
	Alaptipus( T i = 0 ) :adat( i ) {}  /// konstruktor �s egyben konverzi�s oper�tor
	operator T&() { return adat; }/// cast
	operator T() const { return adat; } /// const cast
};

#endif // ALAPTIPUS_H