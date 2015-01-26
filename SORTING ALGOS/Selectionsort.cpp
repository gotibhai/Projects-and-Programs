#include<iostream.h>
#include<fstream.h>
using namespace std;
void printarr(int arr[],int n)
{
     cout<<endl;
     cout<<endl;
     for(int j=0; j<n;j++)
    {
            if(j==9)
            {cout<<arr[j];}
            else
            cout<<arr[j]<<", ";
    }
    cout<<endl;
}
void selectionsort(int arr[], int n)
{
     int i,l,temp,min;
     for(i=0;i<n-1;i++)
     {
           min=i; 
             for (l=i+1;l<n;l++)
             {
                 if(arr[l] < arr[min])
                 min=l;
             }
        
          temp=arr[l];
          arr[l]=arr[min];
          arr[min]=temp;
        
     }
}
int main()
{
    int k;
    int arr[10]= {10,9,8,7,6,5,4,3,2,1};
    cout<<"The Array supplied is : "; 
    //calling the print array function
    printarr(arr,10);
    cout<<endl;
    
    //sorting the array
    selectionsort(arr,10);
    
    //calling the print array function again!
    cout<<"The Sorted Array is : ";
    printarr(arr,10);
    
    cin>>k;
    return 0; 
    
}
