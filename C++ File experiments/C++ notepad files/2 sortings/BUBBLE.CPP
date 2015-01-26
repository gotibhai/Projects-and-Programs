#include<iostream.h>
#include<conio.h>
void main()
{clrscr();
int A[80],n;
cout<<"Enter desired size of array (<80): "; cin>>n;
cout<<"\n\nEnter the array : \n";
for(int i=0; i<n; i++)
cin>>A[i];

cout<<"\n\nArray of elements is as shown below : \n\n";
for(i=0; i<n; i++)
cout<<A[i]<<" ";
cout<<"\n\nNow Elements will be arranged in ascending order using bubble sort :\n\n";

void bubble_sort(int A[],int n);

bubble_sort(A,n);

getch();
}

void bubble_sort (int A[], int n)
{ int temp; int count=0;
for(int i=0; i<n; i++)
{
	for(int j=0; j<n-1; j++)
		{ if(A[j+1]<A[j])
			{ count++;
			  temp=A[j+1];
			  A[j+1]=A[j];
			  A[j]=temp;
			cout<<"\n\nArray for iteration "<<count<<" is : \n\n";
			for(int k=0; k<n; k++)
			cout<<A[k]<<" ";
			}
		}
}
}





