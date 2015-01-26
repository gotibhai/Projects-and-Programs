#include<fstream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>

struct sports {
		 char event[20];
		 char participants[10][30];
		 int no_of_participants;
	      } s[20], s2[20];

void copy(fstream &ob);
int i=0;

void main()
{
clrscr();

char choice;

fstream ob("sports.dat",ios::binary|ios::in|ios::out);

do
{
if(i>0)
cin.get();

cout<<"\n\nEnter the name of Event : ";
cin.getline(s[i].event,20);

cout<<"\n\nEnter the total number of participants in Event "<<s[i].event<<" : ";
cin>>s[i].no_of_participants;

cout<<"\n\nEnter the name of Praticipants : \n";
cin.get();

for(int j=0; j<s[i].no_of_participants; j++)
cin.getline(s[i].participants[j],30);

ob.write((char*)&s[i], sizeof(sports));

cout<<"\n\n\nWant to Enter Details of Another Event (Y/N) : ";
cin>>choice;
i++;
}while(choice=='y'||choice=='Y');

cout<<"\n\n\n\n\n*****************************************************************************\n\n";

copy(ob);



cout<<"\n\n*****************************************************************************\n\n\n";

getch();

}


void copy(fstream &o)
{
sports s[20];
o.seekg(0);

ofstream file;
file.open("athletic.dat",ios::binary);
file.seekp(0);

int j;
int c=0;

while(o)
{
   o.read((char*)&s[c], sizeof(sports));

   if(strcmp("athletic",s[c].event)==0)
	{
		file.write((char*)&s[c], sizeof(sports));
		break;
	}
   c++;
}

o.close();
file.close();


sports sp;

ifstream oo;
oo.open("athletic.dat",ios::binary);

while(oo)
{
	oo.read((char*)&sp, sizeof(sports));

}

cout<<"\n\nThe Records of file are : \n\n";

cout<<"\n\nEvent = "<<sp.event;

cout<<"\n\n\n\nThe Participants are : \n\n";
for(int i=0; i<sp.no_of_participants; i++)
{
cout<<sp.participants[i]<<"\n\n";
}

oo.close();

remove("athletic.dat");
remove("sports.dat");

}









