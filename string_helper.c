#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_helper.h"

char* read_line(char* prompt, int* n)
{
	char*	buffer = (char*)malloc(sizeof(char)*BUFFER_SIZE);

	printf("%s", prompt);
	fgets(buffer, 80, stdin);
	*n = strlen(buffer);

	if (buffer[*n - 1] == '\n')
	{
		buffer[*n - 1] = '\0';
		--*n;
	}

	return buffer;
}
