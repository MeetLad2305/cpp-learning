#include<iostream>
using namespace std;
class InvItem
{
        int item_id;
        int cur_qty;
        string item_name;
    public:
        InvItem()
        {
            item_id = 0;
            cur_qty = 0;
            item_name = "";
        }
        InvItem(int i_id,int i_qty,string i_name)
        {
            item_id=i_id;
            cur_qty=i_qty;
            item_name=i_name;
        }
        InvItem& operator ++()
        {
            cur_qty++;
            return *this;
        }
        InvItem operator ++(int)
        {
            InvItem temp = *this;
            cur_qty++;
            return temp;
        }
        InvItem& operator --()
        {
            cur_qty--;
            return *this;
        }
        InvItem operator --(int)
        {
            InvItem temp = *this;
            cur_qty--;
            return temp;
        }
        InvItem operator +(InvItem x)
        {
            return InvItem(item_id,cur_qty+(x.cur_qty),item_name);
        }
        InvItem operator -(InvItem x)
        {
        
            return InvItem(item_id,cur_qty-(x.cur_qty),item_name);
        }
        InvItem operator *(InvItem x)
        {
            return InvItem(item_id,cur_qty*(x.cur_qty),item_name);
        }
        InvItem operator /(InvItem x)
        {
            return InvItem(item_id,cur_qty/(x.cur_qty),item_name);
        }
        bool operator >(InvItem y)
        {
            return cur_qty>y.cur_qty;
        }  
        bool operator <(InvItem y)
        {
            return cur_qty<y.cur_qty;
        }  
        bool operator >=(InvItem y)
        {
            return cur_qty>=y.cur_qty;
        }  
        bool operator <=(InvItem y)
        {
            return cur_qty<=y.cur_qty;
        }  
        bool operator ==(InvItem y)
        {
            return cur_qty==y.cur_qty;
        }  
        bool operator !=(InvItem y)
        {
            return cur_qty!=y.cur_qty;
        }  
        InvItem& operator =(const InvItem &z)
        {
            cur_qty=z.cur_qty;
            item_id=z.item_id;
            item_name=z.item_name;
            return *this;
        }
        InvItem& operator +=(InvItem &z)
        {
            cur_qty=cur_qty+z.cur_qty;
            return *this;
        }
        InvItem& operator -=(InvItem &z)
        {
            cur_qty=cur_qty-z.cur_qty;
            return *this;
        }
        bool operator &&(InvItem y)
        {
            return cur_qty&&y.cur_qty;
        } 
        bool operator ||(InvItem y)
        {
            return (cur_qty || y.cur_qty);
        } 
        bool operator !()
        {
            return !cur_qty;
        } 
        void display()
        {
            cout<<"ID  "<<item_id<<endl;
            cout<<"Name  "<<item_name<<endl;
            cout<<"Item Quantity "<<cur_qty<<endl;
            
        }
        int get()
        {
            return cur_qty;
        }

};
void print(int q)
{
    if(q!=0)
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
}
int main()
{
    InvItem i1(1,100,"Bag"),i2(1,50,"Bag");
    int i=0;
    cout<<"----Item info----"<<endl;
    i1.display();
    cout<<"Actul stock : "<<i1.get()<<endl;
    cout<<"Receiving new stock : "<<i2.get()<<endl;
    i1+=i2;
    cout<<"After Receiving new stock : "<<i1.get()<<endl;
    cout<<"Actul stock : "<<i1.get()<<endl;
    cout<<"Dispatching stock : "<<i2.get()<<endl;
    i1-=i2;
    cout<<"After Dispatching stock : "<<i1.get()<<endl;
    i=(i1==i2);
    cout<<"Both are Same : ";
    print(i);
    i=i1>=i2;
    if(i!=0)
    {
        cout<<"Stock is Available"<<endl;
    }
    else
    {
        cout<<"Stock is not Available"<<endl;
    }
}