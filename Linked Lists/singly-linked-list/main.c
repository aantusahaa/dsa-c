#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

void handleFailure(Node* node) {
	if(node == NULL) {
		printf("Memory Allocation Failed!");
		exit(1);
	}	
}

Node* createNode(int data) {
	Node* newNode = (Node*) malloc(sizeof(Node));
	handleFailure(newNode);

	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

void insertEnd(Node** head, int data) {
	Node* newNode = createNode(data);

	if(*head == NULL) {
		*head = newNode;
	} else {
		Node* current = *head;

		while(current->next != NULL) {
			current = current->next;
		}

		current->next = newNode;
	}
}

void insertBeginning(Node** head, int data) {
	Node* newNode = createNode(data);
	newNode->next = *head;
	*head = newNode;
}

void insertAt(Node** head, int data, int pos) {
	if (pos < 1) {
		printf("Invalid position\n");
	} else if (pos == 1) {
		insertBeginning(head, data);
	} else {
		Node* current = *head;
		int currentPosition = 1;
		while(current != NULL && currentPosition < pos) {
			current = current->next;
			currentPosition++;
		}

		if(current == NULL) {
			printf("Invalid Position\n");
		} else {
			Node* newNode = createNode(data);
			newNode->next = current->next;
			current->next = newNode;
		}
	}
}

void delete(Node** head, int data) {
	Node* current = *head;
	Node* prev = NULL;

	while(current != NULL && current->data != data) {
		prev = current;
		current = current->next;
	}

	if(current == NULL) {
		printf("Item not found!\n");
	} else {
		if (prev == NULL) {
			*head = current->next;
		} else {
			prev->next = current->next;
		}
		free(current);
	}
}

int find(Node* head, int data) {
    Node* current = head;
    int position = 1;

    while (current != NULL) {
        if (current->data == data) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1;
}

void printList(Node* head) {
	Node* current = head;

	while(current != NULL) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
}

void freeList(Node** head) {
    Node* current = *head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main() {
	Node* head = NULL;

	insertEnd(&head, 10);
	insertBeginning(&head, 20);
	insertEnd(&head, 30);
	insertAt(&head, 40, 2);
	delete(&head, 10);

	printList(head);

	freeList(&head);
	
	return 0;
}
