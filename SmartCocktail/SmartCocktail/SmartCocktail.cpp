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

SmartArray<Cocktail *> *g_parrCocktail;

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

		g_parrCocktail->InsertLast( pCocktail );
	}

	f.close();
}

void menu_dialog()
{
#ifndef CPORTA
	system( "cls" );
#endif 
	cout << "SmartCocktail" << endl << endl;

	cout << "0. Exit" << endl;
	cout << "1. List existing cocktails" << endl;
	cout << "2. Filter existing cocktails" << endl;
	cout << "3. Edit cocktail" << endl;
	cout << "4. Add cocktail" << endl;
	cout << "5. Delete cocktail" << endl;
	cout << "6. Save" << endl;

	cout << endl;
}

template< class Predi >
void list( Predi cmp )
{
#ifndef CPORTA
	system( "cls" );
#endif 

	for( int i = 0; i < g_parrCocktail->GetCount(); ++i )
	{
		Cocktail *pCocktail = g_parrCocktail->GetPosition( i );
		if( cmp( pCocktail ) == false )
			continue;

		cout << i + 1 << ". ";
		cout << pCocktail->GetName() << endl;
	}

	cout << endl << endl;
	cout << "0. To Exit" << endl;
	cout << "#. To list raw data of cocktail" << endl;

	int iChoice;
	while( true )
	{
		cin >> iChoice;

		if( iChoice <= 0 )
		{
			return;
		}
		else
		{
			if( iChoice - 1 < g_parrCocktail->GetCount() )
			{
				g_parrCocktail->GetPosition( iChoice - 1 )->WriteData( cout );
				cout << endl;
			}
		}
	}
}

void filter()
{
#ifndef CPORTA
	system( "cls" );
#endif 

	cout << "0. Exit" << endl;
	cout << "1. List alcohol percent above" << endl;
	cout << "2. List alcohol percent below" << endl;
	cout << "3. List ingredient count above" << endl;
	cout << "4. List ingredient count below" << endl;

	int iChoice;
	cin >> iChoice;

	if( iChoice <= 0 || iChoice > 4 )
		return;

	if( iChoice <= 2 ) // Alcohol percent
	{
		double dPercent;
		cout << "Alchol percent(0.1 means 10%): ";
		cin >> dPercent;
		if( iChoice == 1 )
			list( FuncCocktailAlcoholAbove( dPercent ) );
		else
			list( FuncCocktailAlcoholBelow( dPercent ) );
	}
	else
	{
		int iCount;
		cout << "Count: ";
		cin >> iCount;
		if( iChoice == 3 )
			list( FuncCocktailIngredientAbove( iCount ) );
		else
			list( FuncCocktailIngredientBelow( iCount ) );
	}
}

void duplicate_ingredient( Cocktail *pCocktail )
{
	for( int i = 0; i < pCocktail->GetIngredientCount(); ++i )
	{
		cout << i + 1 << ". ";
		cout << pCocktail->GetIngredient( i )->GetName() << endl;
	}

	cout << endl << endl;
	cout << "0. To Exit" << endl;
	cout << "#. To Duplicate ingredient" << endl;

	int iIngredientChoice;
	cin >> iIngredientChoice;
	if( iIngredientChoice <= 0 )
		return;

	if( iIngredientChoice > pCocktail->GetIngredientCount() )
		return;

	pCocktail->AddIngredient( pCocktail->GetIngredient( iIngredientChoice - 1 )->Clone() );
}

void add_ingredient( Cocktail *pCocktail )
{
	while( true )
	{
#ifndef CPORTA
		system( "cls" );
#endif 
		cout << "0. To Exit" << endl;
		cout << "1. To Add Liquid ingredient" << endl;
		cout << "2. To Add Alcohol ingredient" << endl;
		cout << "3. To Add Solid ingredient" << endl;
		cout << "4. To Duplicate existing ingredient" << endl;

		int iModeChoice;
		cin >> iModeChoice;
		switch( iModeChoice )
		{
		case 0: return;
		case 1: pCocktail->AddIngredient( Liquid:: Create( cout, cin ) ); break;
		case 2: pCocktail->AddIngredient( Alcohol::Create( cout, cin ) ); break;
		case 3: pCocktail->AddIngredient( Solid::  Create( cout, cin ) ); break;
		case 4: duplicate_ingredient( pCocktail ); break;

		default:
			break;
		}
	}
}

