#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    test.sh                                            :+:    :+:             #
#                                                      +:+                     #
#    By: fbes <fbes@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/05/19 23:24:18 by fbes          #+#    #+#                  #
#    Updated: 2022/05/19 23:24:18 by fbes          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

make
echo ""

INPUT_FILE=wolfenstein.txt

rm -f "$INPUT_FILE.replace"

./sed_42 "$INPUT_FILE" "" "42CODAM42"
echo "Compare $INPUT_FILE with $INPUT_FILE.replace. It should be the exact same file."
read -p "Press any key to continue with the next test."
rm -f "$INPUT_FILE.replace"
echo ""

./sed_42 "$INPUT_FILE" "the" "(wow, it works)"
echo "Compare $INPUT_FILE with $INPUT_FILE.replace. The word \"the\" should be replaced with \"(wow, it works)\"."
read -p "Press any key to continue with the next test."
rm -f "$INPUT_FILE.replace"
echo ""

./sed_42 "$INPUT_FILE" "the" "@"
echo "Compare $INPUT_FILE with $INPUT_FILE.replace. The word \"the\" should be replaced with \"@\"."
read -p "Press any key to continue with the next test."
rm -f "$INPUT_FILE.replace"
echo ""

./sed_42 "$INPUT_FILE" "on" "42CODAM42"
echo "Compare $INPUT_FILE with $INPUT_FILE.replace. All occurrences of \"on\" should be replaced with \"42CODAM42\"."
read -p "Press any key to continue with the next test."
rm -f "$INPUT_FILE.replace"
echo ""

./sed_42 "$INPUT_FILE" " " ""
echo "Compare $INPUT_FILE with $INPUT_FILE.replace. All spaces should be gone."
read -p "Press any key to continue with the next test."
rm -f "$INPUT_FILE.replace"
echo ""

./sed_42 "$INPUT_FILE" $'\n\n' " "
echo "Compare $INPUT_FILE with $INPUT_FILE.replace. All blank lines should be gone."
read -p "Press any key to continue with the next test."
rm -f "$INPUT_FILE.replace"
echo ""

./sed_42 "$INPUT_FILE" $'\n' " "
echo "Compare $INPUT_FILE with $INPUT_FILE.replace. All newlines should have been replaced with a space."
read -p "Press any key to continue."
rm -f "$INPUT_FILE.replace"
