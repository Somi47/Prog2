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

	T &GetPosition( int iPos ) const;

	      T &operator[]( int iIndex );
	const T &operator[]( int iIndex ) const;

	void Sort( int( *cmp )( T &obj1, T &obj2 ) );
};

template <typename T>
SmartArray< T >::SmartArray()
	: m_iReserved( 0 )
	, m_iCount( 0 )
	, m_pData( NULL )
{
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
int SmartArray< T >::GetReserved()
{
	return m_iReserved;
}

template <typename T>
int SmartArray< T >::GetCount()
{
	return m_iCount;
}

template <typename T>
void SmartArray< T >::ReserveTotal( int iReserve )
{
	m_iReserved = iReserve;
	T *pDataNew = new T[ iReserve ];
	for( int i = 0; i < m_iCount; ++i )
		pDataNew[ i ] = m_pData[ i ];

	delete[] m_pData;
	m_pData
}

template <typename T>
void SmartArray< T >::ReserveMore( int iReserve )
{
	ReserveTotal( m_iReserved + iReserve );
}

#endif