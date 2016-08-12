CC=gcc 
CFLAGS=-I. -Wall -std=c99

kata: RomanNumeral.o RomanNumeralTest.o
	$(CC) -o kata RomanNumeral.o RomanNumeralTest.o -lcheck -lm -pthread -lrt

RomanNumeral.o: RomanNumeral.c RomanNumeral.h
	$(CC) $(CFLAGS) -c RomanNumeral.c

RomanNumeralTest.o: RomanNumeral.h RomanNumeralTest.c
	$(CC) $(CFLAGS) -c RomanNumeralTest.c 
