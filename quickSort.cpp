#include<iostream>
#include<random>
#include <chrono>
#include <ctime>
using namespace std;

int partition(int arr[],int start,int end){
    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}

void quickSort(int arr[],int start, int end){
    if(start > end){
        return;
    }

    int p = partition(arr,start,end);

    quickSort(arr,start,p-1);

    quickSort(arr,p+1,end);
}

int main(){
    int n;
    cout<<"Enter the size of array::";
    cin>>n;
    int randArr[n];
    for(int i=0;i<n;i++){
        randArr[i]=rand()%200;
    }

    auto start = std::chrono::system_clock::now();
    quickSort(randArr,0,n-1);
    auto end = std::chrono::system_clock::now();
    for(int j=0;j<n;j++){
        cout<<randArr[j]<<' ';
    }
    cout<<endl;
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;
}
