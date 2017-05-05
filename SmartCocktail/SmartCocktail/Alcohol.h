#ifndef ALCOHOL_H
#define ALCOHOL_H

#include "Liquid.h"

class Alcohol : public Liquid
{
protected:
	double m_dAlcoholPercent;
public:
	Alcohol();

	virtual Ingredient *Clone() const;

	virtual double GetAlcoholPercent() const;

	void SetAlcoholPercent( const double &dAlcoholPercent );

	virtual void WriteData( std::ostream &os ) override;
	virtual void ReadData ( std::istream &is ) override;
};

#endif