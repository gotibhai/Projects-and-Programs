#include <iostream.h>
#include <fstream.h> 
#include <conio.h>
#include <stdlib.h>
class Student
{
      
      int adm_no;
      
      public:
      int roll_no;
       char name[50];
       char gender;
       void getroll_no()
       {
                   cout<<"Enter Roll No : ";
                   cin>>roll_no;
                   cout<<endl;
                   }
       void getadm_no()
       {
             cout<<"Enter Admission No : ";
             cin>>adm_no;
             cout<<endl;
             }
       void getname()
       {
            cout<<"Enter your Name : ";
            cin>>name;
            cout<<endl;
            }
       void getgender()
       {
            cout<<"Enter your Gender : ";
            cin>>gender;
            cout<<endl;
            }     
}stu1;

void modify()
{
     ifstream fin;
     ofstream fout;
     fin.open("Student1.Dat",ios::binary);
     fin.read((char*)&stu1,sizeof(stu1));
     system("cls");
     cout<<"What is the new Roll No ?\n";
     cin>>stu1.roll_no;
     fout.write((char*)&stu1,sizeof(stu1));
     cout<<"Modified record Successfully !\n\n";
     
     }   
     
int main()
{
    char res;
    ofstream fout;
    fout.open("Student1.Dat",ios::app|ios::binary);
    stu1.getroll_no();
    stu1.getadm_no();
    stu1.getname();
    stu1.getgender();
    fout.write((char*)&stu1,sizeof(stu1));
    cout<<"Written to File Successfully !\n\n";
    
    fout.close();
    
    cout<<"Do you want to Modify Roll No ?(Y/N)";
    cin>>res;
    if(res == 'y' || res == 'Y')
    {
           modify();
           }
    else
    {
        cout<<"Thank you for your time !\n\n";
        getch();
        exit(5);
        }
    
    
    
system("pause");
return 0;

}
    
