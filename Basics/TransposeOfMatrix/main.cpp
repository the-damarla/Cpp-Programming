#include <iostream>

using namespace std;

int main()
{
    cout << "Enter No. of rows : ";
    int r; cin >> r;
    cout << "Enter No. of Columns : ";
    int c; cin >> c;
    cout << "Enter elements of the Array : \n";
    int a[100][100] = {0};
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin >> a[i][j];
        }
    }
    int tr[100][100] = {0};
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            tr[j][i] = a[i][j];
        }
    }
    cout << "Transpose of the matrix is : \n";
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
            cout << tr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
