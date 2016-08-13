#include <check.h>
#include <stdlib.h>
#include "RomanNumeral.h"

START_TEST(RomanToDecimal_I_Returns1)
{
	// setup
	
	// function under test 
	int result = RomanToDecimal("I");	

	// assertions
    ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(RomanToDecimal_II_Returns2)
{
	// setup
	
	// function under test 
	int result = RomanToDecimal("II");	

	// assertions
    ck_assert_int_eq(result, 2);
}
END_TEST

START_TEST(RomanToDecimal_III_Returns3)
{
	// setup
	
	// function under test 
	int result = RomanToDecimal("III");	

	// assertions
    ck_assert_int_eq(result, 3);
}
END_TEST

START_TEST(RomanToDecimal_IV_Returns4)
{
	// setup
	
	// function under test 
	int result = RomanToDecimal("IV");	

	// assertions
    ck_assert_int_eq(result, 4);
}
END_TEST

START_TEST(RomanToDecimal_V_Returns5)
{
	// setup
	
	// function under test 
	int result = RomanToDecimal("V");	

	// assertions
    ck_assert_int_eq(result, 5);
}
END_TEST

START_TEST(RomanToDecimal_MCCXXVI_Returns1226)

	// setup

	// method under test
	int result = RomanToDecimal("MCCXXVI");

	// assertions
	ck_assert_int_eq(result, 1226);
}

START_TEST(RomanToDecimal_LXVIIII_Returns69)

	// setup

	// method under test
	int result = RomanToDecimal("LXVIIII");

	// assertions
	ck_assert_int_eq(result, 69);
}

START_TEST(RomanToDecimal_LXIX_Returns69)

	// setup

	// method under test
	int result = RomanToDecimal("LXIX");

	// assertions
	ck_assert_int_eq(result, 69);
}

START_TEST(DecimalToRoman_1_ReturnsI)

	// setup

	// method under test
	char * result = DecimalToRoman(1);

	// assertions
	ck_assert_str_eq (result, "I");
	free(result);
}

START_TEST(DecimalToRoman_2_ReturnsII)

	// setup

	// method under test
	char * result = DecimalToRoman(2);

	// assertions
	ck_assert_str_eq (result, "II");
	free(result);
}

START_TEST(DecimalToRoman_3_ReturnsIII)

	// setup

	// method under test
	char * result = DecimalToRoman(3);

	// assertions
	ck_assert_str_eq (result, "III");
	free(result);
}

START_TEST(DecimalToRoman_4_ReturnsIV)

	// setup

	// method under test
	char * result = DecimalToRoman(4);

	// assertions
	ck_assert_str_eq (result, "IV");
	free(result);
}

START_TEST(DecimalToRoman_69_ReturnsLXIX)

	// setup

	// method under test
	char * result = DecimalToRoman(69);

	// assertions
	ck_assert_str_eq (result, "LXIX");
	free(result);
}

START_TEST(DecimalToRoman_1226_ReturnsMCCXXVI)

	// setup

	// method under test
	char * result = DecimalToRoman(1226);

	// assertions
	ck_assert_str_eq (result, "MCCXXVI");
	free(result);
}

START_TEST(RomanAdd_1Plus1_Returns2)

	// setup

	// method under test
	char * result = RomanAdd("I", "I");

	// assertions
	ck_assert_str_eq (result, "II");
	free(result);
}

START_TEST(RomanAdd_1Plus2_Returns3)

	// setup

	// method under test
	char * result = RomanAdd("I", "II");

	// assertions
	ck_assert_str_eq (result, "III");
	free(result);
}

START_TEST(RomanAdd_1Plus3_Returns4)

	// setup

	// method under test
	char * result = RomanAdd("I", "III");

	// assertions
	ck_assert_str_eq (result, "IV");
	free(result);
}

START_TEST(RomanSubtract_4Minus1_Returns3)

	// setup

	// method under test
	char * result = RomanSubtract("IV", "III");

	// assertions
	ck_assert_str_eq (result, "I");
	free(result);
}

Suite * roman_numeral_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("RomanNumerals");
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, RomanToDecimal_I_Returns1);
    tcase_add_test(tc_core, RomanToDecimal_II_Returns2);
    tcase_add_test(tc_core, RomanToDecimal_III_Returns3);
    tcase_add_test(tc_core, RomanToDecimal_IV_Returns4);
    tcase_add_test(tc_core, RomanToDecimal_V_Returns5);
    tcase_add_test(tc_core, RomanToDecimal_MCCXXVI_Returns1226);
    tcase_add_test(tc_core, RomanToDecimal_LXVIIII_Returns69);
    tcase_add_test(tc_core, RomanToDecimal_LXIX_Returns69);
    tcase_add_test(tc_core, DecimalToRoman_1_ReturnsI);
    tcase_add_test(tc_core, DecimalToRoman_2_ReturnsII);
    tcase_add_test(tc_core, DecimalToRoman_3_ReturnsIII);
    tcase_add_test(tc_core, DecimalToRoman_4_ReturnsIV);
    tcase_add_test(tc_core, DecimalToRoman_69_ReturnsLXIX);
    tcase_add_test(tc_core, DecimalToRoman_1226_ReturnsMCCXXVI);
    tcase_add_test(tc_core, RomanAdd_1Plus1_Returns2);
    tcase_add_test(tc_core, RomanAdd_1Plus2_Returns3);
    tcase_add_test(tc_core, RomanAdd_1Plus3_Returns4);
    tcase_add_test(tc_core, RomanSubtract_4Minus1_Returns3);
    suite_add_tcase(s, tc_core);

    return s;
}


int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = roman_numeral_suite();
    sr = srunner_create(s);
    srunner_set_fork_status(sr,  CK_NOFORK);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
