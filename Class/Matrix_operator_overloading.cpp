#include<iostream>
using namespace std;

class matrix
{
    int rows;
    int cols;
    int **m;
    bool valid;

public:

    matrix()
    {
        rows = 0;
        cols = 0;
        m = NULL;
        valid = false;
    }

    matrix(int r,int c)
    {
        rows = r;
        cols = c;
        valid = true;

        m = new int*[rows];
        for(int i=0;i<rows;i++)
        {
            m[i] = new int[cols];
        }
    }

    bool isValid()
    {
        return valid;
    }

    matrix operator /(int n)
    {
        if(n == 0)
        {
            cout<<"Division by zero is not possible."<<endl;
            return matrix();
        }

        matrix b(rows,cols);

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                b.m[i][j] = m[i][j] / n;
            }
        }

        return b;
    }

    matrix operator +(matrix a)
    {
        if(rows != a.rows || cols != a.cols)
        {
            cout<<"Addition not possible. Matrix dimensions must be same."<<endl;
            return matrix();
        }

        matrix b(rows,cols);

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                b.m[i][j] = m[i][j] + a.m[i][j];
            }
        }

        return b;
    }

    matrix operator -(matrix a)
    {
        if(rows != a.rows || cols != a.cols)
        {
            cout<<"Subtraction not possible. Matrix dimensions must be same."<<endl;
            return matrix();
        }

        matrix b(rows,cols);

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                b.m[i][j] = m[i][j] - a.m[i][j];
            }
        }

        return b;
    }

    matrix operator *(matrix a)
    {
        if(cols != a.rows)
        {
            cout<<"Multiplication not possible. Columns of first matrix must equal rows of second matrix."<<endl;
            return matrix();
        }

        matrix b(rows,a.cols);

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<a.cols;j++)
            {
                int sum = 0;

                for(int k=0;k<cols;k++)
                {
                    sum += m[i][k] * a.m[k][j];
                }

                b.m[i][j] = sum;
            }
        }

        return b;
    }

    friend ostream& operator <<(ostream &out,matrix &o)
    {
        if(!o.valid)
            return out;

        for(int i=0;i<o.rows;i++)
        {
            for(int j=0;j<o.cols;j++)
            {
                out << o.m[i][j] << " ";
            }
            out << endl;
        }

        return out;
    }

    friend istream& operator >>(istream &in,matrix &o)
    {
        for(int i=0;i<o.rows;i++)
        {
            for(int j=0;j<o.cols;j++)
            {
                cout<<"Enter "<<i+1<<" row "<<j+1<<" element : ";
                in>>o.m[i][j];
            }
        }

        return in;
    }
};

int main()
{
    int r,c;

    cout<<"Enter the number of rows : ";
    cin>>r;

    cout<<"Enter the number of columns : ";
    cin>>c;

    matrix A(r,c);
    matrix B(r,c);
    matrix C;

    cout<<"----For Matrix A-----"<<endl;
    cin>>A;

    cout<<"----For Matrix B-----"<<endl;
    cin>>B;

    cout<<"----A-----"<<endl;
    cout<<A;

    cout<<"----B-----"<<endl;
    cout<<B;

    cout<<"----------C=A+B-----------"<<endl;
    C = A + B;

    if(C.isValid())
        cout<<C;

    cout<<"---------C=A*B------------"<<endl;
    C = A * B;

    if(C.isValid())
        cout<<C;

    cout<<"---------C=C/2------------"<<endl;
    C = C / 2;

    if(C.isValid())
        cout<<C;

    cout<<"---------C=A+B-C------------"<<endl;
    C = A + B - C;

    if(C.isValid())
        cout<<C;

    return 0;
}
