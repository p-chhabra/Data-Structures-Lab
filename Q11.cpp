#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int size){
    for(int i = 0; i<size - 1; i++){
        int flag = 0;
        for(int j = 0; j<size - i - 1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}

///Selection Sort
void selectionSort(int arr[], int size){
    for(int i = 0; i < size; i++){
        int smallIndex = i;
        for(int j = i+1; j<size; j++){
            if(arr[j] < arr[smallIndex]){
                smallIndex = j;
            }
        }
        if(arr[smallIndex] < arr[i]){
            swap(arr[i], arr[smallIndex]);
        }
    }
}

///Merge Sort
void mergeArrays(int x[], int y[], int arr[], int s, int e){
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = s;

    while(i<=mid && j<=e){
        if(x[i] < y[j]){
            arr[k] = x[i];
            i++;
            k++;
        }else{
            arr[k] = y[j];
            j++;
            k++;
        }
    }

    while(i<=mid){
        arr[k] = x[i];
        i++;
        k++;
    }

    while(j<=e){
        arr[k] = y[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int s, int e){
    if(s>=e){
        return;
    }

    int mid = (s+e)/2;
    int x[100], y[100];

    for(int i = s; i<=mid; i++){
        x[i] = arr[i];
    }
    for(int i = mid+1; i<=e; i++){
        y[i] = arr[i];
    }
    mergeSort(x,s,mid);
    mergeSort(y,mid+1,e);
    mergeArrays(x,y,arr,s,e);
}

///Quick Sort
int partition(int arr[], int s, int e){
    int i = s;
    int j = e;
    int countSmaller = s;
    int pivot = arr[e];
    for(int k = s; k<e; k++){
        if(arr[k] < pivot){
            countSmaller++;
        }
    }

    int pivotIndex = countSmaller;
    swap(arr[pivotIndex], arr[e]);

    while(i<pivotIndex && j>pivotIndex){
        if(arr[i] > arr[pivotIndex] && arr[j] < arr[pivotIndex]){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        if(arr[i] < arr[pivotIndex]){
            i++;
        }
        if(arr[j] > arr[pivotIndex]){
            j--;
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e){
    if(s>=e){
        return;
    }
    int p = partition(arr, s, e);
    quickSort(arr, s ,p-1);
    quickSort(arr,p+1, e);
}

void print(int arr[], int size){
    for(int i =0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[] = {7,2,5,9,1,4,0,6};
    int size = 8;
    cout<<"Original Array: ";
    print(arr, size);
    char x;
    cout<<"'s' for selection sort || 'b' for bubble sort || 'm' for merge sort || 'q' for quick sort || 'e' to exit' "<<endl;
    cin>>x;
    while(x !='e'){
        switch(x){
            case 's': {
                selectionSort(arr, size); 
                break;
                }
            case 'b': {
                bubbleSort(arr, size); 
                break;
                }
            case 'm': {
                mergeSort(arr, 0, size-1); 
                break;
                }
            case 'q': {
                quickSort(arr, 0, size-1); 
                break;
                }
            case 'e': break;
            default:{
                cout<<"wrong character entered"<<endl;
            } 
        }
        print(arr,size);
        cout<<"'s' for selection sort || 'b' for bubble sort || 'm' for merge sort || 'q' for quick sort || 'e' to exit' "<<endl;
        cin>>x;
    }
    return 0;
}