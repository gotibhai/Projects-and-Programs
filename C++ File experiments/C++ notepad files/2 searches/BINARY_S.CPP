#include<iostream.h>
#include<process.h>
#include<conio.h>
void main()
{ clrscr();
int A[50], n,p;
cout<<"Enter the Size of array : ";
cin>>n;

cout<<"\n\nEnter the elements : \n\n";
for(int i=0; i<n; i++)
cin>>A[i];

cout<<"\n\nArray formed is  : ";
for(i=0; i<n; i++)
cout<<A[i]<<" ";

cout<<"\n\nEnter the element to be searched : ";
cin>>p;

void binary_search(int A[], int n, int p); //declaration

binary_search(A,n,p);

getch();
}

void binary_search(int A[], int n, int p)
{ int L,U,mid;   char ch;
 lb: L=0; U=n-1;

  while(L<=U) //i.e loop will continue if L<=u. if L>U loop will end
  { mid=(L+U)/2;
    if(A[mid]==p)
    { cout<<"\n\nElement "<<p<<" found. Search Successful.";
      cout<<"\n\nSubscript = "<<mid<<" \n\nPosition = "<<mid+1;
      break;
    }
    else if(p<=A[mid])
    U=mid-1;

    else
    L=mid+1;
  }//end of while loop
  if(L>U)
  {cout<<"\n\nUnsuccessful search.";
    cout<<"\n\n\n\nWant to search again. : "; cin>>ch;
    if(ch=='y'||ch=='Y')
    {cout<<"\n\n\n\nEnter the element to be searched : ";
    cin>>p;
    goto lb;}
    else
    exit(1);

  }

}


