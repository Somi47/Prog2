#include "Alcohol.h"

Alcohol::Alcohol()
	: Liquid()
	, m_dAlcoholPercent( 0.0 )
{
}

Ingredient *Alcohol::Clone() const
{
	Alcohol *AlcoholClone = new Alcohol();

	AlcoholClone->m_strName         = m_strName;
	AlcoholClone->m_iQuantity       = m_iQuantity;
	AlcoholClone->m_dAlcoholPercent = m_dAlcoholPercent;

	return AlcoholClone;
}

double Alcohol::GetAlcoholPercent() const
{
	return m_dAlcoholPercent;
}