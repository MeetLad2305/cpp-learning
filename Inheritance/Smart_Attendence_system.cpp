#include<iostream>
using namespace std;
class Employee
{
        int Emp_id;
        string Emp_Name;
    public:
        Employee()
        {}
        Employee(int id,string name)
        {
            Emp_id=id;
            Emp_Name=name;
        }
        void displayEmployee()
        {
            cout<<"Employee I'D : "<<Emp_id<<endl;
            cout<<"Employee Name : "<<Emp_Name<<endl;

        }

};
class Attendance
{
        int tot_work_day;
        int Day_pre;
    public:
        Attendance()
        {}
        Attendance(int twd,int dp)
        {
            tot_work_day=twd;
            Day_pre=dp;
        }
        void displayAttendance()
        {
            cout<<"Total Working Days: : "<<tot_work_day<<endl;
            cout<<"Present Days : "<<Day_pre<<endl;

        }
        float  get_present_day()
        {
            
            return Day_pre;
        }
        float  get_tot_day()
        {
            return tot_work_day;
        }

};
class PerformanceReport : public Employee,public Attendance
{
    public:
        PerformanceReport(int i,string n,int wd,int pd): Employee(i,n),Attendance(wd,pd)
        {

        }
        float calculateAttendancePercentage()
        {
            return (get_present_day()*100.0)/get_tot_day();
        }
        void display()
        {
            displayEmployee();
            displayAttendance();
            cout<<"Attendence Percentage : "<<calculateAttendancePercentage()<<endl;

        }

};
int main()
{
    int e_id,td,pd;
    string e_n;
    cout<<"Enter the Employee I'D :  ";
    cin>>e_id;
    cout<<"Enter the Employee Name :  ";
    cin>>e_n;
    cout<<"Enter the Total Working Day  :  ";
    cin>>td;
    cout<<"Enter the Present Day  :  ";
    cin>>pd;
    PerformanceReport p1(e_id,e_n,td,pd);
    p1.display();
}