#include<fstream.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
void main()
{
clrscr();
char a[80];
int words=0, upper_letters=0, lower_letters=0, alpha=0, vowels=0,consonants=0;

ofstream string("str.txt");

cout<<"\n\nEnter the string : ";
cin.getline(a,79);

string<<"The string is : "<<a<<"\n\n";

for(int i=0; i<strlen(a); i++)
{
   if(a[i]==' ')
     while(a[i]==' ')
	{
	i++;
	}

   if(isalnum(a[i]))
     {
       while(a[i]!=' ')
	{
	  i++;
	}
       words++;
     }
}
string<<"\n\nThe number of words in string are : "<<words;

string<<"\n\n\nAlphabets in string are : \n\n";
for(i=0; i<strlen(a); i++)
{
  if(isalpha(a[i]))
  {
    alpha++;
    string<<a[i]<<" ";
  }
}
string<<"\n\nTotal number of alphabets in string => "<<alpha;

string<<"\n\n\nUppercase letters in string are : \n\n";
for(i=0; i<strlen(a); i++)
{
  if(isupper(a[i]))
  {
    upper_letters++;
    string<<a[i]<<"  ";
  }
}
string<<"\n\nTotal number of uppercase letters in string => "<<upper_letters;


string<<"\n\n\nLowercase letters in string are : \n\n";
for(i=0; i<strlen(a); i++)
{
  if(islower(a[i]))
  {
    lower_letters++;
    string<<a[i]<<"  ";
  }
}
string<<"\n\nTotal number of Lowercase letters in string => "<<lower_letters;


string<<"\n\n\nVowels in string are : \n\n";
for(i=0; i<strlen(a); i++)
{
  if(isalpha(a[i]))
  {
    if(a[i]=='a'||a[i]=='A'||a[i]=='e'||a[i]=='E'||a[i]=='i'||a[i]=='I'||a[i]=='o'||a[i]=='O'||a[i]=='u'||a[i]=='U')
    {
    vowels++;
    string<<a[i]<<" ";
    }
  }
}
string<<"\n\nTotal number of vowels in string => "<<vowels;

string<<"\n\n\nConsonants in string are : \n\n";
for(i=0; i<strlen(a); i++)
{
  if(isalpha(a[i]))
  {
    if((a[i]!='a'&&a[i]!='A')&&(a[i]!='e'&&a[i]!='E')&&(a[i]!='i'&&a[i]!='I')&&(a[i]!='o'&&a[i]!='O')&&(a[i]!='u'&&a[i]!='U'))
    {
      consonants++;
      string<<a[i]<<" ";
    }
  }
}
string<<"\n\nTotal number of vowels in string => "<<consonants;


getch();
}



