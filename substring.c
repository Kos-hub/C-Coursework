#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "substring.h"

#define	ARRAY_SIZE 50

/*
The function takes the input text that has been read from the input file, the substring occurence, the text we want to replace and the new text we want to print.
*/
char* substrReplacer(char* inputText, char* substr, char* replaceText, char* newText)
{
	//Creates a left buffer that's gonna be null terminated where the substring starts.
	char left[ARRAY_SIZE];
	strcpy(left, inputText);

	//Creates a right buffer starting from the end of the substring and then it saves the right buffer elsewere .
	char* buffer = substr + strlen(replaceText);
	char right[ARRAY_SIZE];
	strcpy(right, buffer);

	//Null terminating the left buffer as said before.
	left[strlen(inputText) - strlen(substr)] = '\0';

	//Concatenates the newText with the left buffer.
	strcat(left, newText);

	//Here the input text becomes the left buffer + the new text. Now we only have the right buffer to concatenate.
	strcpy(inputText, left);
	left[strlen(left)] = '\0';

	//It re-checks if there's an occurence of the same substring inside the right buffer
	if (strstr(right, replaceText))
	{
		//Creates a new substring to analyze recalling the same function
		char* nwsubstr = strstr(right, replaceText);
		substrReplacer(right, nwsubstr, replaceText, newText);

	}

	//Concatenates the right buffer
	strcat(inputText, right);

	//The function returns the modified inputText 
	return inputText;
}

/*
These two functions are very similar, except for how the program reads the file. In searchSingle we don't have to change the memory for the array but 
In searchSentence we must do it otherwise the program would not be able to work with smaller strings.
*/
void searchSingle(FILE* input, FILE* output, char* inputText, char* newText, char* replaceText, char* caseLetters)
{
	
	while (!feof(input))
	{
		fgets(inputText, ARRAY_SIZE, input);

		char replaceUpperText[ARRAY_SIZE];

		if (caseLetters)
		{
			//copy the text that we want to replace into another variable that we are going to use only if the -c argument has been written
			strcpy(replaceUpperText, replaceText);
			replaceUpperText[strlen(replaceUpperText)] = '\0';
			//Make the new variable initial character uppercase
			replaceUpperText[0] = toupper(replaceUpperText[0]);

		}


		if (strstr(inputText, replaceText))
		{
			//Null terminates the input text so we can print it without any problems
			inputText[strlen(inputText) - 1] = '\0';
			printf("Original Text: %s || ", inputText);

			//Creates a substring variable and gets the first occurence of a substring
			char* substr = strstr(inputText, replaceText);

			char* replacedText = substrReplacer(inputText, substr, replaceText, newText);

			printf("Replaced text: %s\n", replacedText);
			fprintf(output, "%s\n", replacedText);

		}
		else if (strstr(inputText, replaceUpperText))
		{
			//Same thing as above, this statement only happens when caseletters has been written into the console
			inputText[strlen(inputText) - 1] = '\0';
			printf("Original Text: %s || ", inputText);

			char* substr = strstr(inputText, replaceUpperText);
			char* replacedText = substrReplacer(inputText, substr, replaceUpperText, newText);

			printf("Replaced text: %s\n", replacedText);
			//Just modified the \n.
			fprintf(output, "%s\n", replacedText);
		}
		else {
			fprintf(output, inputText);
		}
		//Freeing the memory from the input text
		free(inputText);

	}

}

void searchSentence(FILE* input, FILE* output, char* inputText, char* newText, char* replaceText, char* caseLetters)
{
	while (!feof(input))
	{
		
		if (strlen(replaceText) < 2)
		{
			//Reallocating memory in order to work with smaller strings
			realloc(inputText, 2);
			fgets(inputText, 2, input);
		}
		fgets(inputText, ARRAY_SIZE, input);

		char replaceUpperText[ARRAY_SIZE];

		if (caseLetters)
		{
			strcpy(replaceUpperText, replaceText);
			replaceUpperText[strlen(replaceUpperText)] = '\0';
			replaceUpperText[0] = toupper(replaceUpperText[0]);
		}

		if (strstr(inputText, replaceText))
		{

			char* substr = strstr(inputText, replaceText);
			char* replacedText = substrReplacer(inputText, substr, replaceText, newText);

			fprintf(output, "%s", replacedText);

		}
		else if (strstr(inputText, replaceUpperText))
		{
			char* substr = strstr(inputText, replaceUpperText);
			char* replacedText = substrReplacer(inputText, substr, replaceUpperText, newText);

			fprintf(output, "%s", replacedText);
		}
		else {
			fprintf(output, "%s", inputText);
		}

		free(inputText);


	}

	fclose(input);
	fclose(output);

}