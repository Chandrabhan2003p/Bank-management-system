#include<iostream>
#include<vector>
using namespace std;

class BankAccount
{
    private:
    string name;
    int accountnum;
    double balance;
    
    public:
    BankAccount(string n,int acc,double bal)
    {
      name=n;
      accountnum=acc;
      balance=bal;
    }
    string getName()
    {
      return name;
    } 
    int getAccountNum()
    {
       return accountnum;
    }
    double getBalance()
    {
       return balance;
    }
    void deposit(double amount) 
    {
       balance=balance+amount; 
       cout<<"\tTransaction complete successfully"<<endl;   
    }
    void withdraw(double amount)
    {
       if(balance >= amount)
       {
          balance = balance - amount;
          cout<<"\tWithdraw Successfully.."<<endl;
       }
       else
       {
          cout<<"\tInsufficient balance..."<<endl;
       }
    }
    
};

class Bankmanagement
{
    private:
    vector<BankAccount>accounts;
    public:
    void Addaccount(string name,int accountnum,double balance)
    {
      accounts.push_back(BankAccount(name,accountnum,balance));
    }
    void showAllAccounts()
    {
      cout<<"\n\tAll Accounts Holder's"<<endl;
      cout<<"\t---------------------------"<<endl;
      for(int i = 0;i<accounts.size();i++)
      {
         cout<<"\tName :"<<accounts[i].getName()<<endl<<"\tAccount Number :"<<accounts[i].getAccountNum()<<endl<<"\tBalance :"<<accounts[i].getBalance()<<endl;
         cout<<endl;
      }
    }
    void searchAccount(int account)
    {
      
      cout<<"\n\tSearch Accounts"<<endl;
      cout<<"\t---------------------------"<<endl;
      cout<<endl;
      for(int i=0;i<accounts.size();i++)
      {
         if(accounts[i].getAccountNum()==account)
         {
         cout<<"\tName :"<<accounts[i].getName()<<endl<<"\tAccount Number :"<<accounts[i].getAccountNum()<<endl<<"\tBalance :"<<accounts[i].getBalance()<<endl;
         }
                
      }
    }
    BankAccount* findAccount(int accountNum)
    {
      for(int i=0;i<accounts.size();i++)
      {
        if(accounts[i].getAccountNum()==accountNum)
        {
          return &accounts[i];
        }
      }
    }
};

int main()
{
   Bankmanagement bank;
   int choice;
   char option;
   
   do
  {
     cout<<"\t::Bank Management System "<<endl;
     cout<<"\t\t Main Menu "<<endl;
     cout<<"\t1. Create a new account "<<endl;
     cout<<"\t2. Show all accounts "<<endl;
     cout<<"\t3. Search account "<<endl;
     cout<<"\t4. Deposit money "<<endl;
     cout<<"\t5. Withdrawal money "<<endl;
     cout<<"\t6. Exit "<<endl;
     cout<<"\t--------------------------"<<endl;
     cout<<"\tEnter your choice :";
     cin>>choice;
     switch(choice)
     {
       case 1:
       {
         string name;
         int accountnum;
         double balance;
     
         cout<<"\tEnter account holder name :";
         cin>>name;
         cout<<"\tEnter account number :";
         cin>>accountnum;
         cout<<"\tEnter initial balance :";
         cin>>balance;
         bank.Addaccount(name,accountnum,balance);
         cout<<"\tAccount Created Successfully.."<<endl;
         break;
       }
       case 2:
       {
         bank.showAllAccounts();
         break;
       }
    
       case 3:
       {
         int accountNum;
         cout<<"\tEnter account number:";
         cin>>accountNum;
         bank.searchAccount(accountNum);
         break;
         
       }
       case 4:
       {
         int accountNum;
         double amount;
         cout<<"Enter account number to deposit money :";
         cin>>accountNum;
         BankAccount* account=bank.findAccount(accountNum);
         
         if(account!=NULL)
         {
           cout<<"\tEnter amount to deposit :";
           cin>>amount;
           account->deposit(amount);
           cout<<"\t"<<amount<<" Deposit successfully...."<<endl; 
         }
         else
         {
           cout<<"\tAccount Not Found...."<<endl;
         }
         break;
       }
       case 5:
       {
         int accountNum;
         double amount;
         cout<<"Enter account number to withdraw money :";
         cin>>accountNum;
         BankAccount* account=bank.findAccount(accountNum);
         
         if(account!=NULL)
         {
           cout<<"\tEnter amount to withdraw :";
           cin>>amount;
           account->withdraw(amount);
         }
         else
         {
           cout<<"\tAccount Not Found...."<<endl;
         }
          break;
       }
       case 6:
       {
          exit(1);
          break;
       }
       
       
    }
      cout<<"\tDo you want Run Again y/n :";
      cin>>option;
  }while(option=='y'||option=='Y');

   

}