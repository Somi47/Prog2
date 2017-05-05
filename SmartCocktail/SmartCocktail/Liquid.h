#ifndef LIQUID_H
#define LIQUID_H

#include "Ingredient.h"

class Liquid : public Ingredient
{
public:
	Liquid();

	virtual Ingredient *Clone() const;

	virtual std::string GetUnit()           const;
	virtual double      GetVolume()         const;
	virtual double      GetAlcoholPercent() const;

	virtual void WriteData( std::ostream &os ) override;
	virtual void ReadData ( std::istream &is ) override;
};

#endif