#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int x;
	struct Node * next;
} Node;


int main(int argc, char* argv[]) {
	Node	root;
	root.x = 15;
	root.next = malloc(sizeof(Node));
	root.next->x = -2;
	root.next->next = NULL;

	Node* curr = &root;
	while (curr != NULL) 
	{
		printf("Current: %d\n", curr->x);
		curr = curr->next;
	}

	free(root.next);
	return 0;
}


/* 
// TO DO: take a look at https://www.cs.cmu.edu/~clo/www/CMU/DataStructures/Lessons/lesson1_2.htm


// function taken from https://www.learn-c.org/en/Linked_lists
void push(node_t ** head, int val) { // push to the beginning of the list (head); => why is it a double pointer ?? => because functions pass a value. , to reassign a pointer in the function we need a double pointer. 
    node_t * new_node; // new node: pointer => why ? ok let's just agree it's that way
    new_node = (node_t *) malloc(sizeof(node_t)); // malloc of type node_t *, because ?

    new_node->val = val; // look at structs ?
    new_node->next = *head; //next is set to be equal to the pointer passed as input. Why ?   we create something at beginning newdata(nb:new head)|next -> data(nb:previous head)|next -> data|next ->
    *head = new_node; // we set the new head to be the pointer pointing to the new node
}


int	main()
{
	node_t *base_node;

	base_node = (node_t *) malloc(sizeof(node_t));

	base_node->val = 1;
	base_node->next = NULL;

	printf("The val of the base_node is %d and next points to %p\n", base_node->val, base_node->next);

	push(&base_node->next, 2);

	printf("The val of the new_node is %d and next points to %p\nprevious node's value is still %d and next now points to %p\n", base_node->next->val, base_node->next->next, base_node->val, base_node->next);

	return (0);
} */