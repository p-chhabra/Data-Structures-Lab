#include<bits/stdc++.h>
using namespace std;

void insertSorted(int arr[], int &size , int element)
{
    int i = size - 1;
    while(arr[i]>element && i>=0)
    {
        arr[i+1] = arr[i];
        i--;
    }
    arr[i+1] = element;
    size++;
}

void deleteElement(int arr[], int &size, int index)
{
    for(int i = index; i<size; i++)
    {
        arr[i] = arr[i+1];
    }
    size--;
}

void binarySearch(int arr[], int &size, int element)
{
    int s = 0;
    int e = size - 1;
    int mid = (s + e)/2;
    bool found = false;

    while(s<=e)
    {
        if(arr[mid] < element)
        {
            s = mid + 1;
        }
        if(arr[mid] > element)
        {
            e = mid - 1;
        }
        if(arr[mid] == element)
        {
            found = true;
            deleteElement(arr, size, mid);
        }
        mid = (s+e)/2;
    }
    if(found == false)
        insertSorted(arr, size, element);
}

int main()
{
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int * arr = new int[100];

    cout<<"Enter the elements in array in ascending order: "<<endl;
    for(int i = 0; i< size ; i++)
    {
        cin>>arr[i];
    }

    binarySearch(arr, size, 8);
    for(int i = 0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
