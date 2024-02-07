#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int low, int high, int key) {
  if (low > high) return -1;

  int mid = low + (high - low) / 2;

  if (arr[mid] == key) return mid;
  if (arr[mid] > key) return binarySearch(arr, low, mid - 1, key);
  if (arr[mid] < key) return binarySearch(arr, mid + 1, high, key);
}

int main() {
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int searchIndex = binarySearch(arr, 0, 9, 5);

  if (searchIndex == -1) {
    printf("Element not found\n");
  } else {
    printf("Element found at index %d\n", searchIndex);
  }

  return 0;
}