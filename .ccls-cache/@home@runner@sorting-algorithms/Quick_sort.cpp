//this is simple code with understandable comments

#include <iostream>
using namespace std;
int partition(int arr[], int start, int end) {
  // lets make the first element as pivot
  int pivot = arr[start];
  // geting the correct position of pivot element
  int count = 0;
  for (int i = start + 1; i < end; i++) {
    if (arr[i] <= pivot) {
      count++;
    }
  }
  // strore the index of correct position of pivot element
  int pivotIndex = start + count;
  // put the element at its right position
  swap(arr[pivotIndex], arr[start]);
  // now making the elements less than the pivot in one side and greater than on
  // the other side of pivot
  int i = start;
  int j = end;
  while (i < pivotIndex && j > pivotIndex) {
    // if arr[i] is already smaller than the pivot, just increase the index as
    // i++
    while (arr[i] <= pivot) {
      i++;
    }
    // if arr[ij is already greater than the pivot, just decrease the index as
    // j--

    while (arr[j] > pivot) {
      j--;
    }
    if (i < pivotIndex && j > pivotIndex) {
      swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
  }
}
// making the function for quickSort
void quickSort(int arr[], int start, int end) {
  // base case
  if (start >= end) {
    return;
  }

  // calling the partition function
  int p = partition(arr, start, end);

  // sorting the left part
  quickSort(arr, start, p - 1);
  // sorting the right part
  quickSort(arr, p + 1, end);
}
int main() {
  int arr[5] = {2, 4, 1, 6, 9};
  int n = 5;

  // calling the function
  quickSort(arr, 0, n - 1);

  // printing the function
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}


/* i have optimised this code with little section 
#include <iostream>
using namespace std;

int partition(int arr[], int start, int end) {
  int pivot = arr[start];
  int i = start + 1;
  int j = end;

  while (i <= j) {
    while (i <= j && arr[i] <= pivot) {
      i++;
    }
    while (j >= i && arr[j] > pivot) {
      j--;
    }
    if (i < j) {
      swap(arr[i], arr[j]);
    }
  }

  int pivotIndex = j;

  swap(arr[start], arr[pivotIndex]);

  return pivotIndex;
}

void quickSort(int arr[], int start, int end) {
  if (start < end) {
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
  }
}

int main() {
  int arr[5] = {2, 4, 1, 6, 9};
  int n = 5;

  quickSort(arr, 0, n - 1);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}


*/