#include "RomanNumeral.h"
#include <string.h>

int GetSymbolValue(char symbol)
{
	int value = 0;
	switch (symbol)
	{
		case 'I':
			value = 1;
			break;
		case 'V':
			value = 5;
			break;
		case 'X':
			value = 10;
			break;
		case 'L':
			value = 50;
			break;
		case 'C':
			value = 100;
			break;
		case 'D':
			value = 500;
			break;
		case 'M':
			value = 1000;
			break;
	}
	return value;
}

int RomanToDecimal(const char * romanNumeralExpr)
{
	int total = 0;
	int lastSymbolicValue = -1;
	int thisSymbolicValue;
	for (int index = strlen(romanNumeralExpr); index >= 0; index--)
	{
		thisSymbolicValue = GetSymbolValue(romanNumeralExpr[index]);
		if (thisSymbolicValue >= lastSymbolicValue)
		{
			total += thisSymbolicValue;
		}
		else
		{
			total -= thisSymbolicValue;
		}
		lastSymbolicValue = thisSymbolicValue;
	}

	return total;
}
