//BBS- CLASS 12th FINAL PROJECT
#include<iostream.h>  // for standard input/output functions
#include <string.h>   // for strlen
#include <ctype.h>    // for isupper,islower,toupper,tolower
#include <conio.h>    // for clear screen , getch()
#include <iomanip>  // used to modify text
#include <fstream.h>  // for file-handling
#include <Windows.h>  //for using the sleep function


int noofacc=101;
//Declaration of the Class Customer
class Customer
{
      private:
      //All the private variables 
      char password[15];   //Password set by the User
	  char fname[20];      //First Name
      char sname[20];       //Second Name
      char address[200];    //Address
      char gender;
      int  age;            //Age
      char checkpassword[10];  //A Temp Variable for Checking the password entered by the user
      long double amount;        //Amount stored in the User's Bank Account
      
      public:
      char accname[100];     //sname + your no of user
      char checkusername[100];  //for updating the details of your account
	  char filename[100];   //A Special Account-Name Created for Each User
	   char checkfilename[100];
      void getfname()      //To print the first name of the User
      {  
	    cout<<fname; 
		}     
      void getsname()      //To print the second name of the User
      { 
        cout<<sname;
        }
        
      void getamount()     //To print the balance in the User's account and a quirky message;
      {
        cout<<"Your Balance :";
        cout<<amount;
        if(amount >= 100000)
         {             
            cout<<endl;          
            cout<<"You're a star. People could use some help from you! "<<endl;;
            cout<<endl;
        }
        else if(amount >= 50000 && amount < 100000) 
        {            
            cout<<endl;          
            cout<<"Great Going! Soon enough you'll have enough to buy a ferrai! "<<endl;;
            cout<<endl;
        }
        else 
        {            
            cout<<endl;          
            cout<<"A Beginners guide to saving money : A great read! Only $2.99 on Amazon!  "<<endl;;
            cout<<endl;
        }
      }
      void getamount( int t)
      {
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
      void addgender()
      {
           cout<<"SEX(M/F) : ";
           cin>>gender;
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
                 cout<<" Password Noted! ";
                 cout<<endl;
                 break;
                 }
              else 
              {
                   password[i]=a;   
                 cout<<"*";  
                 } 
         }
      }
      
      
      //This Function Creates a Specialized USER-NAME for Each User!
      //I HAVE MODIFIED THIS FUNCTION. WITH YOUR CODE, PEOPLE WITH SAME USERNAME COULDNT HAVE BEEN RECOGNIZED.
      // SO I ADDED A NUMBER AT THE END OF IT. (THIS NUMBER IS THE NO OF THE ACCOUNT CREATED STARTING FROM 101
      //THE PROBLEM IS ONCE THE PROGRAM EXITS IT AGAIN STARTS WITH 101 ...!
      //--- PROBLEM---
      void accno()  
      {
         
         char noofacc_string[32];
         strcpy(accname,sname);
		 sprintf(noofacc_string, "%d",::noofacc);
	     
		 strcat(accname,noofacc_string);    
                             
         cout<<" Your Account Name is : ";
		 cout<<accname;
		 
         strcpy(filename,strcat(accname,".dat"));
         
		 cout<<endl;
         cout<<endl;
		 cout<<endl;
		 
		 noofacc++;
         cout<<"\n\nPress any key to continue !";
         char x1;
         cin>>x1;
      }
       
     void keep_number()
     {
          ofstream fout;
          fout.open("Number_of_Accounts.txt");
          fout<<noofacc;
          }
          
     void read_number()
     {
          ifstream fin;
          fin.open("Number_of_Accounts.txt");
          fin>>noofacc;
          }

      //THIS IS THE MAIN FUNCTION FOR CREATING AN ACCOUNT! IT CALLS OTHER PRIMARY FUNCTIONS!
      void addaccount()
      {
           system("CLS");
           read_number();
           cout<<std::setw(45)<<"WELCOME TO BBS"<<endl;
           cout<<"--------------------------------------------------------------------------------";
           addfname();
           addsname();
           addage();
           addgender();
           addaddress();
           addamount();
           setpassword();     
           accno(); 
           keep_number();
      }
      
      void updateaccount()
      { 
        Customer newcus;
        fstream bhuttle;
        newcus.displaymenu_for_entering_myaccount();
        cin>>newcus.checkusername;
        strcpy(newcus.checkfilename,strcat(newcus.checkusername,".dat"));
		bhuttle.open(newcus.checkfilename,ios::binary|ios::in);

        if (!bhuttle.is_open())
        {
		   perror("Error while opening file ");
		   cout<<endl;
		   cout<<endl;
           cout<<"Please check the username you have entered!";
           cout<<"\n\nPress any key to continue !";
           char x1;
           cin>>x1;
           newcus.updateaccount();
        }
        bhuttle.read((char *)&newcus,sizeof(newcus));
        cout<<endl<<endl<<" Please Enter Your Password : ";
         cin>>newcus.checkpassword;
       
          if (strcmp(newcus.password,newcus.checkpassword) != 0)
           {
           char input;
				cout<<" You currently do not have an account in this Bank.";
				cout<<endl;
				cout<<endl;
				cout<<" Do you want to become a part of the Bhuttle Banking Service ? (Y/N)";
				cin>>input;
				if(input=='Y'||input=='y')
				newcus.addaccount();
            }
           else
               newcus.displaymenu_for_myaccount();
      }

     void waiting(long double amt)
     {
          cout<<endl;
          cout<<endl;
          cout<<endl;
          int cursor=0,wait=0,no_of_cycles,cycles=0;
          if(amt>=50000)
          no_of_cycles=5;
          else if(amt>=10000 && amt<=50000)
          no_of_cycles=4;
          else
          no_of_cycles=3;
          for(cursor=0;cursor<no_of_cycles;cursor++)
             {
                   cout<<".";
                   Sleep(0700);
  
              }    
                 cout<<endl;                   
     } 

     void addbalance()
     {
       system("CLS"); 
       long double amount_added;
       cout<<std::setw(45)<<"BBS- Bhuttle Banking Service (BETA VERSION)"<<endl;
       cout<<"--------------------------------------------------------------------------------";
       welcome_statement();
       getamount();
       cout<<endl;
       cout<<" AMOUNT TO BE ADDED: ";
       cin>>amount_added;
       waiting(amount_added);
       cout<<endl;
       cout<<endl;
       amount=amount+amount_added;
       cout<<" TRANSACTION SUCCESSFULL ! ";
       cout<<endl;
       cout<<endl;
       cout<<" YOUR CURRENT BALANCE IS : ";
       getamount(5);

          }
          
     void removebalance()
     {
       system("CLS");
       long double amount_withdraw;
       cout<<std::setw(45)<<"BBS- Bhuttle Banking Service (BETA VERSION)"<<endl;
       cout<<"--------------------------------------------------------------------------------";
       welcome_statement();
       getamount();
       cout<<endl;
       cout<<" AMOUNT TO BE WITHDRAWN: ";
       cin>>amount_withdraw;
       waiting(amount_withdraw);
       cout<<endl;
       cout<<endl;
       amount=amount-amount_withdraw;
       cout<<" TRANSACTION SUCCESSFULL ! ";
       cout<<endl;
       cout<<endl;
       cout<<" YOUR CURRENT BALANCE IS : ";
       getamount(5);
        }
        
     void transfermoney()
     {
       system("CLS"); 
       long double amount_transfer;
       char accno_tranfermoney[100],file_accno_tranfermoney[100];
       cout<<std::setw(65)<<"BBS- Bhuttle Banking Service (BETA VERSION)"<<endl;
       cout<<"--------------------------------------------------------------------------------";
       welcome_statement();
       cout<<endl;
       cout<<" AMOUNT TO BE TRANSFERRED: ";
       cin>>amount_transfer;
       x:;
       cout<<" TO ACCOUNT (ONLY INTERNAL TRANSFERS POSSIBLE): ";
       cin>>accno_transfermoney;
       fstream bhuttle;
       strcpy(file_accno_tranfermoney,strcat(accno_tranfermoney,".dat"));
       bhuttle.open(file_accno_tranfermoney,ios::binary|ios::out);

        if (!bhuttle.is_open())
        {
		   perror("Error while opening file ");
		   cout<<endl;
		   cout<<endl;
           cout<<"Please check the username you have entered!";
           cout<<"\n\nPress any key to continue !";
           char x1;
           cin>>x1;
           goto x;
        }
       waiting(amount_transfer);
       cout<<endl;
       cout<<endl;
       
       cout<<" TRANSACTION SUCCESSFULL ! ";
       cout<<endl;
       cout<<endl;
       cout<<" YOUR CURRENT BALANCE IS : ";
       getamount(5);
       
       
          }
     void updatedetails()
     {
       system("CLS"); 
       cout<<std::setw(65)<<"BBS- Bhuttle Banking Service (BETA VERSION)"<<endl;
       cout<<"--------------------------------------------------------------------------------";
       welcome_statement();
       cout<<std::setw(10)<<"1.CHANGE FIRST-NAME"<<endl<<"2.CHANGE SECOND-NAME"<<endl<<"3.CHANGE AGE"<<endl<<"4.CHANGE ADDRESS"<<endl;
       cin>>var;
       switch(var)
       {
               case 1:{
                       
                          break;
                     }
               case 2:{  
                         
                       break;
                       }
               case 3:{ 
                      
                      break;
                      }
              case 4:{ 
                      
                      break;
                      }
               default : "Please enter a number according to the choices ";
                 break;
    }
       
          }
      

     void deleteaccount()
     {
           welcome_heading(5);
           cout<<endl;
           cout<<endl;
           cout<<endl;
           cout<<std::setw(45)<<"Dear Mr ";
           getfname()<<" ,";
           cout<<endl;
           cout<<"Bhuttle Banking Service shall miss you !" <<endl;
           cout<<std::setw(45)<<"____________________________________"<<endl;
           cout<<endl;
           cout<<endl;
           cout<<endl;
           cout<<endl;
           cout<<std::setw(45)<<"ACCOUNT WITH USERNAME : "<<accname<<" DELETED !" <<endl;
           cout<<std::setw(45)<<"______________________________________________________"<<endl;
           

          }
    //THIS IS A FUNCTION WHICH DISPLAYS THE MENU SCREEN WHEN USER OPTS TO MODIFY DATA. THIS VALIDATES IF THE USER HAS A ACCOUNT 
    void displaymenu_for_entering_myaccount()
    {
    	   welcome_heading(3,5);
           cout<<"You Have Chosen To Update Your Account Details :- ";
           cout<<endl<<endl<<"Please Enter Your UserName : ";
           cout<<endl;
           cout<<endl;
           cout<<"NOTE: PLEASE ENTER THE USERNAME EXACTLY AS GIVEN TO YOU AT THE TIME OF          REGISTRATION!!";
           cout<<endl;
     
	}
	
	void welcome_statement()
	{
    Customer newcus;
    cout<<endl;
    cout<<endl;
    cout<<"WELCOME ";
    if(strcmp(gender,"M"))
    cout<<" Mr ";
    else 
    cout<<"Mrs ";
    getfname();
    cout<<" ";
    getsname();
    cout<<" ,";
    cout<<endl;
    cout<<endl;
    
     }
     
     void welcome_heading(int t)
     {
          system("CLS"); 
          cout<<std::setw(50)<<"BBS- Bhuttle Banking Service"<<endl;
          cout<<"--------------------------------------------------------------------------------";
          }
     
     void welcome_heading(int t, int p)
     {
          system("CLS"); 
           cout<<std::setw(45)<<"WELCOME TO BBS"<<endl;
           cout<<"--------------------------------------------------------------------------------";
          }
	
	//I'm not reaching here but if user passes the checks. This menu will be displayed
	//I shall edit these values using seekp and seekg once this point is reached!
	void displaymenu_for_myaccount()     
    {
    system("CLS"); 
    int var,i;
    cout<<std::setw(50)<<"BBS- Bhuttle Banking Service"<<endl;
    cout<<"--------------------------------------------------------------------------------";
    welcome_statement();
    cout<<std::setw(10)<<"1.ADD BALANCE"<<endl<<"2.REMOVE BALANCE"<<endl<<"3.TRANSFER MONEY"<<endl<<"4.UPDATE ACCOUNT DETAILS"<<endl;
    cin>>var;
    switch(var)
    {
               case 1:{
                         Customer newcus;
                         newcus.addbalance();
                       
                    
                     break;
                     }
               case 2:{  
                         Customer newcus;
                         newcus.removebalance();
                         
                       break;
                       }
               case 3:{ 
                         Customer newcus;
                         newcus.transfermoney();
                      
                      break;
                      }
              case 4:{ 
                         Customer newcus;
                         newcus.updatedetails();
                      
                      break;
                      }
               default : "Please enter a number according to the choices ";
                 break;
    }
    cin>>i;
}
              	
    //THIS IS A FUNCTION WHICH DISPLAYS THE MENU SCREEN
    void displaymenu()
    {
    system("CLS"); 
    int var,i;
    cout<<std::setw(65)<<"BBS- Bhuttle Banking Service (BETA VERSION)"<<endl;
    cout<<"--------------------------------------------------------------------------------";
    cout<<endl;
    cout<<endl;
    cout<<std::setw(10)<<"1.ADD NEW ACCOUNT"<<endl<<"2.GO TO MY ACCOUNT"<<endl<<"3.CLOSE ACCOUNT"<<endl;
    cin>>var;
    switch(var)
    {
               case 1:{
                    
                        Customer newcus;
                        fstream bhuttle;
                        newcus.addaccount();
		                                      
                        bhuttle.open(newcus.filename,ios::binary|ios::out);
                        bhuttle.write((char *)&newcus,sizeof(newcus));
                        bhuttle.close();
                        displaymenu();
                     
                     break;
                     }
               case 2:{ 
                         Customer newcus;
                         fstream bhuttle;
                         newcus.updateaccount();
                         
                       break;
                       }
               case 3:{ 
                      Customer newcus;
                      newcus.deleteaccount();
                      break;
                      }
               default : "Please enter a number according to the choices ";
                 break;
    }
    cin>>i;
}
              
}; //CLASS DECLARATION END

int main()
{
  int idk;
  //CREATING AN OBJECT OF THE CLASS--CUSTOMER
  Customer newcus;
  // CALLING THE DISPLAY MENU FUNCTION
  newcus.displaymenu();
     
cin>>idk;
return 0;


}
