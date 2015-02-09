#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 10
using namespace std;

class queue
{
     int data[SIZE];
     int front,rear;
     
     public:
      queue()
      {            
             front=-1;
             rear=-1;
             cout<<"Front : "<<front<<" Rear : "<<rear<<endl<<endl;
             getch();
             }
      void qInsert()
      {
           if( rear == SIZE-1)
           {
               cout<<"Queue Overflow!\n";
                cout<<"Front : "<<front<<" Rear : "<<rear<<endl<<endl;
                getch();
                }
           if( front == -1)
           {
               front++;
                cout<<"Front : "<<front<<" Rear : "<<rear<<endl<<endl;
                getch();
                }
           else
           {
             rear++;
             cout<<"Enter the value : ";
             cin>>data[rear];
              cout<<"Front : "<<front<<" Rear : "<<rear<<endl<<endl;
              getch();
             }
      }
      void qDelete()
      {
           if ( front == -1)
           {
              cout<<"Queue Underflow! \n";
              getch();
              exit(5);
              }
           
           else
           {
               cout<<"Front : "<<front<<" Rear : "<<rear<<endl<<endl;
               getch();
               cout<<data[front]<<" Deleted!\n\n";
               if(front == rear)
               {
                        front=-1;
                        rear=-1;
                        }
               front++;
               cout<<endl;
                cout<<"Front : "<<front<<" Rear : "<<rear<<endl<<endl;
               getch();
               }
               
        }
    void display()
    {
         int temp=front;
         while( temp>0 )
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
                   case 1: {obj1.qInsert(); 
                           break;}
                   case 2: {obj1.qDelete(); 
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
    
                       
           
           
           
      
      
      
