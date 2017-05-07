#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include <iostream>

class Ingredient
{
// No copy allowed:
	Ingredient( Ingredient &other ) {};
protected:
	std::string m_strName;
	int         m_iQuantity;
public:
	Ingredient();
	virtual ~Ingredient();
	virtual Ingredient *Clone() const = 0;

	virtual std::string GetUnit()           const = 0;
	virtual double      GetVolume()         const = 0;
	virtual double      GetAlcoholPercent() const = 0;

	void        SetName( const std::string &strName );
	std::string GetName() const;

	void SetQuantity( const int &iQuantity );
	int  GetQuantity() const;

	virtual void WriteData( std::ostream &os );
	virtual void ReadData ( std::istream &is );
};

#endif