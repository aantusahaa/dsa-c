#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

typedef struct {
  int data[QUEUE_SIZE];
  int front, rear;
} Queue;

Queue* createQueue() {
  Queue* queue = (Queue*)malloc(sizeof(Queue));
  queue->front = queue->rear = -1;
  return queue;
}

int isFull(Queue* queue) {
  return (queue->rear + 1) % QUEUE_SIZE == queue->front;
}

int isEmpty(Queue* queue) { return queue->front == -1; }

void enqueue(Queue* queue, int value) {
  if (isFull(queue)) {
    printf("Queue Overflow!\n");
  } else {
    if (isEmpty(queue)) {
      queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % QUEUE_SIZE;
    queue->data[queue->rear] = value;
  }
}

int dequeue(Queue* queue) {
  if (isEmpty(queue)) {
    printf("Queue Underflow!\n");
    return -1;
  } else {
    int value = queue->data[queue->front];
    if (queue->front == queue->rear) {
      queue->front = queue->rear = -1;
    } else {
      queue->front = (queue->front + 1) % QUEUE_SIZE;
    }
    return value;
  }
}

int front(Queue* queue) {
  if (isEmpty(queue)) {
    printf("Queue is Empty!\n");
    return -1;
  } else {
    return queue->data[queue->front];
  }
}

void display(Queue* queue) {
  if (isEmpty(queue)) {
    printf("Queue is Empty!\n");
    return;
  }

  int i = queue->front;
  do {
    printf("%d ", queue->data[i]);
    i = (i + 1) % QUEUE_SIZE;
  } while (i != (queue->rear + 1) % QUEUE_SIZE);
}

int main() {
  Queue* queue = createQueue();
  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);
  enqueue(queue, 40);
  enqueue(queue, 50);
  dequeue(queue);
  dequeue(queue);
  display(queue);

  return 0;
}