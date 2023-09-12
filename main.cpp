#include<conio.h>
#include <fstream>
#include <windows.h>
#include<stdio.h>
#include<iostream>
using namespace std;


class bank
{
    char name[100],add[100],y;
    int balance, amount, mobile_no, pin;
public:
    void open_account ();
    void deposite_money();
    void withdraw_money ();
    void display_account();
    void set_pin();
    void update_pin();
};
void bank::open_account()
{ 
    system("cls");
    cout<<"Enter your full name -->";
    cin.ignore();
    cin.getline(name,100);
    cout<<"Enter your address -->";
    cin.ignore();
    cin.getline(add,100);
    cout<<"Enter your mobile number -->";
    cin>>mobile_no;
    cout<<"Enter your PIN -->";
    cin>>pin;
    cout<<"What type of account you want to open, saving (s) or current (c)? \n";
    cin>>y;
    cout<<"Enter amount for deposit -->";
    cin>>balance;
    cout<<"Your account is created...";

}
void bank::deposite_money()
{
    int a ;
    cout<<"Enter how much money you want to deposit ::";
    cin>>a;
    balance+=a;
    cout<<"Your total deposit amount is "<<balance<<endl;
}
void bank::display_account()
{
    cout<<"Name ::"<<name<<endl;
    cout<<"Address -->"<<add<<endl;
    cout<<"Mobile Number -->"<<mobile_no<<endl;
    cout<<"Account Type -->"<<y<<endl;
    cout<<"Balance -->"<<balance<<endl;
}

void bank::withdraw_money()
{
    int p;
    cout<<"Enter your PIN -->";
    cin>>p;
    if(p==pin)
    {
        cout<<"Withdraw -->\n";
        cout<<"Enter the amount for withdrawal -->";
        cin>>amount;
        if(balance>=amount)
        {
            balance=balance-amount;
            cout<<"Transaction Successful!\n";
            cout<<"Now your total balance is left -->"<<balance<<endl;
        }
        else
        {
            cout<<"Transaction failed! You don't have enough balance in your account.\n";
        }
    }
    else
    {
        cout<<"Invalid PIN. Transaction Failed!\n";
    }
}

int main()
{   
     
	int ch,x,n;
    bank obj;
    system("cls");
    
    do
    {   
    

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        cout<<"\n\n\t\t\t\t=========================================\n";
        cout<<"\t\t\t\t ||welcome to the Maya world of banking||";
        cout<<"\n\t\t\t\t=========================================\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
            cout<<"\n\t\t\t\t01)Open account\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            cout<<"\n\t\t\t\t02)Deposit money\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout<<"\n\t\t\t\t03)Withdraw money\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            cout<<"\n\t\t\t\t04)Display account\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            cout <<"\n\t\t\t\t05)Update PIN\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		    cout <<"\n\t\t\t\t06)Exit\n";
        
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
            cout<<"\n\t\t\t\tPlease select an option from the above menu --> ";
            cin>>ch;

        switch(ch)
        {    
            case 1:
                obj.open_account ();
                break;
            case 2:
                obj.deposite_money();
                break;
            case 3:
                obj.withdraw_money ();
                break;
            case 4:
                obj.display_account();
                break;
            case 5:
                if(ch==5)
                {
                   cout<< "Exit\n";
                }
                break;
            case 6:
                
                obj.update_pin();
                break;    
            default:
                cout<<"Invalid option! Please try again.\n";
        }
        
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout<<"\nDo you want to select the next step? Press y for Yes, or n to terminate: ";

x=getch();
if(x=='n' || x=='N')
cout<<"Terminating...\n";
}
while (x=='y' || x=='Y');
getch();
return 0;
}

void bank::set_pin()
{
cout<<"Please enter a 4-digit PIN for your account: ";
cin>>pin;
cout<<"PIN set successfully!\n";
}

void bank::update_pin()
{
int old_pin, new_pin;
cout<<"Enter your old PIN: ";
cin>>old_pin;
if(old_pin != pin)
{
cout<<"Invalid PIN!\n";
return;
}
cout<<"Enter your new PIN: ";
cin>>new_pin;
pin = new_pin;
cout<<"PIN updated successfully!\n";
}
