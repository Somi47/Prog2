#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

class Ingredient
{
	std::string m_strName;
	std::string m_strUnit;
	int         m_iQuatity;
public:
	Ingredient( std::string strName, std::string strUnit );
	virtual ~Ingredient();

	virtual double GetPrice() = 0;
	virtual double GetAlcoholPercent() = 0 { return 0.0; }
	
	int GetQuatnity();
};

#endif