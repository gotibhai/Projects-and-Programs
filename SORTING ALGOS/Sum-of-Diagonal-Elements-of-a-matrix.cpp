#include <iostream>
using namespace std;
 int main() 
 {
     int arr[3][3],k;
     int i,j,sum=0,sum1=0,total_sum;
     cout<<"Enter the Elements of the 2-Dimensional 3x3 Matrix : "<<endl;
     for (i=0;i<3;i++)
     {
         for(j=0;j<3;j++)
         {
             cin>>arr[i][j];
         }
     }
     
     for(i=0;i<3;i++)
     {
         for(j=0;j<3;j++)
         { 
            if(i==1 && j==1)
            continue;
            else if(i==j)
             sum=sum+arr[i][j];
         }
     }
     
     i=2;
     j=0;
     while( i>=0 && j<3)
     {
        sum1=sum1+arr[i][j];
     	i--;
     	j++;
     }
    total_sum=sum+sum1;
    cout<<"The Total Sum of the Diagonal Elements is : ";
     cout<<total_sum<<endl;
     
     cin>>k;
 }
