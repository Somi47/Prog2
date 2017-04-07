#include "Ingredient.h"

Ingredient::Ingredient()
	: m_strName( "No Name Set" )
	, m_iQuantity( 0 )
{
}

Ingredient::~Ingredient()
{
}

void Ingredient::SetName( const std::string &strName )
{
	m_strName = strName;
}

std::string Ingredient::GetName() const
{
	return m_strName;
}

void Ingredient::SetQuantity( const int &iQuantity )
{
	m_iQuantity = iQuantity;
}

int Ingredient::GetQuantity() const
{
	return m_iQuantity;
}


std::string Ingredient::GetDataString()
{
	std::string strData;
	strData += m_strName;
	strData += INGREDIENT_DATA_SEPARATOR;
	strData += std::to_string( m_iQuantity );

	return strData;
}