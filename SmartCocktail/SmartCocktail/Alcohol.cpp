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

void Alcohol::SetAlcoholPercent( const double &dAlcoholPercent )
{
	m_dAlcoholPercent = dAlcoholPercent;
}

std::string Alcohol::GetDataString()
{
	std::string strData;
	strData += "ALCOHOL";
	strData += INGREDIENT_DATA_SEPARATOR;
	strData += Ingredient::GetDataString();
	strData += INGREDIENT_DATA_SEPARATOR;
	strData += std::to_string( m_dAlcoholPercent );

	return strData;
}