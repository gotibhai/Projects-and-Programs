//BBS- CLASS 12th FINAL PROJECT
#include<iostream.h>  // for standard input/output functions
#include <string.h>   // for strlen
#include <ctype.h>    // for isupper,islower,toupper,tolower
#include <conio.h>    // for clear screen , getch()
#include <iomanip.h>  // used to modify text
#include <fstream.h>  // for file-handling


int noofacc=1;
//Declaration of the Class Customer
class Customer
{
      private:
      //All the private variables 
      char fname[20];      //First Name
      char sname[100];     //Second Name
      char address[50];    //Address
      int  age;            //Age
      char password[10];   //Password set by the User
      char checkpass[10];  //A Temp Variable for Checking the password entered by the user
      float amount;        //Amount stored in the User's Bank Account
      
      public:
      char accname[100];   //A Special Account-Name Created for Each User
      void getfname()      //To print the first name of the User
      { cout<<fname; }     
      char getsname()      //To print the second name of the User
      { 
            cout<<sname;
            }
      void getamount()     //To print the balance in the User's account
      {
           cout<<"Your Balance :";
           cout<<amount;
           }
    /*
    THE FOLLOWING FUNCTIONS INPUT THE PRIVATE VARIABLES OF THE CLASS CUSTOMER !
    */       
      void addfname()      
      {     
           cout<<"First Name : ";
           cin>>fname; 
      }
      void addsname() 
      {     
           cout<<"Second Name : ";
           cin>>sname;
      }
           
      void addage() 
      { cout<<"Age : ";
        cin>>age; 
      }
        
      void addaddress()
      {    cout<<"Address : ";\
      cin.ignore();
           cin.getline(address,'#'); 
      }
      
      void addamount()
      {
           cout<<"Add balance to your Account :";
           cin>>amount;
           }
           
      //This Function Sets the Password for the User
      void setpassword()
      {
         cout<<endl<<endl<<"Size of Password (Maximum 10)"<<endl;
         cout<<endl<<"Use only Letters! No Numbers. No Special Characters"<<endl;
         cout<<"Enter your Password : ";
         for (int i=0;i <10;i++)
         {   
             int a;
             a=getch();
             if( a == '\r')
             {
                 cout<<endl<<endl;
                 cout<<"Password Set !";
                 break;
                 }
              else 
              {
                   password[i]=a;   
                 cout<<"*";  
                 } 
         }
      }
       /*
         THE FOLLOWING PIECE OF CODE IS VERY CONTROVERSIAL !  I NEED TO CREATE A FILE, HOWEVER IF I PLACE THIS INSIDE! 
         THIS FUNCTION DOES NOT RECOGNIZE --NEWCUS( THE OBJECT OF THIS CLASS)-- !
         IF I PLACE THIS OUTSIDE! IT DOES NOT RECOGNIZE "ACCNAME", THE SPECIALIZED ACCOUNT NAME CREATED FOR EACH USER!
         
         PLEASE HELP ME WITH THIS !
         
        void createfile()
      {
         ofstream bhuttle;
         bhuttle.open(accname,ios::binary|ios::out);
         bhuttle.write((char *)&Customer,sizeof(Customer));
         bhuttle.close();
      }
      */
      
      //This Function Creates a Specialized USER-NAME for Each User!
      //---NOTE: THIS IS PRINTING OUT SOME SMILEY IN PLACE OF THE "noofacc" - IDK WHY !THERE IS NO ISSUE WITH THE CODE----
      void accno()
      {
         int i,x,length=0,noofacc=1;
         while(sname[length] != '\0')
         {
                 length++;
                 } 

         for(i=0;i<=length;i++)
         {
             accname[i]=sname[i];
             }        
                                  
         accname[length+1]=noofacc;
         accname[length+2]='.';
         accname[length+3]='d';
         accname[length+4]='a'; 
         accname[length+5]='t'; 
         noofacc++;
         cout<<"Your Account Name is : ";
          for(i=0;i<length+6;i++)
         {
             cout<<accname[i];
             }    
       cin>>x;
      }
      //THIS IS A FUNCTION FOR UPDATING THE USER'S ACCOUNT. THIS CHECKS THE PASSWORD, BEFORE GIVING HIM ACCESS>
      //HOWEVER AS THE FILE IS NOT BEING MADE NOW. -- THIS IS USELESS FOR NOW!
      int checkpassf()
      {
          int retfromstr;
          
          for (int i=0;i <10;i++)
         { 
             int a;
             a=getch();
             if( a == '\r')
             {
                 cout<<endl<<endl;
                 retfromstr = strcmp(password,checkpass);
                 break;
                 }
             else if (i<10)
             {
                  checkpass[i]=a;   
                 cout<<"*";  
                 }
                 else if (i==10)
                 {
                      int input;
                      cout<<"You do not have an Account in this Bank!"<<endl<<endl;
                      
                 }
         } 
           return retfromstr;
      }
      //THIS IS THE MAIN FUNCTION FOR CREATING AN ACCOUNT! IT CALLS OTHER PRIMARY FUNCTIONS!
      void addaccount()
      {
           system("CLS");
           cout<<setw(45)<<"WELCOME TO BBS"<<endl;
           cout<<"--------------------------------------------------------------------------------";
           addfname();
           addsname();
           addage();
           addaddress();
           addamount();
           setpassword();     
           accno(); 
           displaymenu();
      }
      //THIS FUNCTION IS USED TO UPDATE A USER"S ACCOUNT- USELESS FOR NOW AS THE FILE IS NOT BEING MADE
      void updateaccount()
      { 
           system("CLS");\
           cout<<setw(45)<<"WELCOME TO BBS"<<endl;
           cout<<"--------------------------------------------------------------------------------";cout<<"You Have Chosen To Update Your Account Details :- ";
           cout<<endl<<endl<<"Please Enter Your Password :";
           if(checkpassf() == 0)
           {
                    cout<<"Welcome ";
                    getfname();
           }
      }
    
    //THIS IS A FUNCTION WHICH DISPLAYS THE MENU SCREEN
    void displaymenu()
    {
    system("CLS"); 
    int var,i;
    cout<<setw(50)<<"BBS- Bhuttle Banking Service"<<endl;
    cout<<"--------------------------------------------------------------------------------";
    cout<<endl;
    cout<<endl;
    cout<<setw(10)<<"1.ADD NEW ACCOUNT"<<endl<<"2.UPDATE DETAILS"<<endl<<"3.DELETE ACCOUNT"<<endl;
    cin>>var;
    switch(var)
    {
               case 1:{
                        addaccount();
                        Customer newcus;
                        ofstream bhuttle;
                        bhuttle.open(accname,ios::binary|ios::out);
                        bhuttle.write((char *)&newcus,sizeof(newcus));
                        bhuttle.close();
                     
                     break;
                     }
               case 2:{ 
                         updateaccount();
                       break;
                       }
               case 3:{ 
                      //deleteaccount();
                      break;
                      }
               default : "Please enter a number according to the choices ";
                 break;
    }
    cin>>i;
}
              
};


int main()
{
  //CREATING AN OBJECT OF THE CLASS--CUSTOMER
  Customer newcus;
  // CALLING THE DISPLAY MENU FUNCTION
  newcus.displaymenu();
     
      
return 0;
system("pause");

}
