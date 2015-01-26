#include <iostream>
using namespace std;
void insertionsort( int arr[], int n)
{
     int i,j;
     cout<<"Unsorted Array: ";
     for(i=0;i<n;i++)
    {
    	cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
    for( i=1;i<n;i++)
    {
        int element=arr[i];
        j=i-1;
        while((j>=0) && (element<arr[j]))
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=element;
    }
     cout<<"Sorted Array : ";
     for(i=0;i<n;i++)
    {
    	cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int k;
    int arr[6]={7,5,4,1,3,2};
    insertionsort(arr,6);
    
    cin>>k;
    return 0;
}
