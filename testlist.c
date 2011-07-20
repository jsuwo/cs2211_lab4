#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "linked_list.h"

int main()
{
	node_t* node = NULL;
	char** strings = (char**)malloc(sizeof(char*)*3);
	int i;
	
	for (i = 0; i < 3; i++)
	{
		strings[i] = (char*)malloc(sizeof(char)*12);
	}	

	strcpy(strings[0], "Hello");
	strcpy(strings[0], "Goodbye");
	strcpy(strings[0], "Hello again");

	// Add string "Hello" to start of list
	node = add(node, strings[0]);
	assert(node != NULL);
	assert(node->data == strings[0]);
	assert(node->next == NULL);

	// Add string "Goodbye" as the second node
	node = add(node, strings[1]);
	assert(node != NULL);
	assert(node->data == strings[0]);
	assert(node->next != NULL);
	assert(node->next->data == strings[1]);
	assert(node->next->next == NULL);

	// Add string "Hello again" as the third node
	node = add(node, strings[2]);
	assert(node != NULL);
	assert(node->data == strings[0]);
	assert(node->next != NULL);
	assert(node->next->data == strings[1]);
	assert(node->next->next != NULL);
	assert(node->next->next->data == strings[2]);
	assert(node->next->next->next == NULL);

	free(strings);
	clear(node);

	puts("Tests passed.");

	return 0;	
}
