//Program Using Inheritance of classes
#include<iostream.h>
#include<stdio.h>
#include<conio.h>

class person{ char name[21];
int age;
public:
	 void indata()
	 {cout<<"\n\nEnter the name of Student: " ;
	  gets(name);
	  cout<<"\n\nEnter the age : ";
	  cin>>age;
	  }
	 void outdata();
};

void person::outdata()
 {
 cout<<"\n\n";
for(int i=0; i<79; i++)
cout<<"-";
cout<<"\n\nName of the student is: "<<name;
 cout<<"\n\nAge of the student is : "<<age;
 }

 class game {
	     char game_name[20];
	     public:
	     void input()
	     {
 cout<<"\n\nEnter the game name : ";
              cin.get();cin.getline(game_name,20);
	     }
	     void output()
	     {
              cout<<"\n\nGame opted by the student is : "<<game_name;
	     }
};

class student: public person, public game
  { 
      float Tmarks;
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
    {
    indata(); 

    cout<<"\n\nEnter the roll number: "; cin>>rollno;

    input();
    cout<<"\n\nEnter total marks (out of 100) : ";
    cin>>Tmarks;

    }
    void display()
    {
     outdata();
     cout<<"\n\nRoll number : "<<rollno;
     output();
     cout<<"\n\nTotal marks are : "<<Tmarks;
     cout<<"\n\nGrade = "<<calgrade();
    }
};

int main()
{ 
system("CLS");
student A;
 A.enter();
cout<<"\n\nStudent details are : \n\n";
 A.display();
getch();
}



