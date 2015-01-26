#include<fstream.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>
void main()
{
clrscr();

char a[80][80],choice;
int i=0,sum=0,words=0,avg;

cout<<"Enter the strings. Enter ## to terminate entering : ";

l1:
cin.getline(a[i],80);
if(a[i][0]=='#'&&a[i][1]=='#')
	goto l2;
else
	{
	   i++;
	   goto l1;
	}


l2:
fstream string;
string.open("str_z.txt", ios::out);
string<<"The strings are : \n\n";
for(int j=0; j<i; j++)
string<<a[j]<<"\n\n";


for(int k=0; k<i; k++)
{words=0;
 sum=0;
	{
	for(j=0; j<strlen(a[k]); j++)
		{
			if(a[k][j]==' ')
			 while(a[k][j]==' ')
				{
					j++;
				}

			if(isalnum(a[k][j]))
				{
					while(isalnum(a[k][j]))
						{
						  sum++;
						  j++;
						}
					words++;

				}

		}
	}
string<<"\n\nThe number of words in string \""<<a[k]<<"\" = "<<words;

string<<"\n\nThe Average word size = "<<sum/words;

}
string.close();

getch();
}