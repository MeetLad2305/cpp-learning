#include<iostream>
#include<iomanip>
using namespace std;
class product{
        string product_name;
        float price_per_unit;
        int quantity;
    public:
        void set_name(string name)
        {
            product_name=name;
        }
        void set_pp_unit(float price)
        {
            price_per_unit=price;
        }
        void set_quantity(int qua)
        {
            quantity=qua;
        }
        string get_name()
        {
            return product_name;
        }
        float get_price()
        {
            return price_per_unit;
        }
        int get_qty()
        {
            return quantity;
        }
        float total_cost()
        {
            return price_per_unit*quantity;
            
        }
        float discount()
        {
            float d=total_cost();
            if(d>500)
            {
                return d-(d*0.1);
            }
            return d;
        }
};
int main()
{
    product pro[3];
    int i,q;
    float ppu;
    string n;
    for(i=0;i<3;i++)
    {
        cout<<"Enter the product name:";
        cin>>n;
        pro[i].set_name(n);
        cout<<"Enter the price per unit :";
        cin>>ppu;
        pro[i].set_pp_unit(ppu);
        cout<<"Enter the Product Quantity :";
        cin>>q;
        pro[i].set_quantity(q);
    }
     cout<<"Product Name "<<setw(20)<<"Price per Unit"<<setw(20)<<"Quantity"<<setw(20)<<"Total"<<endl;
    for(i=0;i<3;i++)
    {
        cout<<"---------------------"<<endl<<setw(10);
        cout<<pro[i].get_name()<<setw(20)<<pro[i].get_price()<<setw(20);
        cout<<pro[i].get_qty()<<setw(20)<<pro[i].discount()<<endl;
        cout<<"---------------------"<<endl;
    }
}
