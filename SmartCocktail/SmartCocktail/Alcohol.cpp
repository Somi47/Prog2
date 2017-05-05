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

void Alcohol::WriteData( std::ostream &os )
{
	os << "ALCOHOL" << std::endl;
	Ingredient::WriteData( os );
	os << m_dAlcoholPercent << std::endl;
}

void Alcohol::ReadData( std::istream &is )
{
	Liquid::ReadData( is );
	is >> m_dAlcoholPercent;
	is.ignore( 1 );
}