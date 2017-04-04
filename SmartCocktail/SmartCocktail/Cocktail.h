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
};

#endif // COCKTAIL_H
