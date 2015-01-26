#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
const int LEN=25;
class employee{ char name[LEN];
		unsigned long enumb;
		public:
		void getdata()
			{ cout<<"Enter the name : ";
			  cin.get();cin.getline(name,LEN);
			  cout<<"\n\nEnter the employee number :";
			  cin>>enumb;
			}
		employee()
		{delay(1000);cout<<"\n\nCalling Constructor of base class .";}
		~employee()
		{ delay(1000);cout<<"\n\nDeallocating the object of base class.";getch();}
		void putdata()
			{	cout<<"\n\nName : "<<name;
				cout<<"\n\nEmployee number : "<<enumb;
				cout<<"\n\nBasic salary : "<<basic;
			}
		protected:
		float basic;
		void getbasic()
			{cout<<"\n\nEnter basic : "; cin>>basic;
			}
		};

class manager : public employee { char title[LEN];
				 public:
				 void getdata()
					{ employee::getdata();
					  getbasic();
					  cout<<"\n\nEnter title : ";
					  cin.get();cin.getline(title,80);
					}
				 manager()
				 {delay(1000);cout<<"\n\nCalling constructor in derived class";
				 }

				 ~manager()
				 { delay(1000);cout<<"\n\nDeallocating the object of derived class."; }
				 void putdata ()
					{ employee::putdata();
					  cout<<"\n\nTitle : "<<title;
					}
				 };
void main()
{ clrscr();
manager m1,m2;
cout<<"\n\nManager 1 : \n"; m1.getdata();
cout<<"\n\nManager 2 : \n"; m2.getdata();
cout<<"\n\n\n\nManager 1 Details :\n"; m1.putdata();
cout<<"\n\n\n\nManager 2 Details :\n"; m2.putdata();
getch();

}





