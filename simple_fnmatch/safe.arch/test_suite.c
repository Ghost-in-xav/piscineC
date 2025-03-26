#include <criterion/criterion.h>
#include <criterion/logging.h>
#include <fnmatch.h>
#include <stdio.h>
#define FNM_NOMATCH 1
#include "simple_fnmatch.h"

// Tests avec des jokers *
Test(fnmatch_tests, wildcard_star_tests)
{
    cr_assert_eq(simple_fnmatch("*", "anything"), 0,
                 "Test échoué: '*' devrait correspondre à 'anything'");
    cr_assert_eq(simple_fnmatch("*", ""), 0,
                 "Test échoué: '*' devrait correspondre à une chaîne vide");
    cr_assert_eq(simple_fnmatch("he*", "hello"), 0,
                 "Test échoué: 'he*' devrait correspondre à 'hello'");
    cr_assert_eq(simple_fnmatch("he*", "he"), 0,
                 "Test échoué: 'he*' devrait correspondre à 'he'");
    cr_assert_eq(simple_fnmatch("he*oy", "heyytutyoz"), FNM_NOMATCH,
                 "Test échoué: 'he*o' devrait correspondre à 'heyo'");
    cr_assert_eq(
        simple_fnmatch("*test", "this_is_a_test"), 0,
        "Test échoué: '*test' devrait correspondre à 'this_is_a_test'");
    cr_assert_eq(
        simple_fnmatch("*test", "this_is_not_a_test"), 0,
        "Test échoué: '*test' devrait correspondre à 'this_is_not_a_test'");
}

// Tests avec le caractère ?
Test(fnmatch_tests, question_mark_tests)
{
    cr_assert_eq(simple_fnmatch("h?llo", "hello"), 0,
                 "Test échoué: 'h?llo' devrait correspondre à 'hello'");
    cr_assert_eq(simple_fnmatch("h?llo", "hallo"), 0,
                 "Test échoué: 'h?llo' devrait correspondre à 'hallo'");
    cr_assert_eq(simple_fnmatch("h?llo", "hxllo"), 0,
                 "Test échoué: 'h?llo' devrait correspondre à 'hxllo'");
    cr_assert_eq(simple_fnmatch("h?llo", "hlo"), FNM_NOMATCH,
                 "Test échoué: 'h?llo' ne devrait pas correspondre à 'hlo'");
    cr_assert_eq(
        simple_fnmatch("h?llo", "hellohello"), FNM_NOMATCH,
        "Test échoué: 'h?llo' ne devrait pas correspondre à 'hellohello'");
}

// Tests avec le caractère d'échappement
Test(fnmatch_tests, backslash_escape_tests)
{
    cr_assert_eq(simple_fnmatch("hello\\*", "hello*"), 0,
                 "Test échoué: 'hello\\*' devrait correspondre à 'hello*'");
    cr_assert_eq(simple_fnmatch("hello\\?", "hello?"), 0,
                 "Test échoué: 'hello\\?' devrait correspondre à 'hello?'");
    cr_assert_eq(simple_fnmatch("file\\[", "file["), 0,
                 "Test échoué: 'file\\[' devrait correspondre à 'file['");
    cr_assert_eq(simple_fnmatch("file\\\\", "file\\"), 0,
                 "Test échoué: 'file\\\\' devrait correspondre à 'file\\'");
    cr_assert_eq(simple_fnmatch("je*isf*rat*er", "jesuisfatiguerderatere"), 1,
                 "pas corresp");
}

Test(fnmatch_tests, turbo_clc)
{
    cr_assert_eq(simple_fnmatch("\\a", "a"), 0, "'\\a' correspond a 'a'");
    cr_assert_eq(simple_fnmatch("*\\a\\b", "123ab"), 0, "pas corresp2");
    cr_assert_eq(simple_fnmatch("*?*?*?*?\\*\\?", "toto"), 1,
                 "'*?*?*?*?\\*\\?' correspond pas a  'toto'");
    cr_assert_eq(simple_fnmatch("*?*?*?*?\\*\\?", "toto*?"), 0,
                 "'*?*?*?*?\\*\\?' correspond pas a  'toto*?'");
}

// Tests supplémentaires pour le backtracking avec des jokers
Test(fnmatch_tests, backtracking_tests)
{
    // Cas où le '' doit correspondre à plusieurs caractères puis revenir en
    // arrière
    cr_assert_eq(simple_fnmatch("ab*cd", "abxyzcd"), 0,
                 "Test échoué: 'abcd' devrait correspondre à 'abxyzcd'");

    // Cas où le '' correspond à une portion de la chaîne, mais doit faire du
    // backtracking
    cr_assert_eq(simple_fnmatch("a*b*c", "axyzbzc"), 0,
                 "Test échoué: 'abc' devrait correspondre à 'axyzbzc'");

    // Cas où plusieurs '' doivent fonctionner ensemble avec backtracking
    cr_assert_eq(simple_fnmatch("*a*b", "xyzaxyzb"), 0,
                 "Test échoué: 'ab' devrait correspondre à 'xyzaxyzb'");

    // Test d'un motif avec '?' où le backtracking est nécessaire
    cr_assert_eq(simple_fnmatch("a?b?cd", "axbycd"), 0,
                 "Test échoué: 'a?b?cd' devrait correspondre à 'axbycd'");
}

// Tests longs supplémentaires pour le backtracking avec des jokers
Test(fnmatch_tests, long_backtracking_tests)
{
    // Cas où '' doit correspondre à une longue portion de la chaîne puis
    // revenir en arrière
    cr_assert_eq(simple_fnmatch("a*def*gh", "abcdefghijklmnopqrstuvwxygh"), 0,
                 "Test échoué: 'a*def*gh' devrait correspondre à "
                 "'abcdefghijklmnopqrstuvwxygh'");

    // Cas avec plusieurs jokers '*' et '?', nécessitant du backtracking sur une
    // longue chaîne
    cr_assert_eq(
        simple_fnmatch("*abc?*def*ghi*jkl", "123abcx567def890ghijklmnop"), 1,
        "Test échoué: '*abc?*def*ghi*jkl' devrait pas correspondre à "
        "'123abcx567def890ghijklmnop'");

    // Cas avec du backtracking où '' correspond à une grande partie de la
    // chaîne, avant et après un joker
    cr_assert_eq(simple_fnmatch("*a*b*c*d*", "xyza123b456c789d0pqrs"), 0,
                 "Test échoué: '*a*b*c*d*' devrait correspondre à "
                 "'xyza123b456c789d0pqrs'");

    // Cas où des caractères échappés doivent être correctement pris en compte
    // avec du backtracking
    cr_assert_eq(
        simple_fnmatch("start*\\*end", "start123*end"), 0,
        "Test échoué: 'start*\\*end' devrait correspondre à 'start123end'");

    // Cas complexe avec une combinaison de plusieurs '' et '?' sur une longue
    // chaîne
    cr_assert_eq(simple_fnmatch("*?*?*?*?*abc*?*?*?*xyz*",
                                "this_is_a_long_test_abc_and_more_xyz_content"),
                 0,
                 "Test échoué: '*?*?*?*?*abc*?*?*?*xyz*' devrait correspondre "
                 "à 'this_is_a_long_test_abc_and_more_xyz_content'");

    char path1[] = "*?*?*?*?\\*?";
    char str1[] = "toto?";
    int actual1 = simple_fnmatch(path1, str1);
    int expected1 = fnmatch(path1, str1, 0);
    printf("actual = %d\n", actual1);
    printf("expected = %d\n", expected1);
}
