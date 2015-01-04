/*	Author: Parker Mathewson								*
 *	Date: 3/7/12										*
 *	Program: This is a change on the program from lab4. Now we are working on efficiency.	*
 *		We are to use arrays this time around to shorten our code a great deal.		*
 */

#include<stdio.h>
#define SIZE 4

void init(char *array_initial, int size)
{
	int i=0;

	for(i=0; i<size; i++)
		array_initial[i]=0;
}

/*******************************************COUNTING CORRECTK*********************************************************/

int count_correct(char *answer_array_2, char *guess_array_2, int size)
{
	int i=0, correct=0;

	for(i=0; i<size; i++)
		if(*(guess_array_2+i) == *(answer_array_2+i))	correct++;
	printf("\n");

	return correct;
} 

/*******************************************GUESSING FUNCTIONK********************************************************/

void guess(char *guess_array_2, int size)
{
	int i=1;

	for(i=1; i<size+1; i++)
	{
		printf("Guess the color in position %d: ",i);	
		fflush(stdin);
		scanf("%c",&guess_array_2[i-1]);
	}
}

/*******************************************MESSAGE BLOCK************************************************************/

void print_message(int correct)
{
	switch(correct)
	{
			case 0:
				printf("\n\nThere are 0 correct in your guess.\n");
				break;

			case 1:								//case statements
				printf("There is 1 correct in your guess.\n");
				break;

			case 2:
				printf("There is 2 correct in your guess! You are almost there!\n");
				break;

			case 3:
				printf("There are 3 correct in your guess! Just one left...\n");
				break;

			case 4:
				printf("These are all correct!\n");
				break;

			default:
				printf("There was an error in counting correct answers. Check code...");
	}

	if (correct==4) printf("You win!\n");

}

/*******************************************START MAIN FUNCTION********************************************************/

int main(void)
{
	char answer_array[SIZE];
	char guess_array[SIZE];
	FILE *inp;
	int correct=0, i=0;

	init(answer_array, SIZE);
	init(guess_array, SIZE);
	inp = fopen("answer.dat","r");

	for(i=0; i<SIZE; i++)
	{
		if(i==3) fscanf(inp,"%c",&answer_array[i]);
		else
			 fscanf(inp,"%c ",&answer_array[i]);	//if statement in case the fscanf is confused by extra space.
								//Could be put into another function
		printf("%c ",answer_array[i]);
	}

	printf("\n\nI have 4 colors in a specific order.\nThe colors are red (r) blue (b) green (g) and yellow (y).\n");
	printf("Guess the order of the colors using r b g and y as the guesses.\n\n");

	fclose(inp);
	while (correct != 4)
	{
		correct=0;
		guess(guess_array, SIZE);
		correct=count_correct(answer_array, guess_array, SIZE);

		print_message(correct);
	}
	return (0);
}
