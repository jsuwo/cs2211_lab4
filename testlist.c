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

  /**********************************************************
   * Test 1 - Add string "Hello"
   *********************************************************/

	// Add string "Hello" to start of list
	node = add(node, strings[0]);

	// The head of the list should not be NULL
	assert(node != NULL);

	// The data at the head should have the same address as strings[0]
	assert(node->data == strings[0]);

	// The next pointer of the head should be NULL 
	assert(node->next == NULL);

  /**********************************************************
   * Test 2 - Add string "Goodbye"
   *********************************************************/

	// Add string "Goodbye" as the second node
	node = add(node, strings[1]);

	// The head should still be not NULL
	assert(node != NULL);

	// The data at the head should still have the same address as strings[0]
	assert(node->data == strings[0]);

	// The next pointer of the head should not be NULL
	assert(node->next != NULL);

	// The data at the second node should have the same address as strings[1]
	assert(node->next->data == strings[1]);

	// The next pointer of the second node should be NULL
	assert(node->next->next == NULL);

  /**********************************************************
   * Test 3 - Add string "Hello again"
   *********************************************************/

	// Add string "Hello again" as the third node
	node = add(node, strings[2]);

	// The head should still be not NULL
	assert(node != NULL);

	// The data at the head should still have the same address as strings[0]
	assert(node->data == strings[0]);

	// The next pointer of the head should not be NULL
	assert(node->next != NULL);

	// The data at the second node should have the same address as strings[1]
	assert(node->next->data == strings[1]);

  // The next pointer of the second node should not be NULL
	assert(node->next->next != NULL);

  // The data at the third node should have the same address as strings[2]
	assert(node->next->next->data == strings[2]);

  // The next pointer of the third node should be NULL
	assert(node->next->next->next == NULL);

  /**********************************************************
   * Test 4 - Clear the list 
   *********************************************************/
	clear(node);


	free(strings);
	puts("Tests passed.");

	return 0;	
}
