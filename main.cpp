#include <chrono>
#include <cstdlib>
#include <iostream>
using namespace std;
using namespace std::chrono;

int n = 100;
int arr[100];
void randomArrays(int n) {
  // Generate random Arrays
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 101;
  }
}
void displayAllRecords() {
  // Display all Arrays
  cout << "----------------------------------------------" << endl;
  cout << "Displaying all Records >..<" << endl;
  cout << endl;
  for (int i = 0; i < n; i++) {
    cout << "[arr" << (i + 1) << "->" << arr[i] << "] ";
    if ((i + 1) % 10 == 0) {
      cout << endl;
    }
  }
}
int selectionSort(int arr[], int n) {
  int min_idx;
  int temp;
  int operationCount = 0;
  for (int i = 0; i < n - 1; i++) {
    min_idx = i;
    for (int j = i + 1; j < n; j++) {
      operationCount++;
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    if (min_idx != i) {
      temp = arr[i];
      arr[i] = arr[min_idx];
      arr[min_idx] = temp;
      operationCount++;
    }
  }
  return operationCount;
}

int merge(int arr[], int left, int mid, int right) {
  int operationCount = 0;
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int *L = new int[n1];
  int *R = new int[n2];

  for (int i = 0; i < n1; i++) {
    L[i] = arr[left + i];
    operationCount++;
  }
  for (int j = 0; j < n2; j++) {
    R[j] = arr[mid + 1 + j];
    operationCount++;
  }

  int i = 0;
  int j = 0;
  int k = left;

  while (i < n1 && j < n2) {
    operationCount++;
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    operationCount++;
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
    operationCount++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
    operationCount++;
  }

  delete [] L;
  delete [] R;
  return operationCount;
}

int mergeSortMain(int arr[], int left, int right) {
  int operationCount = 0;
  if (left < right) {
    int mid = left + (right - left) / 2;

    operationCount += mergeSortMain(arr, left, mid);
    operationCount += mergeSortMain(arr, mid + 1, right);
    operationCount += merge(arr, left, mid, right);
  }
  return operationCount;
}

int mergeSort(int arr[], int n){
  return mergeSortMain(arr, 0, n-1);
}

void sortMenu() {
  cout << "--------------------------------------------------------------"
       << endl;
  cout << "Welcome >< Which Sorting algorithm would you like to choose :) "
       << endl;
  cout << "--------------------------------------------------------------"
       << endl;
  cout << "1. Selection Sort Algorithm" << endl;
  cout << "2. Quick Sort Algorithm" << endl;
  cout << "3. Merge Sort Algorithm" << endl;
  cout << "What you like to do :) ";
  int sortChoice;
  cin >> sortChoice;

  if (sortChoice == 1) {
    cout << "___________________________________________" << endl;
    cout << "Running Selection Sort. Hold on tight :>" << endl;
    auto start = high_resolution_clock::now();
    int totalOperations = selectionSort(arr, n);
    auto stop = high_resolution_clock::now();
    duration<double, milli> duration = stop - start;
    cout << "Operation Count : " << totalOperations << endl;
    cout << "Time Taken      : " << duration.count() << " ms" << endl;

  } else if (sortChoice == 2) {
    // quick sort
  } else if (sortChoice == 3) {
    cout << "___________________________________________" << endl;
    cout << "Running Merge Sort. Hold on tight :>" << endl;
    auto start = high_resolution_clock::now();
    int totalOperations = mergeSort(arr, n);
    auto stop = high_resolution_clock::now();
    duration<double, milli> duration = stop - start;
    cout << "Operation Count : " << totalOperations << endl;
    cout << "Time Taken      : " << duration.count() << " ms" << endl;
  } else {
    cout << "Enter Valid choice :( " << endl;
  }
}

void searchMenu() {
  cout << "--------------------------------------------------------------"
       << endl;
  cout << "Welcome >< Which Searching Algorithm would you like to choose :) "
       << endl;
  cout << "---------------------------------------------------------------"
       << endl;
  cout << "1. Binary Search Algorithm" << endl;
  cout << "2. Interpolation Search Algorithm" << endl;
  cout << "What you like to do :) ";
  int searchChoice;
  cin >> searchChoice;
  if (searchChoice == 1) {
    // binary

  } else if (searchChoice == 2) {
    // interpolation

  } else {
    cout << "Enter Valid choice :( " << endl;
  }
}
void mainMenu() {
  cout << endl;
  cout << "Welcome >< Generated 100 dummy Arrays :) " << endl;
  while (true) {
    cout << "-----------------------------------------" << endl;
    cout << "Group4-Sort-Search-Algorithm-CLI" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "1. Display ALL Records" << endl;
    cout << "2. Sort Records" << endl;
    cout << "3. Search For Number" << endl;
    cout << "4. Exit Application" << endl;
    cout << "What would you like to do :) ";
    int choice;
    cin >> choice;

    if (choice == 1) {
      displayAllRecords();
      cout << endl;
    } else if (choice == 2) {
      sortMenu();
      cout << endl;
    } else if (choice == 3) {
      searchMenu();
      cout << endl;
    } else if (choice == 4) {
      cout << "Have a Good Day :> ";
      break;
    } else {
      cout << "Enter Valid choice :( " << endl;
      cout << endl;
    }
  }
}
int main() {
  randomArrays(100);
  mainMenu();
  return 0;
}