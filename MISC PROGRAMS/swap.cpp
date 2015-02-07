#include<iostream.h>
#include<conio.h>

void swap_using_pointers(int &a, int &b);

int main()
{
system("CLS");

int a,b;

cout<<"\n\nEnter first  integer : "; cin>>a;
cout<<"\n\nEnter second integer : "; cin>>b;
swap_using_pointers(&a,&b);
getch();
}


swap_using_pointers(&a,&b)
{
cout<<"\n\nNow value of first  integer = "<<a;
cout<<"\n\nNow value of second integer = "<<b;

}
