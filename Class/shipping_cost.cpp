#include<iostream>
#include<iomanip>
using namespace std;
float shipping_cost(float product_weight)
{
    return product_weight*50;
}
float shipping_cost(float product_weight,float dist)
{
    return (product_weight*50)+(dist*2);
}
float shipping_cost(float product_weight,float dist,char exp_choice)
{
    float a=shipping_cost(product_weight,dist),b=0;
    if(exp_choice=='Y' || exp_choice=='y')
    {
        b=300;
    }
    return a+b;
}
int main()
{
    float weight,distance;
    char Choice;
    cout<<"Enter the Weight:";
    cin>>weight;
    cout<<"Enter the Distance:";
    cin>>distance;
    cout<<"For express Delivery write ('Y' or 'y')"<<endl;
    cout<<"Enter the Choice:";
    cin>>Choice;
    cout<<setw(25)<<"Only Weight"<<setw(10)<<shipping_cost(weight)<<endl;
    cout<<setw(25)<<"Weight And Distance"<<setw(10)<<shipping_cost(weight,distance)<<endl;
    cout<<setw(25)<<"All Three feature"<<setw(10)<<shipping_cost(weight,distance,Choice)<<endl;

}
