#include <iostream.h>
#include <Windows.h>


 using namespace std;
 
 void waiting(long double amt)
     {
          int cursor=0,wait=0,no_of_cycles,cycles=0;
          if(amt>=50000)
          no_of_cycles=5;
          else if(amt>=10000 && amt<=50000)
          no_of_cycles=4;
          else
          no_of_cycles=3;
          for(cursor=0;cursor<no_of_cycles;cursor++)
             {
                   cout<<".";
                   Sleep(0700);
  
              }    
                 cout<<endl;                   
     } 


int main()
{
    int i,k;
    cout<<"ENTER YOUR ANSWER ?";
    cin>>i;
    cout<<"Checking";
    waiting(i);
    
    return 0;
    cin>>k;
}
    
