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

	void        AddIngredient( Ingredient *pIngredient );
	void        DelIngredient( int iPos );
	Ingredient *GetIngredient( int iPos );
	int         GetIngredientCount();

	double GetAlcoholPercent() const;

	void WriteData( std::ostream &os ) const;
	void ReadData ( std::istream &is );
};

#endif // COCKTAIL_H
