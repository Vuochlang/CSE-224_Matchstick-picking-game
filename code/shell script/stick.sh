#!/bin/bash
########################################################################################################################
# Name: Vuochlang Chang
# Class: CSE224 Fall2019 2530
# Date: 9/30/2019
# Assignment: PA1, Matchstick Game
# This code is about a matchstick game where the game will be between the player and the computer itself in the game.
# The player starts the game by choosing the amount of sticks, at least 10 and choose who to go first. Then the game
# starts by follow the following rules:
#	- Each player can choose 1, 2 or 3 sticks per round
#	- If any player try to choose the number of sticks than the given choice for 3 times, the game will ended and that
#	  player will lose the game.
#	- The last player that choose the remainded stick will win the game!
########################################################################################################################
echo "Welcome to matchstick game! "
printf "How many sticks would you like to play with?  "
read n

while [[ $n -lt 10 ]]
do
printf "You must enter with at least 10 sticks: "
read n
done

echo "We will be playing with $n stick(s)"

printf "Who should go first? Enter u for user or c for computer: "
read a

while [[ "$a" != "u" ]] && [[ "$a" != "c" ]]
do
printf "Please enter a valid option: "
read a
done

if [[ "$a" == "u" ]]
then
echo "You will go first."
elif [[ "$a" == "c" ]]
then
echo "The computer will go first."
else
echo "Pleas try again."
read a
fi

echo "Each turn, a player can take 1, 2 or 3 sticks."
echo "Whoever takes the last stick wins the game!"
echo "Good Luck!!!"

i=$n
printf "Initial Pile:"

while [[ "$i" -gt 0 ]]
do
i=$((i-1))
echo -n "|"
done
echo "($n)"

if [[ "$a" == "c" ]]
then
Cmove=$((n%4))
echo "Cmove $C"
	if [[ "$Cmove" -eq 0 ]]
	then
	echo "I take 1 stick"
	n=$((n-1))
	b=$n
	printf "Remaining Pile:"
		while [[ "$b" -gt 0 ]]
		do
		b=$((b-1))
		echo -n "|"
		done
		echo "($n)"
	else
	echo "I take $Cmove sticks"
	n=$((n-Cmove))
	c=$n
	printf "Remaining Pile:"
		while [[ "$c" -gt 0 ]]
		do
		c=$((c-1))
		echo -n "|"
		done
		echo "($n)"
	fi
else
echo "done"
fi
