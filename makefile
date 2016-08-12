kata: RomanNumeral.o TestRunner.o RomanNumeralTest.o
	g++ -g -o kata RomanNumeral.o TestRunner.o RomanNumeralTest.o

RomanNumeral.o: RomanNumeral.cpp RomanNumeral.hpp
	g++ -g -c -std=c++11 -I/sw/include/root RomanNumeral.cpp

TestRunner.o: catch.hpp RomanNumeral.hpp TestRunner.cpp
	g++ -g -c -std=c++11 -I/sw/include/root TestRunner.cpp

RomanNumeralTest.o: catch.hpp RomanNumeralTest.cpp RomanNumeral.hpp
	g++ -g -c -std=c++11 -I/sw/include/root RomanNumeralTest.cpp 
