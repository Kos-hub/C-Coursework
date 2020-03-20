/*
Author: Gianmarco Natuzzi 
Matric: 40439919
Last Modification: 27/02/2020

This program is used to replace characters or a sequence of characters within a text file. 
It uses command line arguments to get the text that needs to be found, the input file and the new text that we want to print.
It also uses an argument that allows us to have case sensitivity
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "substring.h"

#define	ARRAY_SIZE 50

int main(int argc, char** argv)
{
	//Creates a pointer to an array of characters in the heap which will be used to read in the data.
	char* inputText;
	inputText = (char*)malloc(ARRAY_SIZE);

	//Opens the output text file in which it writes our output text.
	FILE* output = fopen("output.txt", "w");

	//Using string compare to check if we're reading from the single word text file or from the sentences text file.
	if (strcmp(argv[3],"single_words_test.txt") == 0) 
	{
		//After the check, opens the text file and we calls a function called searchString that will do everything for us. In the end, we close the file.
		FILE* inputSingle = fopen(argv[3], "r");
		searchSingle(inputSingle, output, inputText, argv[5], argv[1], argv[6]);
		fclose(inputSingle);
	}
	
	if (strcmp(argv[3], "sentences_test.txt") == 0)
	{
		FILE* inputSentence = fopen("sentences_test.txt", "r");
		searchSentence(inputSentence, output, inputText, argv[5], argv[1], argv[6]);
		fclose(inputSentence);
	}
	
	fclose(output);

	return 0;

}

