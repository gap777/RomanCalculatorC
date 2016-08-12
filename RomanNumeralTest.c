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
