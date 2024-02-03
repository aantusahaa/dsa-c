#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* left;
  struct Node* right;
} Node;

void handleFailure(Node* node) {
  if (node == NULL) {
    printf("Memory Allocation Failed!");
    exit(1);
  }
}

Node* createNode(int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  handleFailure(newNode);

  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

Node* insert(Node* root, int data) {
  if (root == NULL) return createNode(data);

  if (data < root->data) {
    root->left = insert(root->left, data);
  } else if (data > root->data) {
    root->right = insert(root->right, data);
  }

  // return the unchanged node pointer
  return root;
}

Node* search(Node* root, int data) {
  if (root == NULL || data == root->data) {
    return root;
  } else if (data < root->data) {
    return search(root->left, data);
  } else {
    return search(root->right, data);
  }
}

void printInOrder(Node* root) {
  if (root != NULL) {
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
  }
}

// Also known as depth-first search (DFS)
void printPreOrder(Node* root) {
  if (root != NULL) {
    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
}

void printPostOrder(Node* root) {
  if (root != NULL) {
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->data);
  }
}

int main() {
  Node* root = NULL;

  root = insert(root, 42);
  insert(root, 28);
  insert(root, 62);
  insert(root, 22);
  insert(root, 33);
  insert(root, 65);
  insert(root, 78);

  printf("In Order: ");
  printInOrder(root);
  printf("\n");

  printf("Pre Order: ");
  printPreOrder(root);
  printf("\n");

  printf("Post Order: ");
  printPostOrder(root);
  printf("\n");

  Node* result = search(root, 33);
  if (result != NULL) {
    printf("Found: %d\n", result->data);
  } else {
    printf("Not Found\n");
  }

  return 0;
}
