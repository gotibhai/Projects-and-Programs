#include <iostream.h>
#include <conio.h>
void printarr(int arr[][3])
{
  int i,j;
  for(i=0;i<3;i++)
  {
     for(j=0;j<3;j++)
     {
       cout<<arr[i][j]<<" ";
     }
     cout<<endl;
  }
}

int main()
{
  system("CLS");
 cout<<" MATRIX MULTIPLICATION OF TWO 3X3 MATRIX "<<endl;
 cout<<endl;
 int i,j,sum1=0;
 int arr1[3][3]={1,2,3,4,5,6,7,8,9};
 int arr2[3][3];
 int count=9;
 for(int k=0;k<3;k++)
 {
   for(int l=0;l<3;l++)
   {
     arr2[k][l]=count;
     count--;
   }
 }
 int arr3[3][3]={0};
 cout<<" MATRIX 1 : "<<endl<<endl;
 printarr( arr1 );
 cout<<endl;
 cout<<endl;
 cout<<" MATRIX 2 : "<<endl<<endl;
 printarr( arr1);
 int x=0,y=0;

      for(int z=0;z<3;z++)
      {
	 for(y =0; y<3;y++)
	 {
	    for(i=0;i<3;i++)
	   {
	    sum1=sum1 + arr1[z][i]*arr2[i][y];
	    }
	    arr3[x][y]=sum1;
	    sum1=0;
	 }
	 x++;
       }
       cout<<endl;
       cout<<"SUM OF MATRIX 3 :\n";
 printarr(arr3);

 getch();
 return 0;

 }



