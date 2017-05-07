#ifndef COCKTAIL_H
#define COCKTAIL_H

#include <string>
#include <iostream>
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


///////////////
// Functors: //
///////////////
class FuncCocktailAll
{
public:
	bool operator()( Cocktail * ) { return true; }
};

struct FuncCocktailAlcoholAbove
{
	double m_dAlcoholPercent;
public:
	FuncCocktailAlcoholAbove( double dAlcoholPercent ) : m_dAlcoholPercent( dAlcoholPercent ) {}
	bool operator()( Cocktail *pCocktail ) { return pCocktail->GetAlcoholPercent() > m_dAlcoholPercent; }
};

struct FuncCocktailAlcoholBelow
{
	double m_dAlcoholPercent;
public:
	FuncCocktailAlcoholBelow( double dAlcoholPercent ) : m_dAlcoholPercent( dAlcoholPercent ) {}
	bool operator()( Cocktail *pCocktail ) { return pCocktail->GetAlcoholPercent() < m_dAlcoholPercent; }
};

struct FuncCocktailIngredientAbove
{
	int m_iCount;
public:
	FuncCocktailIngredientAbove( int iCount ) : m_iCount( iCount ) {}
	bool operator()( Cocktail *pCocktail ) { return pCocktail->GetIngredientCount() > m_iCount; }
};

struct FuncCocktailIngredientBelow
{
	int m_iCount;
public:
	FuncCocktailIngredientBelow( int iCount ) : m_iCount( iCount ) {}
	bool operator()( Cocktail *pCocktail ) { return pCocktail->GetIngredientCount() < m_iCount; }
};

#endif // COCKTAIL_H
