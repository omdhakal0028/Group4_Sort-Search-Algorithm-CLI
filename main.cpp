#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

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
  cout << "Displaying all Records >..<" << endl;
  cout << endl;
  for (int i = 0; i < n; i++) {
    cout << "[arr" << (i + 1) << "->" << arr[i] << "] ";
    if ((i + 1) % 10 == 0) {
      cout << endl;
    }
  }
}
void selectionSort(int arr[], int n) {
  int min_idx;
  int temp;
  for (int i = 0; i < n - 1; i++) {
    min_idx = i;

    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }

    if (min_idx != i) {
      temp = arr[i];
      arr[i] = arr[min_idx];
      arr[min_idx] = temp;
    }
  }
}
void sortMenu() {
  cout << endl;
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
    selectionSort(arr, n);
    
  } else if (sortChoice == 2) {
    // quick sort
  } else if (sortChoice == 3) {
    // merge sort
  } else {
    cout << "Enter Valid choice :( " << endl;
  }
}

void searchMenu() {
  cout << endl;
  cout << "Welcome >< Which Searching Algorithm would you like to choose :) "
       << endl;
  cout << "--------------------------------------------------------------"
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
  cout << "Welcome >< Generated 100 dummy Arrays :) " << endl;
  while (true) {
    cout << "----------------------------------------" << endl;
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