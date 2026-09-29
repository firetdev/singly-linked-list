#include "sll.h"

int main(void) {
	Node* head = NULL;

	push_back(&head, 10);
	push_back(&head, 20);
	push_back(&head, 30);
	list_insert(&head, 25, 1);
	list_insert(&head, 22, 2);
	list_remove(&head, 3);

	Node* found = list_search(&head, 30);

	if (found != NULL) {
		printf("Found value: %d\n", found->value);
	} else {
		printf("Value not found\n");
	}

	print_list(head);

	free_list(head);
	head = NULL;

	return 0;
}
