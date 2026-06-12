#include<iostream>
using namespace std;
class EmpPer
{
        int emp_id;
        string emp_name;
        string emp_dept;
        float score[12];
    public:
        EmpPer()
        {

        }
        EmpPer(int id,string name,string dept,float s[])
        {
            emp_id=id;
            emp_name=name;
            emp_dept=dept;
            int i;
            for(i=0;i<12;i++)
            {
                score[i]=s[i];
            }
            
        }
        float& operator [](int index)
        {
            if(index < 1 || index > 12)
            {
                cout<<"Invalid Month!\n";
                exit(0);
            }
            return score[index-1];
        }
        float operator ()(int n1,int n2)
        {
            return ((score[n1-1]+score[n2-1])/2.0);
        }
        float operator ()(int n1)
        {
            if(n1==1)
            {
                return (score[0]+score[1]+score[2])/3.0;
            }
            else if(n1==2)
            {
                return (score[3]+score[4]+score[5])/3.0;
            }
            else if(n1==3)
            {
                return (score[6]+score[7]+score[8])/3.0;
            }
            else if(n1==4)
            {
                return (score[9]+score[10]+score[11])/3.0;
            }
        }
        float operator ()()
        {
            float m,sum=0;
            for(int i=0;i<12;i++)
            {
                sum+=score[i];
            }
            return sum/12.0;
            
        }
        friend ostream& operator <<(ostream &out,EmpPer &o)
        {
             cout<<"Employe I'D : "<<o.emp_id<<endl;
            cout<<"Employe Name : "<<o.emp_name<<endl;
            cout<<"Employe Department : "<<o.emp_dept<<endl;
            for(int j=0;j<12;j++)
            {
                cout<<j+1<<"month performance score : "<<o.score[j]<<endl;
            
            }
            return out;

        }
        friend istream& operator >>(istream &in,EmpPer &o)
        {
             cout<<"Employe I'D : "; 
             in>>o.emp_id;
            cout<<"Employe Name : ";
             in>>o.emp_name;
            cout<<"Employe Department : ";
             in>>o.emp_dept;
            for(int i = 0; i < 12; i++)
            {
                cout << "Score " << i + 1 << " : ";
                in >> o.score[i];
            }

            return in;

        }
        
      
};
 
int main()
{
    EmpPer emp;
    cin>>emp;
    cout<<emp<<endl;

    cout<<"\nMarch Score : "
        <<emp[3]<<endl;

    emp[3]=99;

    cout<<"Updated March Score : "<<emp[3]<<endl;

    cout<<"\nAverage of Month 2 & 5 : "<<emp(2,5)<<endl;

    cout<<"Quarter 1 Average : "<<emp(1)<<endl;

    cout<<"Annual Average : "<<emp()<<endl;


    return 0;
}