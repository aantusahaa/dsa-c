#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

typedef struct {
  int data[STACK_SIZE];
  int top;
} Stack;

Stack* createStack() {
  Stack* stack = (Stack*)malloc(sizeof(Stack));
  stack->top = -1;
  return stack;
}

int isFull(Stack* stack) { return stack->top == STACK_SIZE - 1; }

int isEmpty(Stack* stack) { return stack->top == -1; }

void push(Stack* stack, int value) {
  if (isFull(stack)) {
    printf("Stack Overflow!\n");
  } else {
    stack->data[++stack->top] = value;
  }
}

int pop(Stack* stack) {
  if (isEmpty(stack)) {
    printf("Stack Underflow!\n");
  } else {
    return stack->data[stack->top--];
  }
}

int peek(Stack* stack) {
  if (isEmpty(stack)) {
    printf("Stack is Empty!\n");
  } else {
    return stack->data[stack->top];
  }
}

void display(Stack* stack) {
  if (isEmpty(stack)) {
    printf("Stack is Empty!\n");
    return;
  }

  printf("---\n");
  for (int i = stack->top; i >= 0; i--) {
    printf("%d\n", stack->data[i]);
    printf("---\n");
  }
}

int main() {
  Stack* stack = createStack();
  push(stack, 10);
  push(stack, 20);
  push(stack, 30);
  push(stack, 40);
  push(stack, 50);
  pop(stack);
  pop(stack);
  display(stack);

  return 0;
}