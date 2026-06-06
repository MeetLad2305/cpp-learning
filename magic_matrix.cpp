#include<iostream>
using namespace std;
#define MAX 10
int main() {
    int mat[MAX][MAX], n, i, j;
    int rowSum, colSum, diag1 = 0, diag2 = 0;
    int magicSum, isMagic = 1;
    cout<<"Enter N: ";
    cin>>n;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            cout<<"Enter the "<< i+1<< " rows " <<j+1<< " element : ";
            cin>>mat[i][j];
        }

            
    // Calculate magic sum from first row
    magicSum = 0;
    for (j = 0; j < n; j++) 
        magicSum += mat[0][j];
    cout<<"Magic Sum:"<<magicSum<<endl;
    // Check rows
    for (i = 0; i < n; i++) 
    {
        rowSum = 0;
        for (j = 0; j < n; j++)
            rowSum += mat[i][j];
        if (rowSum != magicSum) 
            isMagic = 0;
    }
    // Check columns
    for (j = 0; j < n; j++) {
        colSum = 0;
        for (i = 0; i < n; i++) 
            colSum += mat[i][j];
        if (colSum != magicSum) 
            isMagic = 0;
    }
    // Main diagonal: top-left to bottom-right
    for (i = 0; i < n; i++)
        diag1 += mat[i][i];
   
    for (i = n-1; i >=0; i--)
        diag2 += mat[i][i];  
    if (diag1 != magicSum || diag2 != magicSum) 
        isMagic = 0;
    cout<<"Diagonal 1 sum: "<<diag1<<endl;
    cout<<"Diagonal 2 sum: "<<diag2<<endl;
    
    if (isMagic == 0) 
        cout<<"Result: Not a Magic Square"<<endl;
    else
        cout<<"Result: Magic Square"<<endl;
    return 0;
}
