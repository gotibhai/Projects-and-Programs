#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class stack
{
      public:

      int data[100];
      int top;
      stack()
      {            
             top=0;
             }
      void push()
      {
           if( top == 99 )
           cout<<"Stack Overflow!\n";
           else
           {
             top++;
             cout<<"Enter the value : ";
             cin>>data[top];
             getch();
             }
      }
      void pop()
      {
           if ( top == 0)
           {cout<<"Stack Underflow! \n";
              getch();}
           
           else
           {
               cout<<data[top]<<" Deleted!\n";
               top--;
               getch();
               }
               
        }
    void display()
    {
         int temp=top;
         while( temp> 0 )
         {
                cout<<data[temp]<<" ";
                temp--;
                }
         getch();
         
    }
    
}obj1;

int main()
{
    int k;
    do{
          system("CLS");
          cout<<"Choose your option : \n";
          cout<<" 1.Push\n 2.Pop\n 3.Display\n 4.Exit\n ";
          cout<<"Ans : ";
          cin>>k;
          switch(k)
          {
                   case 1: {obj1.push(); 
                           break;}
                   case 2: {obj1.pop(); 
                            break;}
                   case 3:  {obj1.display(); 
                            break;}
                   case 4: {  getch();
                              exit(9); }
                   default: {cout<<"Enter the correct option !\n"; 
                            break;}
                   }
          }
    while (k != 4);
    {
          getch();
          exit(9);
          
     }

return 0;
system("pause");

}
    
                       
           
           
           
      
      
      
