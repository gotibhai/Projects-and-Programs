//Program to sort elements using Bubble Sort
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
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
void bubblesort(int a[],int n)
{
     int i,j,temp;
     for(i=0;i<n-1;i++)
     {
        for( j=i+1;j<n;j++)
        {
                if(a[i]>a[j])
                {
                      temp=a[i];
                      a[i]=a[j];
                      a[j]=temp;
                }
        }
     }
}
        
int main()
{
    int arr[10]={9,7,5,6,2,3,4,1,6,2};
    cout<<"The Array supplied is : "; 
    //calling the print array function
    printarr(arr,10);
    cout<<endl;
    //sorting the array
    bubblesort(arr, 10);
    //calling the print array function again!
    cout<<"The Sorted Array is : ";
    printarr(arr,10);
    
    int x;
    cin>>x;
    return 0;
}
