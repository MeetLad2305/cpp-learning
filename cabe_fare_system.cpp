#include<iostream>
#include<iomanip>
using namespace std;
float bill(float , int);
float fare(float dis,int car_ch=1,int sur_mul=1)
{
    float bill_amount=bill(dis,car_ch),surge_mul=0;
    
    if(sur_mul==1)
    {
        surge_mul=1;
    }
    else if(sur_mul==2)
    {
        surge_mul=1.5;
    }
    else if(sur_mul==3)
    {
        surge_mul=2;
    }
    else if(sur_mul==4)
    {
        surge_mul=2.5;
    }
    return bill_amount*surge_mul;
}
float bill(float dist,int choice)
{
    if(choice==1)
    { 
        return 50+(dist*12);
    }
    else if(choice==12)
    { 
        return 80+(dist*15);
    }
    else if(choice==3)
    { 
        return 120+(dist*20);
    }
}
int main()
{
    int Distance,car_choice,surge;
    cout<<"Enter the Distance:";
    cin>>Distance;
    cout<<"For Vehicle Number"<<endl<<"1. Mini"<<endl<<"2. Sedan"<<endl<<"3. SUV"<<endl;
    cout<<"Enter the Vehicle choice:";
    cin>>car_choice;
    cout<<"--------"<<endl;
    cout<<"For Surge Multiplier"<<endl<<"1. noramal Hours -- 1"<<endl<<"2. Moderate Demand -- 1.5"<<endl;
    cout<<"3. High Demand -- 2.0"<<endl<<"4. Festival/Rain Rush -- 2.5"<<endl;
    cout<<"Enter the Surge Multiplier:";
    cin>>surge;
    cout<<"The Total bill for cabe is "<<fare(Distance,car_choice,surge);
}
