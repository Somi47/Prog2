#include "Liquid.h"

Liquid::Liquid()
	: Ingredient()
{
}

Ingredient *Liquid::Clone() const
{
	Liquid *LiquidClone = new Liquid();

	LiquidClone->m_strName   = m_strName;
	LiquidClone->m_iQuantity = m_iQuantity;

	return LiquidClone;
}

Liquid *Liquid::Create( std::ostream &os, std::istream &is )
{
	Liquid *pLiquid = new Liquid();

	os << "Name: ";
	is.ignore();
	getline( is, pLiquid->m_strName );
	os << "Quantity in cl: ";
	is >> pLiquid->m_iQuantity;

	return pLiquid;
}

std::string Liquid::GetUnit() const
{
	return "cl";
}

double Liquid::GetVolume() const
{
	return m_iQuantity;
}

double Liquid::GetAlcoholPercent() const
{
	return 0.0;
}

void Liquid::WriteData( std::ostream &os )
{
	os << "LIQUID" << std::endl;
	Ingredient::WriteData( os );
}

void Liquid::ReadData( std::istream &is )
{
	Ingredient::ReadData( is );
}