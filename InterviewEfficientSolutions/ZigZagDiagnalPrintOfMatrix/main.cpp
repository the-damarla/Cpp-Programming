#include <bits/stdc++.h>

using namespace std;

void ZigZagPrint(vector<vector<int>> matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int row = 0,col = 0;
    bool up = true;
    while(row < m && col < n)
    {
        if(up)
        {
            while(row > 0 && col < n-1)
            {
                cout << matrix[row][col] << " ";
                row--;col++;
            }
            cout << matrix[row][col] << " ";
            if(col == n-1)
                row++;
            else
                col++;
        }
        else
        {
            while(col > 0 && row < m-1)
            {
                cout << matrix[row][col] << " ";
                row++;col--;
            }
            cout << matrix[row][col] << " ";
            if(row == m-1)
                col++;
            else
                row++;
        }
        up = !up;
    }
}

int main()
{
    cout << "You're Expected to enter rows and columns" << endl;
    int rows;cout << "number of rows : ";cin >> rows;
    int cols;cout << "number of cols : ";cin >> cols;
    vector<vector<int>> matrix(rows, vector<int> (cols));
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
        {
            cout << "Enter " << i << "th row " << j << "th column element : ";
            cin >> matrix[i][j];
        }
    ZigZagPrint(matrix);
    return 0;
}
