
#include<iostream.h>
#include<conio.h>
#include<process.h>

const int size=50;

int q[size],rear=-1,front=-1;

int insert(int q[],int ele)
	{
	  	if(rear==size-1)
	  	return(-1);
	  	else if(rear==-1)
	   		 {
	    			front=rear=0;
	    			q[rear]=ele;
	    		}
	  	else
	   		 { 
rear++;
	      			q[rear]=ele;
	   		 }
	  	return(0);
	}

int delet(int q[])
	{  
     int r ;
 
	  	if(front==-1)
	 		 return(-1);
	 	 else
	    		{ 
r=q[front];
	     			 if(rear==front)
	      			front=rear=-1;
	      			else
	     			 front++;
	    		}
	  	return r;
	}

void display(int q[],int front,int rear)
	{ 
if(front==-1)
	  		return;
	  	else
	   		 {
	     			 for(int i=front;i<=rear;i++)
	     			 cout<<q[i]<<" ";
	    		}
	}

int main()
	{ 
  system("CLS");
	  int n,u,k,m;
	  char ch,ans;
	  do
	  {
 cout<<"\nChoose from the menu :\n"
		<<"\n 1. Insert"
		<<"\n 2. Delete"
		<<"\n 3. Display"
		<<"\n\n Enter your choice : ";  cin>>n;

	    switch(n)
	    { 
    case 1: ans='y';
		      while(ans=='y'||ans=='Y')
		     	 { 
cout<<"\n Enter element to be inserted :"; cin>>m;
			
k=insert(q,m);
			
if(k==-1)
					cout<<"\n Overflow !!!!";
			
cout<<"\n The resultant Queue is : ";

			display(q,front,rear);

			cout<<"\n\n Want to enter again ?: ";

			cin>>ans; 
}
		      break;

	      case 2: ans='y';
		      while(ans=='y'||ans=='Y')
		     	 { 
   u=delet(q);
				if(u==-1)
					{ 
cout<<"\n Underflow !!!!";
			  		break;
					}
				else
					{
					cout<<"\n The deleted element is "<<u<<"\n";
					cout<<"\n The resultant Queue is : \n\n";
					display(q,front,rear);  
}
			cout<<"\n\n Want to delete again ?: ";
			cin>>ans;

			}

		      	break;

	      case 3: cout<<"\n The Queue is : \n\n";
		      display(q,front,rear);
		      break;

	     default: cout<<"\n Please enter desired keyword : ";
	    }
	    
cout<<"\n Choose from the menu again ? : ";cin>>ch;

}while(ch=='y'||ch=='Y');
  getch();
}
