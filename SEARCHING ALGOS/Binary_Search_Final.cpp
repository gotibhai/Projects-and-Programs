#include<iostream.h>

void BinarySearch(int arr[], int ub, int key)
{
       int pos,mid;
       int lb=0;

       // To start, find the subscript of the middle position.
       pos = -1;
       mid = (lb+ub) / 2; 
       while((arr[mid] != key) && (lb <= ub))
       {
              
                          
              if (arr[mid] > key)               // If the number is > key, ..
              {                                                       // decrease position by one.
                    ub = mid - 1;    
              }                                                      
              else                                               
              {                                                        // Else, increase position by one.
                   lb= mid + 1;     
              }
       mid = (lb+ub) / 2;   
       }
      if (lb <= ub)
      {
            cout<< "The number was found at position "<<mid+1<<endl<<endl;              
       }      
       else
             cout<< "Sorry, the number is not in this array."<<endl;
      
}
int main()
{
    int key,i;
    int array1[10]={1,2,4,6,8,9,10,17,19,23};
    
    cout<<"What number do you want to search for?"<<endl;
    cin>>key;
    BinarySearch(array1,10,key);
    
    cout<<"-------------------------------------------------------------------------------"<<endl<<endl;
    cout<<" FOR REFERRENCE : ";
    for(int j=0; j<10;j++)
    {
            if(j==9)
            {cout<<array1[j];}
            else
            cout<<array1[j]<<", ";
            
            }
            cout<<endl;
cin>>i;
return 0;
} 
