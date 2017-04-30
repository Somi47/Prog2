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

	virtual std::string GetDataString() override;
};

#endif