#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OUTPUT_BUFFER_SIZE 50
#define OUTPUT_SIZE 200

int validateInput(int argc, char **argv);
char *getNumberAsSentence(char *input);
char *getSingleDigitNumberAsSentence(char *input);
char *getDoubleDigitNumberAsSentence(char *input);
char *getThreeDigitNumberAsSentence(char *input);

// Constants
const char *units[10] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
const char *teens[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const char *tens[10] = {"", "Ten", "Twenty", "Thrirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninenty"};
const char *bigs[5] = {"", "Thousand", "Million", "Billion", "Trillion"};
const char *hundred = "Hundred";

int main(int argc, char **argv)
{

	int inputReadStatus = validateInput(argc, argv);

	if (inputReadStatus == 0)
	{

		// Copy the valid input
		char *input = (char *)malloc(strlen(argv[1]) * sizeof(char));
		strcpy(input, argv[1]);

		char *answer = getNumberAsSentence(input);
		printf("%s\n", answer);

		free(input);
		free(answer);
		return 0;
	}
	else
	{
		printf("\nInvalid Input\n");
		return 1;
	}
}

int validateInput(int argc, char **argv)
{

	// One argument
	if (!(argc == 2))
	{
		return 1;
	}

	// Length of input should be less than or Equal 13
	int length = strlen(argv[1]);
	if (length <= 0 || length > 13)
	{
		return 2;
	}

	// All the Characters should be digits
	char *tempPtr = argv[1];
	while (*tempPtr)
	{
		if (isdigit(*tempPtr))
		{
			*tempPtr++;
		}
		else
		{
			return 3;
		}
	}

	// Deny the format 0* or anything greater than 1 trillion
	if ((*argv[1] == '0') || (length == 13 && (*argv[1] != '1')))
	{
		return 4;
	}

	return 0;
}

char *getNumberAsSentence(char *input)
{
	char *sentence = (char *)malloc(OUTPUT_SIZE * sizeof(char));
	char *cursor = sentence;

	int digitsProcessed = 0;
	int length = strlen(input);

	while (digitsProcessed < length)
	{
		int remaining = length-digitsProcessed;
		
		int largestBig = (remaining/3);
		largestBig = remaining%3 == 0 ? largestBig-1 : largestBig;
		int largestBigSizeCount = remaining%3 == 0 ? 3 : remaining%3;

		char *subSentence;
		
		if (remaining > 3)
		{ 
			if(largestBigSizeCount == 1){
				subSentence = getSingleDigitNumberAsSentence(input+digitsProcessed);
				digitsProcessed += 1;
			}else if(largestBigSizeCount == 2){
				subSentence = getDoubleDigitNumberAsSentence(input+digitsProcessed);
				digitsProcessed += 2;
			}else if(largestBigSizeCount == 3){
				subSentence = getThreeDigitNumberAsSentence(input+digitsProcessed);
				digitsProcessed += 3;
			}
		}
		else if (remaining == 3)
		{
			subSentence = getThreeDigitNumberAsSentence(input+digitsProcessed);
			digitsProcessed += 3;
		}
		else if (remaining == 2)
		{
			subSentence = getDoubleDigitNumberAsSentence(input+digitsProcessed);
			digitsProcessed += 2;
		}
		else 
		{
			subSentence = getSingleDigitNumberAsSentence(input+digitsProcessed);
			digitsProcessed++;
		}
		
		strcpy(cursor, subSentence);
		
		if(remaining > 3){
			cursor += strlen(subSentence);
			
			if(strlen(subSentence)){
				strcpy(cursor," ");
			  cursor++;
				
				strcpy(cursor,bigs[largestBig]);
      	cursor += strlen(bigs[largestBig]);

				strcpy(cursor," ");
				cursor++;
			}
		}
		
		free(subSentence);
	}

	return sentence;
}

char *getSingleDigitNumberAsSentence(char *input)
{
	int digit = *input - '0';
	char *sentence = (char *)malloc(sizeof(strlen(units[digit]) * (sizeof(char))));
	strcpy(sentence, units[digit]);
	return sentence;
}

char *getDoubleDigitNumberAsSentence(char *input)
{
	int tensDigit = input[0] - '0';
	int unitsDigit = input[1] - '0';

	if (tensDigit == 0)
	{
		return getSingleDigitNumberAsSentence(input + 1);
	}
	else if (tensDigit == 1)
	{
		int size = strlen(teens[unitsDigit]);
		char *sentence = (char *)malloc(size * (sizeof(char)));
		strcpy(sentence, teens[unitsDigit]);
		return sentence;
	}
	else
	{
		int tensDigitWordSize = strlen(tens[tensDigit]);
		int unitsDigitWordSize = strlen(units[unitsDigit]);
		int size = tensDigitWordSize + unitsDigitWordSize + 1;
		if (unitsDigitWordSize == 0)
		{
			size--;
		}
		char *sentence = (char *)malloc(size * (sizeof(char)));
		char *cursor = sentence;
		strcpy(cursor, tens[tensDigit]);
		cursor += tensDigitWordSize;
		if (unitsDigitWordSize)
		{
			strcpy(cursor, " ");
			cursor += 1;
		}
		strcpy(cursor, units[unitsDigit]);
		return sentence;
	}
}

char *getThreeDigitNumberAsSentence(char *input)
{
	int hundredsDigit = input[0] - '0';

	char *doubleDigitSentence = getDoubleDigitNumberAsSentence(input + 1);

	if (hundredsDigit == 0)
	{
		return doubleDigitSentence;
	}
	else
	{
		char *hundredsDigitSentence = getSingleDigitNumberAsSentence(input);

		int size = strlen(hundredsDigitSentence) + 1 + strlen(hundred);
		if (strlen(doubleDigitSentence) > 0)
		{
			size += 1 + strlen("and") + 1 + strlen(doubleDigitSentence);
		}

		char *sentence = (char *)malloc(size * (sizeof(char)));
		char *cursor = sentence;

		strcpy(cursor, hundredsDigitSentence);
		cursor += strlen(hundredsDigitSentence);

		strcpy(cursor, " ");
		cursor += 1;

		strcpy(cursor, hundred);
		cursor += strlen(hundred);

		if (strlen(doubleDigitSentence))
		{
			strcpy(cursor, " and ");
			cursor += 5;

			strcpy(cursor, doubleDigitSentence);
			free(doubleDigitSentence);
		}
		return sentence;
	}
}
