#!/bin/bash

NAME="./loser_sed"
TEST_DIR="./test"
F_FORBIDDEN=$TEST_DIR"/forbidden"
F_INEXISTANT="$TEST_DIR/does_not_exist"
F_MAN_BASH="$TEST_DIR/man_bash"

BOLD="\e[1m"
YELLOW="\e[33m"
RESET="\e[0m"

mkdir -p $TEST_DIR
echo hello world > "$F_FORBIDDEN"
chmod 000 $F_FORBIDDEN
man bash | head -n 15 > $F_MAN_BASH


echo -e "$BOLD----------- MAKE PROGRAM$RESET"
echo
make re
echo

echo -e "$BOLD----------- BEGIN TESTS$RESET"
echo

echo -e "$BOLD--- Bad args:$RESET"

echo -e "$YELLOW> $NAME$RESET"
$NAME
echo -e "$YELLOW> $NAME $F_MAN_BASH$RESET"
$NAME $F_MAN_BASH
echo -e "$YELLOW> $NAME $F_MAN_BASH x$RESET"
$NAME $F_MAN_BASH x
echo -e "$YELLOW> $NAME $F_MAN_BASH x y z$RESET"
$NAME $F_MAN_BASH x y z
echo

echo -e "$BOLD--- Non-existant file:$RESET"

echo -e "$YELLOW> $NAME $F_INEXISTANT x x$RESET"
$NAME $F_INEXISTANT x x
echo

echo -e "$BOLD--- Forbidden file (chmod 000):$RESET"

echo -e "$YELLOW> $NAME $F_FORBIDDEN x x$RESET"
$NAME $F_FORBIDDEN x x
echo

echo -e "$BOLD--- Replacements tests (Should NOT replace):$RESET"

echo -e "$YELLOW> $NAME $F_MAN_BASH \"\" \"\"$RESET"
$NAME $F_MAN_BASH "" ""
diff -s --color $F_MAN_BASH $F_MAN_BASH.replace
echo

echo -e "$YELLOW> $NAME $F_MAN_BASH \"\" \"x\"$RESET"
$NAME $F_MAN_BASH "" "x"
diff -s --color $F_MAN_BASH $F_MAN_BASH.replace
echo

echo -e "$YELLOW> $NAME $F_MAN_BASH \"not_in_text_at_all\" \"ZZZ\"$RESET"
$NAME $F_MAN_BASH "not_in_text_at_all" "ZZZ"
diff -s --color $F_MAN_BASH $F_MAN_BASH.replace
echo

echo -e "$BOLD--- Replacements tests (SHOULD replace):$RESET"

echo -e "$YELLOW> $NAME $F_MAN_BASH \"ash\" \"\"$RESET"
$NAME $F_MAN_BASH "ash" ""
diff -s --color $F_MAN_BASH $F_MAN_BASH.replace
echo

echo -e "$YELLOW> $NAME $F_MAN_BASH \" \" \"x\"$RESET"
$NAME $F_MAN_BASH " " "x"
diff -s --color $F_MAN_BASH $F_MAN_BASH.replace
echo

echo -e "$YELLOW> $NAME $F_MAN_BASH \" \" \"[_]\"$RESET"
$NAME $F_MAN_BASH " " "[_]"
diff -s --color $F_MAN_BASH $F_MAN_BASH.replace
echo

echo -e "$YELLOW> $NAME $F_MAN_BASH \"by the Free Software Foundation, Inc.\" \"ooo\"$RESET"
$NAME $F_MAN_BASH "by the Free Software Foundation, Inc." "ooo"
diff -s --color $F_MAN_BASH $F_MAN_BASH.replace
echo

echo -e "$YELLOW> $NAME $F_MAN_BASH \"bash\" \"clash mash sash\"$RESET"
$NAME $F_MAN_BASH "bash" "clash mash sash"
diff -s --color $F_MAN_BASH $F_MAN_BASH.replace
echo

rm -rf $TEST_DIR