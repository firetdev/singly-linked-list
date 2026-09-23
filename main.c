#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	int value;
	struct Node* next;
} Node;

Node* create_node(int v) {
	Node* new_node = malloc(sizeof(*new_node));
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

	if (!new_node) return;

	if (*head_ref == NULL) {
		*head_ref = new_node;
		return;
	}

	Node* current = *head_ref;
	while (current->next != NULL) {
		current = current->next;
	}

	current->next = new_node;
}

void list_insert(Node** head_ref, int value, int index) {
	if (index < 0) return;

	Node* new_node = create_node(value);

	if (!new_node) return;

	if (*head_ref == NULL) {
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
		free(new_node);
	}
}

void list_remove(Node** head_ref, int index) {
	if (index < 0) return;

	Node** current = head_ref;

	for (int i = 0; i < index && *current != NULL; i++) {
		current = &(*current)->next;
	}

	if (*current == NULL) {
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

int main(void) {
	Node* head = NULL;

	push_back(&head, 10);
	push_back(&head, 20);
	push_back(&head, 30);
	list_insert(&head, 25, 1);
	list_insert(&head, 22, 2);
	list_remove(&head, 3);

	print_list(head);

	free_list(head);
	head = NULL;

	return 0;
}
