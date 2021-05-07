#include <iostream>

using namespace std;

int main()
{
    int a[100][100] = {0};
    int b[100][100] = {0};
    int c[100][100] = {0};
    int r1,r2,c1,c2,i,j,k;
    cout << "Enter number of rows in 1st matrix : "; cin >> r1;
    cout << "enter number of columns in 1st matrix : "; cin >> c1;
    cout << "Enter number of rows in 2nd matrix : "; cin >> r2;
    cout << "Enter number of columns in 2nd matrix : "; cin >> c2;
    if(c1 != r2)
    {
        cout << "Multiplication Cannot be performed.";
    }
    else
    {
        cout << "Enter 1st matrix elements : \n";
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                cin >> a[i][j];
            }
        }
        cout << "enter 2nd Array elements : \n";
        for(i=0;i<r2;i++)
        {
            for(j=0;j<c2;j++)
            {
                cin >> b[i][j];
            }
        }
        cout << "Multiplication of both of the matrices is :\n ";
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                for(k=0;k<c1;k++)
                {
                    c[i][j]+= (a[i][k] * b[k][j]);
                }
            }
        }
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                cout << c[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
