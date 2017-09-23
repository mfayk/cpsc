#ifndef WORDFIND_H
#define WORDFIND_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



void readData(int argc, char *argv[]);

/*This function should:
  1. Print the instructions for the game.
  2. Ask the user to enter a 1 if they want to play and 0 if they do not want to
     play
  3. Depending on the user response call printGame or end the game.*/
int printInstruction(int numAns, int numCorrect, char matrix[3][3],
                    int *answer, bool *correct, char *ans[]);

/*This function should:
  1. Print the matrix that holds numbers associated with each block (see example
     in the assignment specifications)
  2. Print the matrix that holds the letters of the words for the game (see
     example in the assignment specifications)
  3. Call printWords which will print the blanks or the actual word
     if a previous word guess was correct
  4. If the number of correct answers matches the number of answers (numAns)
     then tell the player they won.  If not then prompt the user for a guess.
  5. Using scanf, grab the users guess
  6. Check the users answer by calling is correctAnswer.  If the answer is
     not correct prompt the user to try again.  Continue this until the correct
     answer is given.
  */
void printGame(int numAns, int numCorrect, char matrix[3][3], int *answer,
               bool *correct, char *ans[]);


/*This function should:
  1.  Determine the length of the words stored in ans.
  2.  If the word is correct then print the word
  3.  If the word is not correct then print one blank space for each letter in
      the correct word below the wordFind puzzle.  Also print 2 or 3 blank
      spaces between each word. (see example in assignment specification)*/
void printWords(bool *correct, char *ans[], int *answer);

/*This function should:
  1.  Check the answer, entered by the player, with all possible answers.
  2.  If the users answer is correct set current element of the the array
      of type bool to true.
  2.  Increment a counter for the number of correct answers
  3.  If the answer is incorrect it returns false*/
bool isCorrectAnswer (int numAns, bool *correct, int numCorrect,
                      int *answer, int a, char matrix[3][3], char **ans);

/*This function should:
  1.  When the player returns a correct word the characters in the matrix are
  replaced with spaces and the word is printed below the matrix
    a.  This is done by first looking at each digit in "a".  You will needs
        to determine which subscript (row and col) the number represents.
        Use this information to insure the appropriate row and col in matrix is
        set equal to a space ' ' .
  2.  The last thing you need to do is call printGame.  */

void updateMatrix(int numAns, int numCorrect, char matrix[3][3], int *answer,
               bool *correct,int a, char *ans[]);

#endif
