#include<fstream.h>
#include<conio.h>
void main()
{
clrscr();

int a[10]; float b[10];

for(int i=0; i<10; i++)
{
cout<<"\n\nEnter the roll no. of student "<<i+1<<" : "; cin>>a[i];
cout<<"\n\tEnter the marks of student "<<i+1<<" => "; cin>>b[i];
}



ofstream student;
student.open("stud.txt");
for(i=0; i<10; i++)
{
student<<"\n\nMarks of roll no. "<<a[i]<<" => "<<b[i];

}

student.close();

  i=0;

char str[80][80];
ifstream stude;
stude.open("stud.txt",ios::in);
stude.seekg(0);
while(!stude.eof())
{stude.getline(str[i],80);
cout<<str[i]<<"\n\n";
i++;
}
getch();

}



