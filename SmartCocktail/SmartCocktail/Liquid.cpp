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

std::string Liquid::GetDataString()
{
	std::string strData;
	strData += "LIQUID";
	strData += INGREDIENT_DATA_SEPARATOR;
	strData += Ingredient::GetDataString();

	return strData;
}