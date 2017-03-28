#ifndef MYSET_H
#define MYSET_H

template<typename T>
bool equal( const T &x, const T &y )
{
	return x == y;
}

template<>
bool equal<Point>( const Point &x, const Point &y )
{
	return x.getX() == y.getX();
}

template<typename T, int ALLOCSIZE = 10, bool T_cmp(const T&, const T&) = equal>
class Set {
	int iSize;
	T*  arrData;
public:
	Set() :iSize( 0 ), arrData( new T[ ALLOCSIZE ] ) {}
	~Set() { delete[] arrData; }

	int size() { return iSize; }

	bool isElement( const T &obj ) {
		if( &obj == NULL )
			throw std::exception( "Null reference" );

		for( int i = 0; i < iSize; ++i )
			if( T_cmp(arrData[ i ], obj ) )
				return true;

		return false;
	}

	void insert( const T &obj )
	{
		if( isElement( obj ) )
			return;

		++iSize;
		if( iSize > ALLOCSIZE )
			throw std::out_of_range( "Inserting to full set" );

		arrData[ iSize - 1 ] = obj;
	}
};

#endif // MYSET_H