#include <iostream>

using namespace std;

int main()
{
    int a[100][100] = {0};
    int b[100][100] = {0};
    int add[100][100] = {0};
    cout << "enter Number of Rows : ";
    int r; cin >> r;
    cout << "enter number of Columns : ";
    int c; cin >> c;
    if(r != c)
    {
        cout << "Addition Cannot be performed.";
    }
    else
    {
        cout << "Enter elements of Array 1:\n";
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin >> a[i][j];
            }
        }
        cout << "Enter elements of Array 2 :\n";
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin >> b[i][j];
            }
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                add[i][j] = a[i][j] + b[i][j];
            }
        }
        cout << "The Addition of Two Arrays is : \n";
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cout << a[i][j] << "  ";
            }
            cout << "\n";
        }
        cout << "\n";
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cout << b[i][j] << "  ";
            }
            cout << "\n";
        }
        cout << "\n";
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cout << add[i][j] << "  ";
            }
            cout << "\n";
        }
    }
    return 0;
}
