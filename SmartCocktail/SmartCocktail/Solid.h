#ifndef SOLID_H
#define SOLID_H

#include "Ingredient.h"

class Solid : public Ingredient
{
protected:
	std::string m_strUnit;
public:
	Solid();

	virtual Ingredient *Clone() const;
	static Solid *Create( std::ostream &os, std::istream &is );

	virtual std::string GetUnit()           const;
	virtual double      GetVolume()         const;
	virtual double      GetAlcoholPercent() const;

	void SetUnit( const std::string &strUnit );

	virtual void WriteData( std::ostream &os ) override;
	virtual void ReadData ( std::istream &is ) override;
};

#endif