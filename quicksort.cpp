int partition(int arr[],int low,int high,int &operationCount)
{
  int pivot = arr[high];
  int i = low - 1;

  for (int j=low; j<high; j++ )
  {
        operationCount++;

        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
            operationCount++;
        }
    }

    swap(arr[i + 1], arr[high]);
    operationCount++;

    return i + 1;
}

void quickSort(int arr[], int low, int high, int &operationCount)
{
    if (low < high)
    {
        int pi = partition(arr,low,high,operationCount);

        quickSort(arr,low,pi - 1,operationCount);

        quickSort(arr,pi + 1, high,operationCount);
    }
}

  else if (sortChoice == 2) {
    // quick sort
    cout << "___________________________________________"<<endl;
    cout << "Running Quick Sort. Hold on tight :>"<<endl;

    int totalOperations = 0;
    auto start = high_resolution_clock::now();
    quickSort(arr, 0, n - 1, totalOperations);
    auto stop = high_resolution_clock::now();
    duration<double, milli> duration = stop - start;

    cout <<"Operation Count : "<< totalOperations<< endl;
    cout <<"Time Taken      : "<< duration.count()<< " ms" << endl;
}