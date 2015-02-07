#include<iostream.h>
#include<math.h>
#include<conio.h>
float area(float p)
{
return 3.14*p*p;
}

float area(int p)
{
return p*p;
}

float area(float p,float q)
{
return p*q;
}

int main()
{
    system("CLS");
int p,q,ch;
float a,b,r;
char choice;
do{
cout<<"\n\nChoose from the following : ";
cout<<"\n\n1. Area of square ";
cout<<"\n\n2. Area of circle ";
cout<<"\n\n3. Area of rectangle ";
cout<<"\n\nEnter your choice : "; cin>>ch;

switch(ch)
{
case 1: cout<<"\n\nEnter side of square : ";
	cin>>p;
	cout<<"\n\narea of square is : "<<area(p);
	break;

case 2: cout<<"\n\nEnter radius of circle : ";
	cin>>a;
	cout<<"\n\narea of circle is : "<<area(a);
	break;

case 3: cout<<"\n\nEnter length of rectangle : ";
	cin>>a;
	cout<<"\n\nEnter breadth of rectangle : ";
	cin>>b;
	cout<<"\n\narea of rectangle is : "<<area(a,b);
	break;

}
cout<<"\n\nWant to choose again : ";
cin>>choice;
}while(choice=='y'||choice=='Y');

getch();

}
