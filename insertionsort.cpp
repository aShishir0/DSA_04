#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;


void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " "<<endl;
    
}


int main()
{
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    cout<<endl;
    int randArray[n];
    for (int i=0;i<n;i++)
    {
        randArray[i]=rand()%200;
    }
    printArray(randArray,n);
    cout<<endl<<endl;
  auto start = std::chrono::system_clock::now();
    insertionSort(randArray,n);
  auto end = std::chrono::system_clock::now();

   printArray(randArray,n);


   auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;
}


























