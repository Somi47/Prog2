#include "Solid.h"

Solid::Solid()
	: Ingredient()
	, m_strUnit( "No Unit Set" )
{
}

Ingredient *Solid::Clone() const
{
	Solid *SolidClone = new Solid();

	SolidClone->m_strName   = m_strName;
	SolidClone->m_iQuantity = m_iQuantity;
	SolidClone->m_strUnit   = m_strUnit;

	return SolidClone;
}

std::string Solid::GetUnit() const
{
	return m_strUnit;
}

double Solid::GetVolume() const
{
	return 0.0;
}

double Solid::GetAlcoholPercent() const
{
	return 0.0;
}

void Solid::SetUnit( const std::string &strUnit )
{
	m_strUnit = m_strUnit;
}