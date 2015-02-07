#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>

int pop(int[],int&);
int push(int[],int&,int);
void display(int[],int);

const int size=50;

int main()
	{
	  system("CLS");
	  char m,ch;
	  int k,stack[size],item,top=-1,res;
	  start:
	  do
	  {	 cout<<"\nChoose from the following : \n\n"
		<<"\n 1. Push"
		<<"\n 2. Pop"
		<<"\n 3. Display"
		<<"\n 4. Exit"
		<<"\n\nEnter your choice : ";  cin>>k;

	    switch(k)
	    {
	    case 1: ch='y';
		      while(ch=='y'||ch=='Y')
		      {	 cout<<"\nEnter the element : ";
			cin>>item;
			res=push(stack,top,item);
			if(res==-1)
			{cout<<"\nOverflow !!!!";
			exit(1); }
			cout<<"\nThe stack formed is : \n\n";
			display(stack,top);
			cout<<"\n\nWant to enter again ?(Y/N) : ";
			cin>>ch;
		      }
		      break;

	      case 2: ch='y';
		      while(ch=='y'||ch=='Y')
		      { 
               res=pop(stack,top);
			   if(res==-1)
		         	{ 
                         cout<<"\nUnderflow !!!!";
                         getch();
			             exit(1);  
                    }
			  else
			        { 
                          cout<<"\nThe deleted Element is : "<<res<<endl;
			              cout<<"\nThe resultant stack is : \n\n";
			              display(stack,top); 
                    }
			  
              cout<<"\nWant to delete again ? (Y/N): ";
			  cin>>ch;
			  
          }
		      break;

	      case 3: 
                    cout<<"\nThe resultant stack is  : ";
                    display(stack,top);
		            break;

	      case 4: exit(0);
		      break;

	     default: cout<<"\nPlease enter desired choice : ";
	    } 					// end of switch

	    cout<<"\n\nChoose from the menu again ? : ";
	    cin>>m;

	    }
      while(m=='y'||m=='Y');			// end of do-while loop
	  getch();
	  goto start;
	}					// end of main()

 int push(int stack[],int &top,int el)
	{
       if(top==size-1)
	   return -1;
	   else
	    { 
          top++;
	      stack[top]=el;
	      return 0; 
         }
	}

 int pop(int stack[],int &top)
	{ 
      int ret;
	  if(top==-1)
	  return -1;
	  else
	       { 
             ret=stack[top];
	    	 top--;
	    	 return ret;
	       }
}

 void display(int stack[],int top)
	{ 
      cout<<stack[top];
	  for(int i=top-1;i>=0;i--)
	  cout<<stack[i];
	}
