#include <stdio.h>
#include <stdlib.h>

typedef struct Linkedlist{
	int data;
	struct Linkedlist* next;
} Linkedlist;

Linkedlist* allocNode(int data){
	Linkedlist* next_Linkedlist = (Linkedlist*)calloc(1, sizeof(Linkedlist));
	next_Linkedlist->data = data;
	next_Linkedlist->next = NULL;
	return next_Linkedlist;
}

Linkedlist* appendList(Linkedlist* head, char val) {
	if(head == NULL) {
		return allocNode(val);
	}
	Linkedlist* list = head;
	while(list->next != NULL) {
		list = list->next;
	}
	list->next = allocNode(val);
	return head;
}

void showList(Linkedlist* head) {
	while(head != NULL) {
		printf("[%c]->", head->data);
		head = head->next;
	}
	printf("->NULL\n");
}

Linkedlist* reverseList(Linkedlist* list) {
  Linkedlist* prev = NULL;
  Linkedlist* current = list;
  Linkedlist* next = NULL;
  while (current != NULL) {
    next = current -> next;
    current -> next = prev;
    prev = current;
    current = next;
  }
  return prev;
}

int main() {
    struct Linkedlist* head = NULL;
    head = appendList(head, 'A');
    head = appendList(head, 'B');
    head = appendList(head, 'C');
    head = appendList(head, 'D');
    head = appendList(head, 'E');
    showList(head);
    head = reverseList(head);
    showList(head);
    return 0;
}