void delete_ingredient( Cocktail *pCocktail )
{
	for( int i = 0; i < pCocktail->GetIngredientCount(); ++i )
	{
		cout << i + 1 << ". ";
		cout << pCocktail->GetIngredient( i )->GetName() << endl;
	}

	cout << endl << endl;
	cout << "0. To Exit" << endl;
	cout << "#. To Delete ingredient" << endl;

	int iIngredientChoice;
	cin >> iIngredientChoice;
	if( iIngredientChoice <= 0 )
		return;

	if( iIngredientChoice > pCocktail->GetIngredientCount() )
		return;

	pCocktail->DelIngredient( iIngredientChoice - 1 );
}

void edit()
{
#ifndef CPORTA
	system( "cls" );
#endif 

	for( int i = 0; i < g_parrCocktail->GetCount(); ++i )
	{
		cout << i + 1 << ". ";
		cout << g_parrCocktail->GetPosition( i )->GetName() << endl;
	}

	cout << endl << endl;
	cout << "0. To Exit" << endl;
	cout << "#. To Edit cocktail" << endl;

	int iCocktailChoice;
	cin >> iCocktailChoice;
	if( iCocktailChoice <= 0 )
		return;

	if( iCocktailChoice - 1 >= g_parrCocktail->GetCount() )
		return;

	while( true )
	{
#ifndef CPORTA
		system( "cls" );
#endif 
		cout << "0. To Exit" << endl;
		cout << "1. To Add ingredient" << endl;
		cout << "2. To Delete ingredient" << endl;

		int iModeChoice;
		cin >> iModeChoice;
		switch( iModeChoice )
		{
		case 0: return;
		case 1: add_ingredient( g_parrCocktail->GetPosition( iCocktailChoice - 1 ) ); break;
		case 2: delete_ingredient( g_parrCocktail->GetPosition( iCocktailChoice - 1 ) ); break;

		default:
			break;
		}
	}
}

void add_cocktail()
{
	Cocktail *pCocktail = new Cocktail();
	g_parrCocktail->InsertLast( pCocktail );

	string strName;
	cout << "Name: ";
	cin >> strName;

	pCocktail->SetName( strName );

	add_ingredient( pCocktail );
}

void save()
{
	ofstream f( "data.txt" );

	if( f.fail() )
	{
		cerr << "Failed to open" << endl;
		return;
	}

	for( int i = 0; i < g_parrCocktail->GetCount() - 1; ++i )
	{
		g_parrCocktail->GetPosition( i )->WriteData( f );
		f << endl;
	}

	g_parrCocktail->GetPosition( g_parrCocktail->GetCount() - 1 )->WriteData( f );

	f.close();
}


void delete_cocktail()
{
#ifndef CPORTA
	system( "cls" );
#endif 

	for( int i = 0; i < g_parrCocktail->GetCount(); ++i )
	{
		cout << i + 1 << ". ";
		cout << g_parrCocktail->GetPosition( i )->GetName() << endl;
	}

	cout << endl << endl;
	cout << "0. To Exit" << endl;
	cout << "#. To Edit cocktail" << endl;

	int iCocktailChoice;
	cin >> iCocktailChoice;
	if( iCocktailChoice <= 0 )
		return;

	if( iCocktailChoice - 1 >= g_parrCocktail->GetCount() )
		return;

	delete g_parrCocktail->GetPosition( iCocktailChoice - 1 );
	g_parrCocktail->RemovePosition( iCocktailChoice - 1 );
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
			case 1: list( FuncCocktailAll() ); break;
			case 2: filter(); break;
			case 3: edit(); break;
			case 4: add_cocktail(); break;
			case 5: delete_cocktail(); break;
			case 6: save(); break;

			default:
				break;
		}

		menu_dialog();
	}
}

int main()
{
	SmartArray<Cocktail *> arrCocktail;
	g_parrCocktail = &arrCocktail;

	load_cocktails(); 
	run();

	for( int i = 0; i < arrCocktail.GetCount(); ++i )
		delete arrCocktail.GetPosition( i );

	return 0;
}