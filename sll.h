#include <stdlib.h>
#include <stdio.h>

// Define type
typedef struct Node {
	int value;
	struct Node* next;
} Node;

Node* create_node(int v) {
	Node* new_node = malloc(sizeof(*new_node));  // Allocate memory
	
    if (new_node == NULL) {
		perror("Failed to allocate memory");
		return(NULL);
	}

	new_node->value = v;
	new_node->next = NULL;

	return new_node;
}

void push_back(Node** head_ref, int value) {
	Node* new_node = create_node(value);

	if (!new_node) return;  // Memory allocation failed

	if (*head_ref == NULL) {  // There is no existing node in the list
		*head_ref = new_node;
		return;
	}

	Node* current = *head_ref;
	while (current->next != NULL) {
		current = current->next;
	}

	current->next = new_node;
}

// Inserts AFTER the requested index
void list_insert(Node** head_ref, int value, int index) {
	if (index < 0) return;

	Node* new_node = create_node(value);

	if (!new_node) return;  // Memory allocation failed

	if (*head_ref == NULL) {  // Cannot insert without at least one item in the list
		free(new_node);
		return;
	}

	Node* current = *head_ref;
	int i = 0;
	while (i < index && current->next != NULL) {
		current = current->next;
		i++;
	}

	if (i == index) {
		new_node->next = current->next;
		current->next = new_node;
	} else {
		free(new_node);  // The requested index doesn't exist; free the memory
	}
}

void list_remove(Node** head_ref, int index) {
	if (index < 0) return;

	Node** current = head_ref;  // A pointer to the pointer to the current node

	for (int i = 0; i < index && *current != NULL; i++) {  // *current is the Node* stored at this location
		current = &(*current)->next;  // Set current = a pointer to the pointer to the next node
	}

	if (*current == NULL) {  // Nothing to delete
		return;
	}

	Node* target = *current;
	*current = target->next;
	free(target);
}

void print_list(const Node* head) {
	const Node* current = head;
	while (current != NULL) {
		printf("%d\n", current->value);
		current = current->next;
	}
	printf("NULL\n");
}

void free_list(Node* head) {
	Node* current = head;
	while (current != NULL) {
	Node* last = current;
		current = current->next;
		free(last);
	}
}
