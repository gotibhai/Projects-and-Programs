//BBZ- CLASS 12th FINAL PROJECT
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
      char gender;          //gender of the user
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
           cout<<endl;
           cout<<endl;
        cout<<"YOUR BALANCE : ";
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
      
      // An overloaded function just to print the Balance of the user.
      void getamount( int t)
      {
           cout<<amount;
           cout<<endl; 
           }
    /*
    THE FOLLOWING FUNCTIONS INPUT THE PRIVATE VARIABLES OF THE CLASS CUSTOMER !
    */       
      void addfname()      
      {     
           cout<<"FIRST NAME : ";
           cin>>fname; 
           cout<<endl;
      }
      void addsname() 
      {     
           cout<<"SECOND NAME : ";
           cin>>sname;
           cout<<endl;
      }
           
      void addage() 
      { 
           age1:
           cout<<"AGE : ";
           cin>>age;
           if(age < 18 || age > 90)
           {
                  cout<<"Please Enter your Correct Age! Minors shall not be permitted access!"<<endl<<endl;
                  goto age1;
                  }
           cout<<endl;
      }
        
      void addaddress()
      {    
           cout<<"YOUR ADDRESS : ";\
           cin.ignore();
           cin.getline(address,'#'); 
           cout<<endl;
      }
      void addaddress(int t)
      {    
           cout<<endl;
           cout<<"ENTER YOUR NEW ADDRESS : ";\
           cin.ignore();
           cin.getline(address,'#'); 
            cout<<endl;
      }
      void addamount()
      {
           cout<<"ADD BALANCE : ";
           cin>>amount;
           cout<<endl;
      }
      void addgender()
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
      //This Function Sets the Password for the User
      void setpassword();
      //This Function Creates a Specialized USER-NAME for Each User!
      void accno()  
      {
         
         char noofacc_string[32];
         strcpy(accname,sname);
		 sprintf(noofacc_string, "%d",::noofacc);
	     
		 strcat(accname,noofacc_string);    
                             
         cout<<std::setw(30)<<" YOUR ACCOUNT NAME IS : ";
		 cout<<accname;
		 
         strcpy(filename,strcat(accname,".dat"));
         
		 cout<<endl;
         cout<<endl;
		 cout<<endl;
		 
		 noofacc++;
         cout<<"\n\nPress any key to continue !";
         char x1;
         x1=getch();
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
     //overloading of functions to output different types of welcome messages
     void welcome_heading(int t)
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

      //THIS IS THE MAIN FUNCTION FOR CREATING AN ACCOUNT! IT CALLS OTHER PRIMARY FUNCTIONS!
      void addaccount()
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
           accno();                             // Creates a unique account name for the user
           keep_number();                       //This keeps a track of the number of accounts in the bank!
      }
      
      //Function to update the values of the users account 
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
        cout<<endl<<endl<<"PLEASE ENTER YOUR PASSWORD : ";
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

     //Function for a Loading animation
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
          
          cout<<"Transaction in Progress";
          
          for(cursor=0;cursor<no_of_cycles;cursor++)
             {
                   cout<<".";
                   Sleep(0700);
  
              }    
                 cout<<endl;                   
     } 
     
     //Function for adding balance to the users account!
     void addbalance()
     {
       long double amount_added;
       welcome_heading(5);
       welcome_statement();
       getamount();
       cout<<endl;
       cout<<" AMOUNT TO BE ADDED: ";
       cin>>amount_added;
       waiting(amount_added);
       cout<<endl;
       cout<<endl;
       amount=amount+amount_added;
       Customer newcus;
       ofstream bhuttle;
       bhuttle.write((char *)&newcus,sizeof(newcus));
       bhuttle.close();
       cout<<" TRANSACTION SUCCESSFULL ! ";
       cout<<endl;
       cout<<endl;
       cout<<" YOUR CURRENT BALANCE IS : ";
       getamount(5);

          }
     //Function to remove balance to the users account!     
     void removebalance()
     {
       long double amount_withdraw;
       welcome_heading(5);
       welcome_statement();
       getamount();
       cout<<endl;
       cout<<" AMOUNT TO BE WITHDRAWN: ";
       cin>>amount_withdraw;
       waiting(amount_withdraw);
       cout<<endl;
       cout<<endl;
       amount=amount-amount_withdraw;
       Customer newcus;
       ofstream bhuttle;
       bhuttle.write((char *)&newcus,sizeof(newcus));
       bhuttle.close();
       cout<<" TRANSACTION SUCCESSFULL ! ";
       cout<<endl;
       cout<<endl;
       cout<<" YOUR CURRENT BALANCE IS : ";
       getamount(5);
        }
        
     //This function is used to update the details of the customers account eg: Address
       void updatedetails()
     {
       char change_address[300];
       int one;
       welcome_heading(4);
       welcome_statement();
       cout<<endl;
       cout<<endl;
       cout<<std::setw(10)<<" 1.CHANGE ADDRESS"<<endl;
       cout<<endl;
       cout<<endl;
       cout<<" PRESS 1 TO CHANGE YOUR ADDRESS..."<<endl<<endl;;
       cout<<" PRESS 0 FOR MAIN MENU..."<<endl;
       cout<<endl;
       cout<<endl;
       cin>>one;
       if(one == 1)
       {
              Customer newcus;
              ofstream bhuttle;
              addaddress(3);
              bhuttle.write((char *)&newcus,sizeof(newcus));
              bhuttle.close();
              cout<<endl;
              cout<<endl;
              cout<<" YOUR ADDRESS HAS BEEN SUCCESSFULLY CHANGED! ";
              cout<<endl;
              
              cout<<"\n\nPress any key to continue !";
              char x2;
              x2=getch();
              displaymenu_for_myaccount(); 
              
              }
       else
       {
               displaymenu_for_myaccount();   //Taking the user back to the main menu 

          }
      }
     
     //Function call to delete the users account!
     void closeaccount()
     {
           welcome_heading(5);
           //Customer newcus;
           cout<<endl;
           cout<<endl;
           cout<<" ENTER YOUR USERNAME : ";
           cin>>checkusername;
           strcpy(checkfilename,strcat(checkusername,".dat"));
           
           if( remove(checkfilename) != 0 )
           {
               cout<<endl;
               cout<<endl;
           perror(" ERROR DELETING FILE !" );
           }
           else
           puts(" ACCOUNT DELETED !");
           
           welcome_statement(5);
           cout<<"BHUTTLE BANKING SERVICE SHALL MISS YOU !"<<endl;
           cout<<endl;
          }
          
    //THIS IS A FUNCTION WHICH DISPLAYS THE MENU SCREEN WHEN USER OPTS TO MODIFY DATA. THIS VALIDATES IF THE USER HAS A ACCOUNT 
    void displaymenu_for_entering_myaccount()
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
	//FUNCTION TO DISPLAY THE WELCOME MESSAGE FOR USERS WITH THEIR NAMES USING FUNCTION OVERLOADING!
	void welcome_statement()
	{
    cout<<endl;
    cout<<endl;
    cout<<"WELCOME ";
    if(gender == 'M' || gender == 'm')
    cout<<"MR ";
    else 
    cout<<"MRS ";
    fname[20] = toupper(fname[20]);
    cout<<fname;
    cout<<" ";
    sname[20]=toupper(sname[20]);
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
    fname[20] = toupper(fname[20]);
    cout<<fname;
    cout<<" ";
    sname[20]=toupper(sname[20]);
    cout<<sname;
    cout<<",";
    cout<<endl;    
     }	
	
	//A FUNCTION TO DISPLAY MENU FOR MY ACCOUNT
	void displaymenu_for_myaccount();   
    
              	
    //THIS IS A FUNCTION WHICH DISPLAYS THE MENU SCREEN
    void displaymenu();   
           
}; //CLASS DECLARATION END

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
    cout<<std::setw(10)<<"1.ADD NEW ACCOUNT"<<endl<<"2.GO TO MY ACCOUNT"<<endl<<"3.CLOSE ACCOUNT"<<endl;
    cout<<endl;
    y:
    cout<<"OPTION NO : ";
    cin>>var;
    if (var != 1 && var != 2 && var != 3 )
    {
            cout<<"PLEASE ENTER A CORRECT OPTION !"<<endl<<endl;
            goto y;
            }
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
               case 2: { 
                         updateaccount();
                         break;
                       }
               case 3:{ 
                         closeaccount();
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
    cout<<std::setw(10)<<"1.ADD BALANCE"<<endl<<"2.WITHDRAW BALANCE"<<endl<<"3.UPDATE ACCOUNT DETAILS"<<endl<<"4.BACK TO THE MAIN MENU"<<endl;
    cout<<endl;
    cout<<"OPTION NO : ";
    cin>>var2;
    switch(var2)
    {
               case 1:{
                         addbalance();
                         break;
                     }
               case 2:{  
                        removebalance(); 
                        break;
                       }
              case 3:{ 
                        updatedetails();
                        break;
                      }
              case  4:{
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
  int idk;
  //CREATING AN OBJECT OF THE CLASS--CUSTOMER
  Customer newcus;
  // CALLING THE DISPLAY MENU FUNCTION
  newcus.displaymenu();
  
  
     
cin>>idk;
return 0;
}
