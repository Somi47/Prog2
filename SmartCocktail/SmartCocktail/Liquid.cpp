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