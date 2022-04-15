#include<iostream>
using namespace std;

void bubbleSort(int arr[], int size)
{
    for(int i = 0; i<size; i++)
    {
        int flag = 0;
        for(int j = 0; j<size - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            break;
        }
    }
}

int main()
{
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int * arr = new int[size];
    cout<<"Enter the elements in the array"<<endl;
    for(int i = 0; i<size; i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"Array before sorting"<<endl;
    for(int i = 0; i<size; i++)
    {

        cout<<arr[i]<<" ";
    }

    bubbleSort(arr, size);

    cout<<endl<<endl<<"Array after sorting"<<endl;
    for(int i = 0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }

    delete arr;

    return 0;
}
