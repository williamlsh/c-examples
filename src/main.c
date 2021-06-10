#include "stdio.h"
#define SIZE 5

void enqueue(int);
void dequeue();
void display();

int items[SIZE], front = -1, rear = -1;

int main() {
  //deQueue is not possible on empty queue
  dequeue();

  //enQueue 5 elements
  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(4);
  enqueue(5);

  // 6th element can't be added to because the queue is full
  enqueue(6);

  display();

  //deQueue removes element entered first i.e. 1
  dequeue();

  //Now we have just 4 elements
  display();

  return 0;
}

void enqueue(int value) {
  // Check if queue is full.
  if (rear == SIZE - 1) {
    printf("\nQueue is Full!!");
  } else {
    // for the first element, set the value of front to 0.
    if (front == -1) {
      front = 0;
    }
    // increase the rear index by 1.
    rear++;
    // add the new element in the position pointed to by rear.
    items[rear] = value;
    printf("\nInserted -> %d", value);
  }
}

void dequeue() {
  // Check if the queue is empty.
  if (front == -1) {
    printf("\nQueue is Empty!!");
  } else {
    // Return the value pointed by front.
    printf("\nDeleted : %d", items[front]);
    // Increase the front index by 1.
    front++;
    if (front > rear) {
      // For the last element, reset the values of front and rear to -1.
      front = rear = -1;
    }
  }
}

void display() {
  if (rear == -1) {
    printf("\nQueue is Empty!!!");
  } else {
    printf("\nQueue elements are:\n");
    for (int i = front; i <= rear; ++i) {
      printf("%d  ", items[i]);
    }
  }
  printf("\n");
}