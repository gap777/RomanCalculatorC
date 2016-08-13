#include "RomanNumeral.h"
#include <string.h>
#include <stdlib.h>

#define NumberOfIllegalCombinations 6
const char * IllegalCombinations[NumberOfIllegalCombinations] = {
	"DCCCC",
	"CCCC",
	"LXXXX",
	"XXXX",
	"VIIII",
	"IIII",
};

const char * GetIllegalCombinationReplacement(const char * illegalCombination)
{
	const char * replacement = NULL;
	if (strcmp(illegalCombination, "DCCCC") == 0)
	{
		replacement = "CM";
	}
	else if (strcmp(illegalCombination, "CCCC") == 0)
	{
		replacement = "CD";
	}
	else if (strcmp(illegalCombination, "LXXXX") == 0)
	{
		replacement = "XC";
	}
	else if (strcmp(illegalCombination, "XXXX") == 0)
	{
		replacement = "XL";
	}
	else if (strcmp(illegalCombination, "VIIII") == 0)
	{
		replacement = "IX";
	}
	else if (strcmp(illegalCombination, "IIII") == 0)
	{
		replacement = "IV";
	}
	return replacement;
}

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

char FindSymbolLessThanOrEqualTo(int aValue)
{
	char symbol = '\0';
	if (aValue >= 1000)
	{
		symbol = 'M';
	}
	else if (aValue >= 500)
	{
		symbol = 'D';
	}
	else if (aValue >= 100)
	{
		symbol = 'C';
	}
	else if (aValue >= 50)
	{
		symbol = 'L';
	}
	else if (aValue >= 10)
	{
		symbol = 'X';
	}
	else if (aValue >= 5)
	{
		symbol = 'V';
	}
	else if (aValue >= 1)
	{
		symbol = 'I';
	}

	return symbol;
}

void ReplaceIllegalCombinations(char * expr)
{
	char * nextSubstr = NULL;
	for (int comboIndex = 0; comboIndex < NumberOfIllegalCombinations; comboIndex++)
	{
	 	const char * illegalExpr = IllegalCombinations[comboIndex];
		while ((nextSubstr = strstr(expr, illegalExpr)) != NULL)
		{
			int illegalComboLength = strlen(illegalExpr);
			const char * replacement = GetIllegalCombinationReplacement(illegalExpr);
			int replacementLength = strlen(replacement);

			strncpy(nextSubstr, replacement, replacementLength);
			strcpy(nextSubstr + replacementLength, nextSubstr + illegalComboLength); 
		}	
	}
}

char * DecimalToRoman(int decimal)
{
	int remainder = decimal;
	char symbol = '\0';
	int index = 0;
	int symbolicValue = 0;
	int expressionSize = sizeof(char) * 24;
	char * romanNumeralExpr = malloc(expressionSize);
	while (remainder > 0)
	{
		symbol = FindSymbolLessThanOrEqualTo(remainder);
		romanNumeralExpr[index++] = symbol;
		symbolicValue = GetSymbolValue(symbol);
		remainder -= symbolicValue;
	}
	romanNumeralExpr[index] = '\0';
	ReplaceIllegalCombinations(romanNumeralExpr);
	return romanNumeralExpr;
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
