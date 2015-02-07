#include<iostream.h>
#include<string.h>
#include<conio.h>

int main()
{
system("CLS");
char *str= new char[256];

cout<<"\n\nEnter the string : ";
cin.getline(str,256);

cout<<"\n\nThe string length => "<<strlen(str);

cout<<"\n\nThe reverse string is : ";

char intermediate;

for(int j=strlen(str)-1,i=0; i<=strlen(str)/2; j--,i++)
{
intermediate = *(str+j);

*(str+j)=*(str+i);

*(str+i)=intermediate;
}
cout<<str;

getch();
}
