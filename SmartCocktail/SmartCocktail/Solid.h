#ifndef SOLID_H
#define SOLID_H

#include "Ingredient.h"

class Solid : public Ingredient
{
protected:
	std::string m_strUnit;
public:
	virtual Ingredient *Clone() const;

	virtual std::string GetUnit()           const;
	virtual double      GetVolume()         const;
	virtual double      GetAlcoholPercent() const;

	void SetUnit( const std::string &strUnit );
};

#endif