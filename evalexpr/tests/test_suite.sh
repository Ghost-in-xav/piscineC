#!/bin/sh

REF_OUT=".echo.out"
TEST_OUT=".my_echo.out"

#Test de base : addition
echo "3" > "$REF_OUT"
echo  -ne "1 2 +" | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"


echo "3" > "$REF_OUT"
echo -ne "3" | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

echo "0" > "$REF_OUT"
echo -ne "0 0 +" | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

echo "-1" > "$REF_OUT"
echo -ne "0 1 -" | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

#Test : soustraction
echo "-1" > "$REF_OUT"
echo -ne "1 2 -" | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

#Test : multiplication
echo "6" > "$REF_OUT"
echo -ne "2 3 *" | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

#Test : division
echo "2" > "$REF_OUT"
echo -ne "6 3 /" | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

#Test : modulo
echo "1" > "$REF_OUT"
echo -ne "10 3 %" | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

#Test : exponentiation
echo "16" > "$REF_OUT"
echo -ne "2 4 ^" | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

#Test : addition et multiplication imbriquées
echo "14" > "$REF_OUT"
echo -ne "2 3 4 + *" | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

#Test : priorité exponentiation et addition
echo "9" > "$REF_OUT"
echo -ne "2 3 ^ 1 +" | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

#Test : expression complexe avec plusieurs opérations
echo "16" > "$REF_OUT"
echo -ne "5 3 + 2 4 * +" | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

#Test : expression imbriquée avec exponentiation et multiplication
echo "16" > "$REF_OUT"
echo -ne "2 3 ^ 2 *" | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

#Test : division d'un résultat négatif
echo "2" > "$REF_OUT"
echo -ne "6 3 /" | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

#Test : soustraction donnant zéro
echo "0" > "$REF_OUT"
echo -ne "5 5 -" | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

#Test : soustraction avec des nombres négatifs
#echo "-2" > "$REF_OUT"
#echo "-5 - -3 " | ./evalexpr > "$TEST_OUT"
#diff "$REF_OUT" "$TEST_OUT"

#Test : addition avec des nombres négatifs
#echo "-8" > "$REF_OUT"
#echo "-5 + -3 " | ./evalexpr > "$TEST_OUT"
#diff "$REF_OUT" "$TEST_OUT"

#Test : multiplication de deux nombres négatifs
#echo "6" > "$REF_OUT"
#echo "-2 * -3 " | ./evalexpr > "$TEST_OUT"
#diff "$REF_OUT" "$TEST_OUT"

#Test : division de deux nombres négatifs
#echo "2" > "$REF_OUT"
#echo "-6 -3 /" | ./evalexpr > "$TEST_OUT"
#diff "$REF_OUT" "$TEST_OUT"

#Test : expression complexe avec priorités
echo "49" > "$REF_OUT"
echo -ne " 3 4 + 2 ^" | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

#Test : parenthèses et priorité d'opérations (représenté en RPN)
echo "14" > "$REF_OUT"
echo  -ne "5 1 2 + 4 * + 3 -" | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

#echo "2" > "$REF_OUT"
#echo "1 + 1" | ./evalexpr > "$TEST_OUT"
#diff "$REF_OUT" "$TEST_OUT"

echo "2" > "$REF_OUT"
echo -ne "1 1 +" | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

echo "35" > "$REF_OUT"
echo -ne "5 2 2 ^ 3 + *" | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

#echo "86" > "$REF_OUT"
#echo '86*--1' | ./evalexpr > "$TEST_OUT"
#diff "$REF_OUT" "$TEST_OUT"

#echo "7" > "$REF_OUT"
#echo '3---+-+4' | ./evalexpr > "$TEST_OUT"
#diff "$REF_OUT" "$TEST_OUT"

#echo "-12" > "$REF_OUT"
#echo '3*-4' | ./evalexpr > "$TEST_OUT"
#diff "$REF_OUT" "$TEST_OUT"

echo "2" > "$REF_OUT"
echo -ne '6/3' | ./evalexpr > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

echo "1" > "$REF_OUT"
echo -ne '11%10' | ./evalexpr > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

echo "35" > "$REF_OUT"
echo -ne "5*(2^2+3)" | ./evalexpr > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

echo "1" > "$REF_OUT"
echo -ne "0 1 +" | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

echo "42" > "$REF_OUT"
echo -ne "   42 " | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

echo "2" > "$REF_OUT"
echo -ne "1 1 +" | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

echo "0" > "$REF_OUT"
echo -ne "1 1 -" | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

echo "4" > "$REF_OUT"
echo -ne "2 2 *" | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

echo "4" > "$REF_OUT"
echo -ne "8 2 /" | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

echo "2" > "$REF_OUT"
echo -ne "6 % 4" | ./evalexpr > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

echo "27" > "$REF_OUT"
echo -ne "3 3 ^" | ./evalexpr -rpn > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

echo "298" > "$REF_OUT"
echo -ne "3*(15+3^2*7)+ 8^2" | ./evalexpr > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

echo "1" > "$REF_OUT"
echo -ne "3 % 10 / 3" | ./evalexpr > "$TEST_OUT"
diff "$REF_OUT" "$TEST_OUT"

echo -ne "3 % 10 / 3" | ./evalexpr -toto 
VAL2=$(echo "$?")
echo $VAL2 > "$TEST_OUT"
echo "4" > "$REF_OUT"
diff "$REF_OUT" "$TEST_OUT"

echo -ne "3 % 10 / 3" | ./evalexpr -toto -test
VAL2=$(echo "$?")
echo $VAL2 > "$TEST_OUT"
echo "4" > "$REF_OUT"
diff "$REF_OUT" "$TEST_OUT"

#echo "-2" > "$REF_OUT"
#echo "-1-1" | ./evalexpr > "$TEST_OUT"
#diff "$REF_OUT" "$TEST_OUT"

