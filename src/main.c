#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

void insertAtBeginning(struct node **ref, int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));

  new_node->data = data;
  new_node->next = (*ref);

  (*ref) = new_node;
}

void insertAfter(struct node *node, int data) {
  if (node == NULL) {
    printf("the given previous node cannot be NULL");
    return;
  }

  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = node->next;
  node->next = new_node;
}

void insertAtEnd(struct node **ref, int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  struct node *last = *ref;

  new_node->data = data;
  new_node->next = NULL;

  if (*ref == NULL) {
    *ref = new_node;
    return;
  }

  while (last->next != NULL) {
    last = last->next;
  }

  last->next = new_node;
}

void deleteNode(struct node **ref, int key) {
  struct node *temp = *ref, *prev;
  if (temp != NULL && temp->data == key) {
    *ref = temp->next;
    free(temp);
    return;
  }

  while (temp != NULL && temp->data != key) {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL)
    return;

  prev->next = temp->next;

  free(temp);
}

void printLinkedList(struct node *p) {
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
}

int main() {
  struct node *head = NULL;

  insertAtEnd(&head, 1);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 3);
  insertAtEnd(&head, 4);
  insertAfter(head->next, 5);

  printf("Linked list: ");
  printLinkedList(head);

  printf("\nAfter deleting an element: ");
  deleteNode(&head, 3);
  printLinkedList(head);
}
