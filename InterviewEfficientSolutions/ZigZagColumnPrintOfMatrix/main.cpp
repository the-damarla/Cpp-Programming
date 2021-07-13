#include <bits/stdc++.h>

using namespace std;

void PrintDiagonalZigZag(vector<vector<int>> v)
{
    int row = v.size();
    int col = v[0].size();
    int r = 0,c = 0;
    bool flag = true;
    while(r < row && c < col)
    {
        if(flag)
        {
            while(r > 0 && c < col-1)
            {
                cout << v[r][c] << " ";
                r--;c++;
            }
            cout << v[r][c] << " ";
            if(c == col-1)
                r++;
            else
                c++;
        }
        else
        {
            while(c > 0 && r < row-1)
            {
                cout << v[r][c] << " ";
                r++;c--;
            }
            cout << v[r][c] << " ";
            if(r == row-1)
                c++;
            else
                r++;
        }
        flag = !flag;
    }
    return;
}

void PrintSpiral(vector<vector<int>> v)
{
    int row = v.size();
    int col = v[0].size();
    int top = 0,bottom = row-1,left = 0,right = col-1;
    int dir = 0;
    while(top <= bottom && left <= right)
    {
        if(dir == 0)
        {
            for(int i=top;i<=right;i++)
            {
                cout << v[top][i] << " ";
            }
            top++;
        }
        else if(dir == 1)
        {
            for(int i=top;i<=bottom;i++)
            {
                cout << v[i][right] << " ";
            }
            right--;
        }
        else if(dir == 2)
        {
            for(int i=right;i>=left;i--)
            {
                cout << v[bottom][i] << " ";
            }
            bottom--;
        }
        else if(dir == 3)
        {
            for(int i=bottom;i>=top;i--)
            {
                cout << v[i][left] << " ";
            }
            left++;
        }
        dir = (dir + 1) % 4;
    }
    return;
}

void PrintColZigZag(vector<vector<int>> v)
{
    int row = v.size();
    int col = v[0].size();
    int r = 0,c = 0;
    bool flag = true;
    while(r < row && c < col)
    {
        if(flag)
        {
            while(r < row-1)
            {
                cout << v[r][c] << " ";
                r++;
            }
            cout << v[r][c] << " ";
        }
        else
        {
            while(r > 0)
            {
                cout << v[r][c] << " ";
                r--;
            }
            cout << v[r][c] << " ";
        }
        c++;
        flag = !flag;
    }
    return;
}

void PrintRowZigZag(vector<vector<int>> v)
{
    int row = v.size();
    int col = v[0].size();
    int r = 0,c = 0;
    bool flag = true;
    while(r < row && c < col)
    {
        if(flag)
        {
            while(c < col-1)
            {
                cout << v[r][c] << " ";
                c++;
            }
            cout << v[r][c] << " ";
        }
        else
        {
            while(c > 0)
            {
                cout << v[r][c] << " ";
                c--;
            }
            cout << v[r][c] << " ";
        }
        r++;
        flag = !flag;
    }
    return;
}

int main()
{
    cout << "you're expected to enter number of rows and columns" << endl;
    int row;cout << "Enter number of rows : ";cin >> row;
    int col;cout << "Enter number of columns : ";cin >> col;
    vector<vector<int>> v(row,vector<int> (col));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout << "Enter " << i << "th row " << j << "th column : ";
            cin >> v[i][j];
        }
    }
    cout << "Col ZigZag : ";
    PrintColZigZag(v);
    cout << "\nRowZigZag : ";
    PrintRowZigZag(v);
    cout << "\nDiagonal ZigZag : ";
    PrintDiagonalZigZag(v);
    cout << "\nSpiral Print : ";
    PrintSpiral(v);
    return 0;
}
