//BBZ- CLASS 12th FINAL PROJECT
#include<iostream.h>  // for standard input/output functions
#include <string.h>   // for strlen
#include <ctype.h>    // for isupper,islower,toupper,tolower
#include <conio.h>    // for clear screen , getch()
#include <iomanip>  // used to modify text
#include <fstream.h>  // for file-handling
#include <Windows.h>  //for using the sleep function

//Global variable to keep count of the no of accounts
int noofacc=101;
//Declaration of the Class Customer
class Customer
{
      private:
      //All the private variables 
	  char fname[20];      //First Name
      char sname[20];       //Second Name
      char address[200];    //Address
      char gender;          //gender of the user
      int  age;            //Age
      long double amount;        //Amount stored in the User's Bank Account
      
      public:
      char checkpassword[10];  //A Temp Variable for Checking the password entered by the user
      char password[15];   //Password set by the User
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
        cout<<endl;
        cout<<endl;
        cout<<"YOUR BALANCE :";
        cout<<amount;
        cout<<endl;
        cout<<endl;
        if(amount >= 100000)
         {             
            cout<<endl;        
            cout<<std::setw(25)<<"\"You're a star. People could use some help from you!\"-BBZ "<<endl;;
            cout<<endl;
        }
        else if(amount >= 50000 && amount < 100000) 
        {            
            cout<<endl;          
            cout<<std::setw(25)<<"\"Great Going! Soon enough you'll have enough to buy a ferrai!\"-BBZ   "<<endl;;
            cout<<endl;
        }
        else 
        {            
            cout<<endl;        
            cout<<std::setw(25)<<"\"A Beginners guide to saving money : A great read! Only $2.99 on Amazon!\"-BBZ  "<<endl;;
            cout<<endl;
        }
      }                           
      void setamount(long double x)   //This function sets the amount to the argument passed
      {
           amount=x;
      }
      
      void getamount( int t)          // An overloaded function just to print the Balance of the user.
      {
           cout<<amount;
           cout<<endl; 
           }
      long double retamount()         // returns the value of amount
      {
           return amount;
           }
    /*
    THE FOLLOWING FUNCTIONS INPUT THE PRIVATE VARIABLES OF THE CLASS CUSTOMER !
    */       
      void addfname()                // This is functions sets the First Name of the user by taking user-input
      {     
           cout<<"FIRST NAME : ";
           cin>>fname; 
           cout<<endl;
      }
      void addsname()               // This is functions sets the Second Name of the user by taking user-input
      {     
           cout<<"SECOND NAME : ";
           cin>>sname;
           cout<<endl;
      }
           
      void addage()                 // This is functions sets the Age of the user by taking user-input
      { 
           age1:
           cout<<"AGE : ";
           cin>>age;
           if(age < 18 || age > 90)
           {
                  cout<<endl;
                  cout<<"Please Enter your Correct Age!"<<endl<<endl;;
                  if(age<18)
                  cout<<"Minors shall not be permitted access!"<<endl<<endl;
                  else
                  cout<<"Senior Citizens shall not be permitted access!"<<endl<<endl;;
                  
                  goto age1;
                  }
           cout<<endl;
      }
        
      void addaddress()            // This is functions sets the Address of the user by taking user-input
      {    
           cout<<"YOUR ADDRESS : ";
           cin.ignore();
           cin.getline(address,'#'); 
           cout<<endl;
      }
      void addamount()             // This is functions sets the Balance of the user by taking user-input
      {
           cout<<"ADD BALANCE : ";
           cin>>amount;
           cout<<endl;
      }
      void addgender()             // This is functions sets the Gender of the user by taking user-input
      {
           c:
           cout<<"SEX(M/F) : ";
           cin>>gender;
           cout<<endl;
           if(gender != 'M' && gender != 'F' && gender != 'm' && gender != 'f')
           {
                     cout<<endl;
                     cout<<"Please use only M/F! "<<endl<<endl;;
                     cout<<endl;
                     goto c;
           }
      }
      
      void setpassword();          //This Function Sets the Password for the User
      
      void accno()                 //This Function Creates a Specialized USER-NAME for Each User!
      {
         
         char noofacc_string[32];
         strcpy(accname,sname);
		 sprintf(noofacc_string, "%d",::noofacc);
	     
		 strcat(accname,noofacc_string);    
                             
         cout<<std::setw(30)<<" YOUR ACCOUNT NAME IS : ";
		 cout<<accname;
		 
         strcpy(filename,strcat(accname,".dat"));
         strcpy(checkfilename,accname);
         
		 cout<<endl;
         cout<<endl;
		 cout<<endl;
		 
		 noofacc++;
         cout<<"\n\nPress any key to continue !";
         char x1;
         x1=getch();
      }
      
     void keep_number()          //This keeps a track of the number of accounts in the bank!
     {
          ofstream fout;
          fout.open("Number_of_Accounts.txt");
          fout<<noofacc;
          }
      
     void read_number()          //This keeps a track of the number of accounts in the bank!    
     {
          ifstream fin;
          fin.open("Number_of_Accounts.txt");
          fin>>noofacc;
          }
     
     void welcome_heading(int t)     //Overloading of functions to output different types of welcome messages
     {
          system("CLS"); 
          cout<<std::setw(63)<<"BBS- Bhuttle Banking Service(BETA VERSION)"<<endl;
          cout<<"--------------------------------------------------------------------------------";
          }
     void welcome_heading(int t, int p)
     {
          system("CLS"); 
           cout<<std::setw(45)<<"WELCOME TO BBS"<<endl;
           cout<<"--------------------------------------------------------------------------------";
          }

      
      void addaccount()           //THIS IS THE MAIN FUNCTION FOR CREATING AN ACCOUNT! IT CALLS OTHER PRIMARY FUNCTIONS!
      {
          
           read_number();                       //This keeps a track of the number of accounts in the bank!
           welcome_heading(2,3);                // This gives the introductory page of the Bank!
           addfname();                          // Accepts the First Name
           addsname();                          // Accepts the Second Name
           addage();                            // Accepts the Age 
           addgender();                         // Accepts the gender 
           addaddress();                        // Accepts their address
           addamount();                         // Accepts the Balance
           setpassword();                       // Sets the password for the user
           accno();   
                                                 // Creates a unique account name for the user
           keep_number();                       //This keeps a track of the number of accounts in the bank!
      }

     
     void waiting(long double amt)    //Function for a Loading animation
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
          
          cout<<"Transaction in Progress";
          
          for(cursor=0;cursor<no_of_cycles;cursor++)
             {
                   cout<<".";
                   Sleep(0700);
  
              }    
                 cout<<endl;                   
     } 
     
    
     void closeaccount()    //Function call to delete the users account!
     {
           welcome_heading(5);
           cout<<endl;
           cout<<endl;
           cout<<"ENTER YOUR USERNAME : ";
           cin>>checkusername;
           strcpy(checkfilename,strcat(checkusername,".dat"));
           
            cout<<endl;
            cout<<endl;
            
           cout<<"DEAR MR/MRS ";
           cout<<sname<<endl;
           cout<<"BHUTTLE BANKING SERVICE SHALL MISS YOU !"<<endl;
           if( remove(checkfilename) != 0 )
           {
               cout<<endl;
               cout<<endl;
           perror("ERROR DELETING FILE !" );
           }
           else
           puts("ACCOUNT DELETED !");
           
           cout<<endl;
           displaymenu();
          }
          
    void displaymenu_for_entering_myaccount()           //THIS IS A FUNCTION WHICH DISPLAYS THE MENU SCREEN WHEN USER OPTS TO MODIFY DATA. THIS VALIDATES IF THE USER HAS A ACCOUNT 
    {
    	   welcome_heading(3,5);
           cout<<"You Have Chosen To Update Your Account Details :- ";
           cout<<endl;
           cout<<endl;
           cout<<"NOTE: PLEASE ENTER THE USERNAME EXACTLY AS GIVEN TO YOU AT THE TIME OF          REGISTRATION!!";
           cout<<endl;
           cout<<endl;
           cout<<"PLEASE ENTER YOUR USERNAME : ";     
	}
	
	void welcome_statement()        //FUNCTION TO DISPLAY THE WELCOME MESSAGE FOR USERS WITH THEIR NAMES USING FUNCTION OVERLOADING!
	{
    cout<<endl;
    cout<<endl;
    cout<<"WELCOME ";
    if(gender == 'M' || gender == 'm')
    cout<<"MR ";
    else 
    cout<<"MRS ";
    fname[20];
    cout<<fname;
    cout<<" ";
    sname[20];
    cout<<sname;
    cout<<",";
    cout<<endl;    
     }
     
    void welcome_statement(int t)
	{
    cout<<endl;
    if(gender == 'M' || gender == 'm')
    cout<<"MR ";
    else 
    cout<<"MRS ";
    
    fname[20];
    cout<<fname;
    cout<<" ";
    sname[20];
    cout<<sname;
    cout<<",";
    cout<<endl;    
     }	

	void displaymenu_for_myaccount();    //A FUNCTION TO DISPLAY MENU FOR MY ACCOUNT
    
    void displaymenu();                	 //THIS IS A FUNCTION WHICH DISPLAYS THE MENU SCREEN
           
}newcus; //CLASS DECLARATION END




