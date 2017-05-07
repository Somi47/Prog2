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

Solid *Solid::Create( std::ostream &os, std::istream &is )
{
	Solid *pSolid = new Solid();

	os << "Name: ";
	is.ignore();
	getline( is, pSolid->m_strName );
	os << "Quantity: ";
	is >> pSolid->m_iQuantity;
	os << "Unit: ";
	is.ignore();
	getline( is, pSolid->m_strUnit );

	return pSolid;
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
	m_strUnit = strUnit;
}

void Solid::WriteData( std::ostream &os )
{
	os << "SOLID" << std::endl;
	Ingredient::WriteData( os );
	os << m_strUnit << std::endl;
}

void Solid::ReadData( std::istream &is )
{
	Ingredient::ReadData( is );
	std::getline( is, m_strUnit );
}