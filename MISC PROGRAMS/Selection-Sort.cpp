#include<iostream.h>
#include<conio.h>
void selectionsort(int arr[], int size)
{
//pos_min is short for position of min
	int pos_min,temp;

	for (int i=0; i < size-1; i++)
	{
	    pos_min = i;//set pos_min to the current index of array
		
		for (int j=i+1; j < size; j++)
		{

		if (arr[j] < arr[pos_min])
                   pos_min=j;
	//pos_min will keep track of the index that min is in, this is needed when a swap happens
		}
		
	//if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
            if (pos_min != i)
            {
                 temp = arr[i];
                 arr[i] = arr[pos_min];
                 arr[pos_min] = temp;
            }
	}
}
void printarr(int arr[],int p)
{
     cout<<endl;
     cout<<endl;
     for(int j=0; j<p;j++)
    {
            if(j==6)
            {cout<<arr[j];}
            else
            cout<<arr[j]<<", ";
    }
    cout<<endl;
}
int main()
{
    int k2;
    int arr[7]= {7,8,5,4,6,2,1};
    cout<<"The Array supplied is : "; 
    //calling the print array function
    printarr(arr,7);
    cout<<endl;
    
    //sorting the array
    selectionsort(arr,7);
    
    //calling the print array function again!
    cout<<"The Sorted Array is : ";
    printarr(arr,7);
    
    cin>>k2;
    return 0; 
    
}