void addbalance()            //Function for adding balance to the users account!
     {
       long double amount_added,amt;
       newcus.welcome_heading(5);
       newcus.welcome_statement();
       newcus.getamount();
       cout<<endl;
       cout<<"AMOUNT TO BE ADDED: ";
       cin>>amount_added;
       newcus.waiting(amount_added);
       cout<<endl;
       cout<<endl;
       fstream bhuttle1;
       bhuttle1.open("Temp.dat",ios::binary|ios::out);
        if (!bhuttle1.is_open())
        {
		   perror("Error while opening file ");
		   cout<<endl;
		   cout<<endl;
           cout<<"Please check the username you have entered!";
           cout<<"\n\nPress any key to continue !";
           getch();
           addbalance();
        }
        
       amt=newcus.retamount();
       amt=amt+amount_added;
       newcus.setamount(amt);
       
       bhuttle1.write((char *)&newcus,sizeof(newcus));
       bhuttle1.close();
       if( remove(newcus.checkfilename) != 0 )
       perror("Error deleting file");
       
       int result = rename("Temp.dat",newcus.checkfilename);
       if ( result != 0 )
       perror( "Error renaming file" );
       
       cout<<" TRANSACTION SUCCESSFULL ! ";
       cout<<endl;
       cout<<endl;
       cout<<" YOUR CURRENT BALANCE IS : ";
       newcus.getamount(7);
       cout<<"\n\nPress any key to continue !";
       getch();
          
       }
       
 
     void removebalance()            //Function to remove balance from the users account!     
     {
       long double amount_withdraw,amt;
       newcus.welcome_heading(5);
       newcus.welcome_statement();
       newcus.getamount();
       b:
       cout<<endl;
       cout<<"AMOUNT TO BE WITHDRAWN: ";
       cin>>amount_withdraw;
       amt=newcus.retamount();
       if(amt == 0)
       {
              cout<<endl;
              cout<<"SIR, YOU HAVE 0 BALANCE.!"<<endl;
              cout<<endl;
              cout<<"PLEASE ADD BALANCE FIRST ";
              cout<<"\n\nPress any key to continue !";
              getch();
       }
              
              
       if(amount_withdraw > amt)
       {
                    cout<<endl;
                    cout<<"THAT IS MORE THAN WHAT YOU HAVE, SIR!"<<endl;
                    goto b; 
                          }
       
       newcus.waiting(amount_withdraw);
       cout<<endl;
       cout<<endl;
       fstream bhuttle1;
       bhuttle1.open("Temp.dat",ios::binary|ios::out);
        if (!bhuttle1.is_open())
        {
		   perror("Error while opening file ");
		   cout<<endl;
		   cout<<endl;
           cout<<"Please check the username you have entered!";
           cout<<"\n\nPress any key to continue !";
           getch();
           addbalance();
        }
        
       amt=amt-amount_withdraw;
       newcus.setamount(amt);
       
       bhuttle1.write((char *)&newcus,sizeof(newcus));
       bhuttle1.close();
       if( remove(newcus.checkfilename) != 0 )
       perror("Error deleting file");
       
       int result = rename("Temp.dat",newcus.checkfilename);
       if ( result != 0 )
       perror( "Error renaming file" );
       
       cout<<" TRANSACTION SUCCESSFULL ! ";
       cout<<endl;
       cout<<endl;
       cout<<" YOUR CURRENT BALANCE IS : ";
       newcus.getamount(7);
       cout<<"\n\nPress any key to continue !";
       getch();
          
        }
        
