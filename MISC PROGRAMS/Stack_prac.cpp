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
      node *top;
      public:
      Stack()
      {
             top=NULL;
             }
      void push()
      {
           node *temp = new node;
           temp->next=top;
           cout<<" Enter the data >";
           cin>>temp->data;
           top=temp;
           getch();
           }
      void pop()
      {
           if( top == NULL)
            {
            cout<<"Stack Underflow";
            getch();
            exit(3);
                 }
          else
          {        
           node *temp;
           temp=top;
           top=top->next;
           cout<<temp->data<<" Deleted!";
           delete temp;
           getch();
                 }
          }
      void display()
      {
           node *temp;
           temp=top;
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

                   
                   
          
          
