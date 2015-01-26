//Linear Search
#include <iostream.h>
#include <string.h>


void lnsearch(int arr[],int x,int size)
{
    int i=0,j=0,k=0;
    int elmpos;
    for (i=0;i<size;i++)
    {
        if(x == arr[i])
        {
                         elmpos=i;
                         cout<<"This element is present at "<<elmpos+1<<" position."<<endl;
                         k++;
                         }
                         
        else if (i==size-1 && k==0)
        {
        cout<<"This number is not present."<<endl;        
        cin>>k;
        
        }
                         
    }
}
                         

int main()
{
    int input,position;
    cout<<"What number do you want to search for ?"<<endl;
    cin>>input;
    
    int newarr[10]={2,7,5,69,8,7,1,13,51,7};
    lnsearch(newarr,input,10);
    
   
    
    cout<<"-------------------------------------------------------------------------------"<<endl<<endl;
    cout<<" FOR REFERRENCE :   ";
    for(int j=0; j<10;j++)
    {
            if(j==9)
            {cout<<newarr[j];}
            else
            cout<<newarr[j]<<", ";
            
            }
    cout<<endl;
    cout<<endl;
system("pause");
}

