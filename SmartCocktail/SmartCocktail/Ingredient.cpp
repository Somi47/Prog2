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

void Ingredient::WriteData( std::ostream &os )
{
	os << "Name: " << m_strName << std::endl;
	os << "Quantity: " << m_iQuantity << std::endl;
}

void Ingredient::ReadData( std::istream &is )
{
	is.ignore( 6 );
	std::getline( is, m_strName );
	is.ignore( 10 );
	is >> m_iQuantity;
	is.ignore( 1 );
}