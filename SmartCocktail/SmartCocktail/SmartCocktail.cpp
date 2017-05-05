#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "SmartArray.hpp"
#include "Cocktail.h"
#include "Ingredient.h"
#include "Solid.h"
#include "Liquid.h"
#include "Alcohol.h"

using namespace std;

SmartArray<Cocktail *> *g_arrCocktail;

void test()
{
	Cocktail cocktailTest01;
	cocktailTest01.SetName( "Tequila Sunrise" );

	Alcohol *pTequila = new Alcohol();
	pTequila->SetName( "Don Jacinto Tequila Silver" );
	pTequila->SetQuantity( 4 );
	pTequila->SetAlcoholPercent( 0.40 );
	cocktailTest01.AddIngredient( pTequila );

	Liquid *pOrangeJuice = new Liquid();
	pOrangeJuice->SetName( "Orange Juice" );
	pOrangeJuice->SetQuantity( 15 );
	cocktailTest01.AddIngredient( pOrangeJuice );

	Solid *pOrangeSlice = new Solid();
	pOrangeSlice->SetName( "Orange Slice" );
	pOrangeSlice->SetQuantity( 1 );
	pOrangeSlice->SetUnit( "piece" );
	cocktailTest01.AddIngredient( pOrangeSlice );

	cocktailTest01.WriteData( cout );
	cout << "Alcohol percent:" << cocktailTest01.GetAlcoholPercent() * 100 << "%" << endl << endl;


	stringstream strstream;
	cocktailTest01.WriteData( strstream );

	Cocktail cocktailRead;
	cocktailRead.ReadData( strstream );
	cocktailRead.WriteData( cout );
}

void load_cocktails()
{
	ifstream f( "data.txt" );

	if( f.fail() )
	{
		cerr << "Failed to open" << endl;
		return;
	}

	while( !f.eof() )
	{
		Cocktail *pCocktail = new Cocktail();
		pCocktail->ReadData( f );

		g_arrCocktail->InsertLast( pCocktail );
	}

	f.close();
}

void menu_dialog()
{
	system( "cls" );
	cout << "SmartCocktail" << endl << endl;

	cout << "0. Exit" << endl;
	cout << "1. List exixting cocktails" << endl;
	cout << "2. Add cocktail" << endl;
	cout << "3. Save" << endl;

	cout << endl;
}

void list()
{
	system( "cls" );

	for( int i = 0; i < g_arrCocktail->GetCount(); ++i )
	{
		cout << i + 1 << ". ";
		cout << g_arrCocktail->GetPosition( i )->GetName() << endl;
	}

	cout << endl << endl;
	cout << "0. To Exit" << endl;
	cout << "#. To list raw data of cocktail" << endl;

	int iChoice;
	while( true )
	{
		cin >> iChoice;

		if( iChoice == 0 )
		{
			return;
		}
		else
		{
			if( iChoice - 1 < g_arrCocktail->GetCount() )
				g_arrCocktail->GetPosition( iChoice - 1 )->WriteData( cout );
		}
	}
}

void run()
{
	menu_dialog();

	int iChoice;
	while( true )
	{
		cin >> iChoice;

		switch( iChoice )
		{
			case 0: return;
			case 1: list(); break;

			default:
				break;
		}

		menu_dialog();
	}
}

int main()
{
	SmartArray<Cocktail *> arrCocktail;
	g_arrCocktail = &arrCocktail;

	load_cocktails();
	run();

	for( int i = 0; i < arrCocktail.GetCount(); ++i )
		delete arrCocktail.GetPosition( i );

	return 0;
}