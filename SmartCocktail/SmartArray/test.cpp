#include <iostream>
#include "SmartArray.hpp"

using namespace std;

int main()
{
	SmartArray<int> smInt;
	
	smInt.InsertLast( 666 );
	smInt.InsertLast( 321 );
	smInt.InsertLast( 3213 );
	smInt.InsertLast( 54 );
	smInt.InsertLast( 645 );
	smInt.InsertLast( 312 );
	smInt.InsertLast( 99 );
	smInt.InsertLast( 77 );
	smInt.InsertLast( 19 );

	smInt.RemovePosition( 0 );
	smInt.RemovePosition( 2 );
	smInt.RemovePosition( smInt.GetCount() - 1 );

	try
	{
		for( int i = 0; i <= smInt.GetCount(); ++i )
			cout << smInt[ i ]++ << " ++ " << smInt.GetPosition( i ) << endl;
	}
	catch( std::out_of_range &exc )
	{
		cout << "std::out_of_range handled: " << exc.what();
	}

}