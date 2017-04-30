#include <iostream>
#include "Cocktail.h"
#include "Ingredient.h"
#include "Solid.h"
#include "Liquid.h"
#include "Alcohol.h"

using namespace std;

int main()
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

	cout << cocktailTest01.GetDataString() << endl;
	cout << "Alcohol percent:" << cocktailTest01.GetAlcoholPercent() * 100 << "%" << endl;


	return 0;
}