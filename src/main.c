#include <stdio.h>
#include <stdlib.h>

// Create a node.
struct node {
  int data;
  struct node *next;
};

void insertAtBeginning(struct node **ref, int data) {
  // Allocate memory to a node.
  struct node *new_node = (struct node *)malloc(sizeof(struct node));

  // Insert the item.
  new_node->data = data;
  new_node->next = (*ref);

  // Move head to new node.
  (*ref) = new_node;
}

// Insert a node after a node.
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

  // Find the key to be deleted.
  while (temp != NULL && temp->data != key) {
    prev = temp;
    temp = temp->next;
  }

  // If the key is not present.
  if (temp == NULL)
    return;

  // Remove the node.
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
