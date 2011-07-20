#include <stdio.h>
#include <stdlib.h>
#include "string_helper.h"
#include "boolean.h"

#define MAX_STRINGS 5

/*******************************************************************************
 * Reads strings from the standard input until an empty line is specified.
 *
 * Parameters:
 *   n - Will store the number of strings read after the function returns 
 *
 * Returns:
 *   An array containing the strings entered. 
 ******************************************************************************/ 
char** read_strings(int* n)
{
	char** strings = (char**)malloc(sizeof(char*) * MAX_STRINGS);
	char* line;
	int chars_read;
	int strings_read = 0;
	bool_t done = FALSE;

	while (!done)
	{
		line = read_line("> ", &chars_read);	

		if (chars_read == 0)
 		{	
			done = TRUE;
		}
		else
		{
			strings[strings_read] = line;
			strings_read++;

			if (strings_read == MAX_STRINGS)
				done = TRUE;
		}
	}

	*n = strings_read;
	return strings;
}

/*******************************************************************************
 * Prints all strings contained in the specified list.
 *
 * Parameters:
 *   list - The array of strings to print
 *   n    - The number of strings contained in the list
 *
 * Returns:
 *   Nothing 
 ******************************************************************************/ 
void print_strings(char** list, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%s\n", list[i]);
	}
}

/*******************************************************************************
 * Frees the memory allocated to the strings in the specified list, as well as
 * the memory allocated to the list itself.
 *
 * Parameters:
 *   list - The array of strings to print
 *   n    - The number of strings contained in the list
 *
 * Returns:
 *   Nothing 
 ******************************************************************************/ 
void clear_strings(char** list, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		free(list[i]);
	}

	free(list);
}

/*******************************************************************************
 * Reads strings from the standard input until an empty string is entered, at
 * which time the strings entered are printed to standard output.
 *
 * Parameters:
 *   None
 *
 * Returns:
 *  EXIT_SUCCESS upon program completion
 ******************************************************************************/ 
int main()
{
	int strings_read;

	puts("Enter a list of strings.  Enter a blank line to stop.");
	char** list = read_strings(&strings_read);
	print_strings(list, strings_read);
	clear_strings(list, strings_read);

	return 0;
}
