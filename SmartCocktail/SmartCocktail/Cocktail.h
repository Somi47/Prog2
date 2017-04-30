#ifndef COCKTAIL_H
#define COCKTAIL_H

#include <string>
#include "SmartArray.hpp"

class Ingredient;

class Cocktail
{
	std::string              m_strName;
	SmartArray<Ingredient *> m_arrIngredients;
public:
	Cocktail();
	Cocktail( const Cocktail &other );
	virtual ~Cocktail();

	void        SetName( const std::string &strName );
	std::string GetName() const;

	void AddIngredient( Ingredient *pIngredient );
	void DelIngredient( int iPos );

	double GetAlcoholPercent() const;

	std::string GetDataString() const;
};

#endif // COCKTAIL_H
