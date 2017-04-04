#ifndef SMARTARRAY_H
#define SMARTARRAY_H

template <typename T>
class SmartArray
{
	int   m_iReserved;
	int   m_iCount;
	T    *m_pData;
public:
	SmartArray();
	SmartArray( SmartArray &other );
	virtual ~SmartArray();

	int GetReserved() const;
	int GetCount() const;

	void ReserveTotal( int iReserve );
	void ReserveMore( int iReserve );

	void InsertLast( const T& tObject );

	T &GetPosition( int iPos );

	      T &operator[]( int iIndex );
	const T &operator[]( int iIndex ) const;
};

template <typename T>
SmartArray< T >::SmartArray()
	: m_iReserved( 0 )
	, m_iCount( 0 )
	, m_pData( NULL )
{
}


template <typename T>
SmartArray< T >::~SmartArray()
{
	delete[] m_pData;
}

template <typename T>
SmartArray< T >::SmartArray( SmartArray &other )
	: m_iReserved( other.m_iReserved )
	, m_iCount( other.m_iCount )
	, m_pData( new T[ other.m_iReserved ] )
{
	for( int i = 0; i < m_iSize; ++i )
		m_pData[ i ] = other.m_pData[ i ];
}

template <typename T>
int SmartArray< T >::GetReserved() const
{
	return m_iReserved;
}

template <typename T>
int SmartArray< T >::GetCount() const
{
	return m_iCount;
}

template <typename T>
void SmartArray< T >::ReserveTotal( int iReserve )
{
	if( m_iReserved < iReserve )
		return;

	m_iReserved = iReserve < 8 ? 8 : iReserve;
	T *pDataNew = new T[ m_iReserved ];
	for( int i = 0; i < m_iCount; ++i )
		pDataNew[ i ] = m_pData[ i ];

	delete[] m_pData;
	m_pData = pDataNew;
}

template <typename T>
void SmartArray< T >::ReserveMore( int iReserve )
{
	ReserveTotal( m_iReserved + iReserve );
}

template <typename T>
void SmartArray< T >::InsertLast( const T& tObject )
{
	if( m_iCount == m_iReserved )
		ReserveTotal( m_iReserved * 2 );

	m_pData[ m_iCount ] = tObject;
	++m_iCount;
}

template <typename T>
T &SmartArray< T >::GetPosition( int iPos )
{
	return operator[]( iPos );
}

template <typename T>
T &SmartArray< T >::operator[]( int iIndex )
{
	if( iIndex >= m_iCount )
		throw std::out_of_range( "iIndex >= m_iCount" );

	return m_pData[ iIndex ];
}


template <typename T>
const T &SmartArray< T >::operator[]( int iIndex ) const
{
	if( iIndex >= m_iCount )
		throw std::out_of_range( "iIndex >= m_iCount" );

	return m_pData[ iIndex ];
}

#endif