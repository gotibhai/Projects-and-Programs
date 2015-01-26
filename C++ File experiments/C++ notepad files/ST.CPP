#include<iostream.h>
#include<stdio.h>
#include<conio.h>

class person{ char name[21];
	      int age;
	      public:
	      void indata()
	      {cout<<"\n\nEnter the name:" ;
	       gets(name);
	       cout<<"\n\nEnter the age\n\n";
	       cin>>age;
	      }
	      void outdata()
	      {     cout<<"\n\nName is:\n\n"<<name;
		    cout<<"\n\nAge is:"<<age;

	      }
	};
class student: public person
  { float Tmarks;
    int rollno;
    public:
    char calgrade()
    {if(Tmarks>90)
     return 'A';
     else if(Tmarks>80&&Tmarks<=90)
     return 'B';
     else if(Tmarks>70&&Tmarks<=80)
     return 'C';
     else if(Tmarks>60&&Tmarks<=70)
     return 'D';
     else
     return 'E';
    }
    void enter()
    {     cout<<"\n\nEnter the roll number: "; cin>>rollno;
    cout<<"\n\nEnter total marks";
    cin>>Tmarks;

    }
    void display()
    { cout<<"\n\nRoll number : "<<rollno;
     cout<<"\n\nTotal marks are : "<<Tmarks;
      cout<<"\n\nGrade = :"<<calgrade();
    }
};

void main()
{ clrscr();
student A;
A.indata();
 A.enter();
 A.outdata();
 A.display();
 getch();
 }

