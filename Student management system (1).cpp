#include<iostream>
#include<cstring>
using namespace std;

string ar1[20],ar2[20],ar3[20],ar4[20],ar5[20];
int total=0;

void Enter()
{
    int value;
    cout << "How many students  do you want enter : ";
    cin>>value;
    if(total==0)
    {
    for (int i=0;i<value;i++)
    {
      cout<<"Enter "<<i+1<<"student Details"<<endl;
      cout << "Enter Enrollment no :";
      cin>>ar1[i];
      
      cout << "Enter Name :";
      cin>>ar2[i];
   
      cout << "Enter Mobile no. :";
      cin>>ar3[i];
    
      cout << "Enter Course :";
      cin>>ar4[i];
      
     cout << "Enter Gender :";
     cin>>ar5[i];
      
    }
    }
    else
    {
      for (int i=total;i<total+value;i++)
    {
      cout<<"Enter "<<i+1<<"student Details"<<endl;
      cout << "Enter Enrollment no :";
      cin>>ar1[i];
      
      cout << "Enter Name :";
      cin>>ar2[i];
   
      cout << "Enter Mobile no. :";
      cin>>ar3[i];
    
      cout << "Enter Course :";
      cin>>ar4[i];
      
     cout << "Enter Gender :";
     cin>>ar5[i];
     cout << endl;
    }
    }
    cout<<endl;
    total=total+value;
    

}
void show()
{
      if(total==0)
      {
        cout << "No records found !!" << endl;
      }
      else
      {
      for (int i=0;i<total;i++)
      { 
         cout<<""<<i+1<<" student Details"<<endl;
         
         cout<<"Enrollment no. "<<ar1[i]<<endl;
         cout<<"Student Name : "<<ar2[i]<<endl;
         cout<<"Mobile no. :"<<ar3[i]<<endl;
         cout<<"Course "<<ar4[i]<<endl;
         cout<<"Gender :"<<ar5[i]<<endl;
         cout <<endl;
      }
      cout<<endl;
      }
}
void update()
{
  string enroll;
   cout << "Enter your enrollment no :" << endl;
   cin>>enroll;
   for(int i=0;i<total;i++)
   {
     if(enroll==ar1[i])
     {
         cout<<"Previous Data"<<endl;
         cout <<endl;
         cout<<"Enrollment no. "<<ar1[i]<<endl;
         cout<<"Student Name : "<<ar2[i]<<endl;
         cout<<"Mobile no. :"<<ar3[i]<<endl;
         cout<<"Course "<<ar4[i]<<endl;
         cout<<"Gender :"<<ar5[i]<<endl;
         cout <<endl;
         cout<<"Enter new Data"<<endl;
         cout<<endl;
         cout << "Enter Enrollment no :";
         cin>>ar1[i];
      
         cout << "Enter Name :";
         cin>>ar2[i];
   
         cout << "Enter Mobile no. :";
         cin>>ar3[i];
    
         cout << "Enter Course :";
         cin>>ar4[i];
      
         cout << "Enter Gender :";
         cin>>ar5[i];
     }
   }

cout<<endl;
}
void search()
{
   string enroll;
   cout << "Enter your enrollment no :" << endl;
   cin>>enroll;
   
   for(int i=0;i<total;i++)
   {
     if(enroll==ar1[i])
     {
         cout<<"Enrollment no. "<<ar1[i]<<endl;
         cout<<"Student Name : "<<ar2[i]<<endl;
         cout<<"Mobile no. :"<<ar3[i]<<endl;
         cout<<"Course "<<ar4[i]<<endl;
         cout<<"Gender :"<<ar5[i]<<endl;
         cout <<endl;
     }
     
   }

cout<<endl;
}
void deleterecord()
{
  int a;
  cout << "press 1. to delete all records" << endl;
  cout << "press 2. to delete specific records" << endl;
  cout << "Enter your choice " << endl;
  cin>>a;
  if(a==1)
  { 
     total=0;
     cout << "all records delete successfully !!" << endl;
     
  }
  else if(a==2)
  {
    string enroll;
    cout << "Enter enrollment no. : " << endl;
    cin>>enroll;
    for(int i=0;i<total;i++)
    {
      if(enroll==ar1[i])
      {
         for(int j=i;j<total;j++)
         {
             ar1[j]=ar1[j+1];
             ar2[j]=ar2[j+1];
             ar3[j]=ar3[j+1];
             ar4[j]=ar4[j+1];
             ar5[j]=ar5[j+1];
         }
         total--;
         cout << "your specific records is deleted" << endl;
      }
    }
  
  }

cout<<endl;
}
int main()
{
   
   while(true)
   {
      int choice;
      cout << "1. Enter Student Details " << endl;
      cout << "2. Show Student Details " << endl;
      cout << "3. Update Student Data " << endl;
      cout << "4. Search  Student Data" << endl;
      cout << "5. Delete Student Data " << endl;
      cout << "6. Exit " << endl;
      
      cout << "Enter your choice ";
      cout <<endl;
      cin>>choice;
      switch(choice)
      {
         case 1:
           Enter();
           break;
          
         case 2 :
           show();
           break;
          
         case 3:
           update();
           break;
         
        
         case 4:
           search();
           break;
         
        
         case 5:
           deleterecord ();
           break;
         
        
         case 6:
           exit(0);
           break;
         
         default:
           cout << "Wrong choice !!!";
           break;
         
         
      }
      
   }
   
}