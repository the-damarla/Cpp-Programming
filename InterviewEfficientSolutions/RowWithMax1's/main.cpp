#include <bits/stdc++.h>

using namespace std;

void GetColWithMax1s(vector<vector<int>> v,int row,int col)
{
    int r,c;r=c=0;
    int count1 = 0;
    int maxi = 0;
    int colInd;
    cout << "Given Matrix ---> \n";
    while(c < col)
    {
        r = 0;
        count1 = 0;
        while(r < row)
        {
            cout << v[r][c] << " ";
            count1 += v[r][c];
            r++;
        }
        cout << " -----> " << count1;
        if(maxi < count1)
        {
            maxi = count1;
            colInd = c;
        }
        cout << "\n";
        c++;
    }

    cout << "\n\nColumn with max number of 1's " << colInd  << " with " << maxi << " No. of 1's\n";
    return;
}

void GetRowWithMax1s(vector<vector<int>> v,int row,int col)
{
    int r,c;r=c=0;// row col traversal variables
    int count1;//count variable
    int maxi = 0;
    int rowInd;
    cout << "\nGiven Matrix ------> \n";
    while(r < row)
    {
        count1 = 0;
        c = 0;
        while(c < col)
        {
            cout << v[r][c] << " ";
            count1 += v[r][c];
            c++;
        }
        if(maxi < count1)
        {
            maxi = count1;
            rowInd = r;
        }
        r++;
        cout << " ------> " << count1 << "\n";
    }
    cout << "\nThe Row with max 1's is " << rowInd << " with " << maxi << " number of 1's\n" << endl;
    return;
}

int main()
{
    cout << "You're expected to give the size of the matrix" << endl;
    cout << "Enter number of rows : ";int row;cin >> row;
    cout << "Enter number of cols : ";int col;cin >> col;
    vector<vector<int>> matrix(row,vector<int> (col,0));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout << "Enter " << i << "th row " << j << "th element : ";cin >> matrix[i][j];
        }
    }
    GetRowWithMax1s(matrix,row,col);
    GetColWithMax1s(matrix,row,col);
    return 0;
}
