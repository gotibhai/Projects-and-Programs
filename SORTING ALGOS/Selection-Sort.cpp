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
     int i,j,temp,min;
     for(i=0;i<n-1;i++)
     {
           min=i; 
             for (j=1+i;j<n;j++)
             {
                 if(arr[j]<arr[min])
                 min=j;
             }
        if(min != i)
        {
          temp=arr[j];
          arr[j]=arr[min];
          arr[min]=temp;
        }
     }
}
int main()
{
    int k;
    int arr[11]= {11,2,4,7,31,5,9,8,12,19,1};
    cout<<"The Array supplied is : "; 
    //calling the print array function
    printarr(arr,10);
    cout<<endl;
    
    //sorting the array
    selectionsort(arr,11);
    
    //calling the print array function again!
    cout<<"The Sorted Array is : ";
    printarr(arr,10);
    
    cin>>k;
    return 0; 
    
}