void updateaccount()            //This is called when user chooses to update account. It is used to validate the users account.    
      { 
        ifstream bhuttle1;
        newcus.displaymenu_for_entering_myaccount();
        cin>>newcus.checkusername;
        strcpy(newcus.checkfilename,strcat(newcus.checkusername,".dat"));
		bhuttle1.open(newcus.checkfilename,ios::binary|ios::in);
        if (!bhuttle1.is_open())
        {
		   perror("Error while opening file ");
		   cout<<endl;
		   cout<<endl;
           cout<<"Please check the username you have entered!";
           cout<<"\n\nPress any key to continue !";
           getch();
           updateaccount();
        }
        bhuttle1.read((char *)&newcus,sizeof(newcus));
        bhuttle1.close();
        cout<<endl<<endl<<"PLEASE ENTER YOUR PASSWORD : ";
        cin>>newcus.checkpassword;
        cout<<endl;
       
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
               getch();
      }

//outline definition of setpassword
void Customer::setpassword()
  {
         cout<<endl<<"SIZE OF PASSWORD (MAX - 10)"<<endl;
         cout<<endl<<"ONLY LETTERS! NO NUMBERS OR SPECIAL CHARACTERS"<<endl;
         cout<<endl;
         cout<<"YOUR PASSWORD : ";
         for (int i=0;i <10;i++)
         {   
             int a;
             a=getch();
             if( a == '\r')
             {
                 cout<<endl<<endl;
                 cout<<std::setw(30)<<" PASSWORD NOTED! ";
                 cout<<endl;
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
  //Outline definition of displaymenu    
  void Customer::displaymenu()
  {
    int var;
    welcome_heading(3);
    cout<<endl;
    cout<<endl;
    cout<<"\"EVERY GREAT BUSINESS IS BUILT ON FRIENDSHIP\" - JC PENNEY";
    cout<<endl;
    cout<<endl;
    cout<<std::setw(10)<<"1.ADD NEW ACCOUNT"<<endl<<"2.GO TO MY ACCOUNT"<<endl<<"3.CLOSE ACCOUNT"<<endl<<"4.EXIT"<<endl;
    cout<<endl;
    y:
    cout<<"OPTION NO : ";
    cin>>var;
    if (var != 1 && var != 2 && var != 3&& var != 4 )
    {
            cout<<"PLEASE ENTER A CORRECT OPTION !"<<endl<<endl;
            goto y;
            }
    switch(var)
    {
               case 1:{
                        fstream bhuttle;
                        newcus.addaccount();
		                                      
                        bhuttle.open(newcus.filename,ios::binary|ios::out);
                        bhuttle.write((char *)&newcus,sizeof(newcus));
                        bhuttle.close();
                        displaymenu();
                        break;
                     }
               case 2: { 
                         updateaccount();
                         break;
                       }
               case 3:{ 
                         closeaccount();
                         break;
                      }
               case 4: {
                       exit(0);
                       break;
                    }
               default :{
                         cout<<"PLEASE ENTER A NUMBER ACCORDING TO THE CHOICES"<<endl<<endl;
                         break;
                       }
          }
        
   }
   //Outline definition of displaymenu_for_myaccount
   void Customer::displaymenu_for_myaccount()
   {
    int var2;
    welcome_heading(3);
    welcome_statement();
    cout<<endl;
    cout<<std::setw(10)<<"1.ADD BALANCE"<<endl<<"2.WITHDRAW BALANCE"<<endl<<"3.BACK TO THE MAIN MENU"<<endl;
    cout<<endl;
    cout<<"OPTION NO : ";
    cin>>var2;
    switch(var2)
    {
               case 1:{
                         addbalance();
                         displaymenu_for_myaccount();
                         break;
                     }
               case 2:{  
                         removebalance();
                         displaymenu_for_myaccount(); 
                        break;
                       }
              case  3:{
                        displaymenu();
                        break;
                    }
                    
               default :{
                         cout<<"PLEASE ENTER A NUMBER ACCORDING TO THE CHOICES"<<endl<<endl;
                         break;
                       }
    }
    cout<<endl;
    cout<<endl;
}

int main()
{
  // CALLING THE DISPLAY MENU FUNCTION
  newcus.displaymenu();
  
getch(); 
return 0;
}
