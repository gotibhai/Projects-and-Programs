#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct node{
       int data;
       node *next;
       };
       
class Stack 
{
      node *front,*rear;
      public:
      Stack()
      {
             front=NULL;
             rear=NULL;
             }
      void qinsert()
      {
           node *temp = new node;
           cout<<" Enter the data >";
           cin>>temp->data;
           temp->next=NULL;
           if(rear == NULL) 
           {
               rear = temp;
               front = temp;
               }
           else
           {
               rear->next=temp;
               rear=temp;            
               }
           getch();
           }
      void qdelete()
      {
           if( front == NULL)
            {
            cout<<"Queue Underflow";
            rear=NULL;
            getch();
            exit(3);
                 }
          else
          {        
           node *temp = front;
           front=front->next;
           cout<<temp->data<<" Deleted!";
           delete temp;
           getch();
                 }
          }
      void qdisplay()
      {
           node *temp;
           temp=front;
           while ( temp != NULL )
           {
                 cout<<temp->data<<" ";
                 temp=temp->next;
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
          cout<<" 1.Insert\n 2.Delete\n 3.Display\n 4.Exit\n ";
          cout<<"Ans : ";
          cin>>k;
          switch(k)
          {
                   case 1: {obj1.qinsert(); 
                           break;}
                   case 2: {obj1.qdelete(); 
                            break;}
                   case 3:  {obj1.qdisplay(); 
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

                   
                   
          
          
