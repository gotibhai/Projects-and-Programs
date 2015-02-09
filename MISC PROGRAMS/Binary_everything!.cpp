#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <string.h>
#include <stdlib.h>

class student{
	int rn;
	char name[50];
public:
	void getdata(){
		cout<<"\nWrite data: "<<endl;
		cout<<"Enter roll number: ";
		cin>>rn;
		cout<<"Enter name: ";
		cin>>name;
	}
	void showdata(){
	cout<<rn<<"\t"<<name<<endl;
	}
	int getrn()
    {return rn;}
	void write();
	void modify(int n);
	void modify(int n,int k);
	void delete_rec(int n);
	
}object;


void student::write()
{
     student obj1;
     obj1.getdata();
     ofstream fout;
     fout.open("Students.dat",ios::app|ios::out|ios::binary);
     fout.write((char*)&obj1, sizeof(obj1));
     fout.close();
     }

void student :: modify(int n)
{
     student obj2;
     fstream fio;
     fio.open("Students.dat",ios::app|ios::in|ios::out|ios::binary);
     cout<<"ji";
          getch();
     while(fio.read((char*)&obj2,sizeof(obj2)))
     {
          //int p = fio.tellg();
          //fio.read((char*)&obj2,sizeof(obj2));
          if(obj2.getrn() == n)
          {
                   cout<<"Modify : \n\n";
                   obj2.getdata();
                   fio.seekp(-1*sizeof(obj2),ios::cur);
                   fio.write((char*)&obj2,sizeof(obj2));
              }
     }
     fio.close();
     
}

void student::modify(int n, int x)
{
     student obj3;
     ifstream fin;
     ofstream fout;
     fin.open("Students.dat",ios::in|ios::binary);
     fout.open("temp.dat",ios::app|ios::in|ios::binary);
     while( fin )
     {
            fin.read((char*)&obj3,sizeof(obj3));
            if(getrn() == n)
            {
                   obj3.getdata();
                   }
            fout.write((char*)&obj3,sizeof(obj3));
        }
     fin.close();
     fout.close();
     remove("Students.dat");
     rename("temp.dat","Students.dat");
               
}
     
     
void student :: delete_rec(int n)
{
     student obj4;
     ifstream fin;
     ofstream fout;
     fin.open("Students.dat",ios::in|ios::binary);
     fout.open("temp.dat",ios::app|ios::in|ios::binary);
       while( fin )
     {
            fin.read((char*)&obj4,sizeof(obj4));
            if(getrn() == n)
            {
                   //obj2.getdata();
                   }
            else
            {
            fout.write((char*)&obj4,sizeof(obj4));
            }
        }
     fin.close();
     fout.close();
     remove("Students.dat");
     rename("temp.dat","Students.dat"); 
     }
     
int main()
{  
    system("CLS");
    int option;
    do
    {
         system("CLS");
         cout<<"WELCOME,\n\n";
	cout<<"1.Add\n2.Modify\n3.Delete\n4.Exit"<<endl;
	cout<<"Your choice : ";
	cin>>option;
	switch(option){
		case 1: {
                 object.write(); 
                 break; }
		case 2: {
                 object.modify(1); 
                 break;}
		case 3: {
                 object.delete_rec(10); 
                 break; }
		case 4: {
                  getch(); 
                  exit(4); }
		default: {
                   cout<<"Enter Correct Option !\n\n";
                    break; }
		 
       }
    } 
    
  while (option != 4);
  {      getch();
         exit(4);
         }
         
  return 0;
  system("Pause");
       
}
               
     
     
                   
                   
                   
                   
        
        
     
