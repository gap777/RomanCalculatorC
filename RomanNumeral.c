#include "RomanNumeral.h"
#include <string.h>
#include <stdlib.h>

/** 
 * The algorithm I use to convert a decimal to a roman numeral 
 * is to look for the biggest single roman symbol that is included
 * in the number, subtract the value thereof, and repeat, concatenating
 * the symbols as they are selected.
 *
 * The problem with this approach is that it leaves you with illegal
 * combinations (see below). Thus, as a post-processing step, I replace
 * any instances of those symbol combinations with their correct form.
 */

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

void ReplaceAll(char * expr, const char * search, const char * replacement)
{
	char * nextSubstr = NULL;
	while ((nextSubstr = strstr(expr, search)) != NULL)
	{
		int searchLength = strlen(search);
		int replacementLength = strlen(replacement);

		strncpy(nextSubstr, replacement, replacementLength);
		strcpy(nextSubstr + replacementLength, nextSubstr + searchLength); 
	}
}

void ReplaceIllegalCombinations(char * expr)
{
	for (int comboIndex = 0; comboIndex < NumberOfIllegalCombinations; comboIndex++)
	{
		const char * illegalExpr = IllegalCombinations[comboIndex];
		const char * replacement = GetIllegalCombinationReplacement(illegalExpr);
		ReplaceAll(expr, illegalExpr, replacement);	
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

char * RomanAdd(const char * firstRomanAddend, const char * secondRomanAddend)
{
	int firstDecimalAddend = RomanToDecimal(firstRomanAddend);
	int secondDecimalAddend = RomanToDecimal(secondRomanAddend);
	return DecimalToRoman(firstDecimalAddend + secondDecimalAddend);
}

char * RomanSubtract(const char * romanMinuend, const char * romanSubtrahend)
{
	int decimalMinuend = RomanToDecimal(romanMinuend);
	int decimalSubtrahend = RomanToDecimal(romanSubtrahend);
	return DecimalToRoman(decimalMinuend - decimalSubtrahend);
}

