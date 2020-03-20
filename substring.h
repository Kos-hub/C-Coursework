#pragma once

void searchSingle(FILE* input, FILE* output, char* inputText, char* newText, char* replaceText, char* caseLetters);
void searchSentence(FILE* input, FILE* output, char* inputText, char* newText, char* replaceText, char* caseLetters);

char* substrReplacer(char* inputText, char* substr, char* replaceText, char* newText);
