#include<iostream>
#include <string>
using namespace std;
void display(string nm,int num_day=1,int choice=1)
{
    cout<<"--------------------"<<endl;
    cout<<"-----HOTEL BILL-----"<<endl;
    cout<<"--------------------"<<endl;
    cout<<"Name: "<<nm<<endl;
    cout<<"Days :"<<num_day<<endl;
    if(choice==1)
    {
        cout<<"Room Type : Standard"<<endl;
        cout<<"Bill  : "<<num_day*2000<<endl;
    }
    else if(choice==2)
    {
        cout<<"Room Type : Deluxe"<<endl;
        cout<<"Bill  : "<<num_day*3500<<endl;
    }
    else if(choice==3)
    {
        cout<<"Room Type : Suit"<<endl;
        cout<<"Bill  : "<<num_day*5000<<endl;
    }
}
void bill(string cust_name)
{
    display(cust_name);
}
void bill(string cust_name,int nu_day)
{
    display(cust_name,nu_day);
}
void bill(string cust_name,int nu_day,int room_choice)
{
    display(cust_name,nu_day,room_choice);
    
}
int main()
{
    string name;
    int day,room_choice;
    cout<<"Enter the Customer Name:";
    getline(cin, name);
    cout<<"Enter the Number of Days:";
    cin>>day;
    cout<<"Room Rates:"<<endl;
    cout<<"1. Standard - 2000/day"<<endl;
    cout<<"2. Deluxe   - 3500/day"<<endl;
    cout<<"3. Suite    - 5000/day"<<endl;
    cout<<"Enter the Room Choice : ";
    cin>>room_choice;
    bill(name,day,room_choice);
}