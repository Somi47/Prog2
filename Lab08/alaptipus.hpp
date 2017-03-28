#ifndef ALAPTIPUS_H
#define ALAPTIPUS_H

template<typename T>
class Alaptipus {
	T adat;
public:
	Alaptipus( T i = 0 ) :adat( i ) {}  /// konstruktor és egyben konverziós operátor
	operator T&() { return adat; }/// cast
	operator T() const { return adat; } /// const cast
};

#endif // ALAPTIPUS_H