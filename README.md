# CSE-224 Programming Tools
# Programming Assignment: Matchstick-picking-game

There are two versions of the game, one is using shell script and another is using c.

# Shell script version:

_ The game will greet the user, and then ask how many sticks to play with (must be an integer of at least 10), 
and ask the user who should go first (c for computer, u for user).

_ In case the user enter invalid answer, the program will keep asking the question.

_ On the user's turn, ask the user how many sticks to remove, and remove those from the pile. 

_ On the computer's turn, calculate the correct number of sticks to remove in order to ensure it will win the game.

_ Must show the set of sticks after each player's move. Show this as a set of pipes (|) side by side, followed by the number of sticks in (parenthesis), for example: ||||||| (7)

# C version:

_ Has similar pattern as shell script version with more changes as followed:

_ The user always goes first 

_ The program must be prepared to handle any invalid input 

_ The game accepts either a command line parameter or program input to determine how many sticks to start with 

_ If a command line argument is given, the program will check is there is exactly one argument and the argument is a valid integer 
