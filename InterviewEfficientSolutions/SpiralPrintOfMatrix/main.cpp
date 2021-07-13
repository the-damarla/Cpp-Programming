#include <bits/stdc++.h>

using namespace std;

void SpiralPrint(vector<vector<int>> matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int top=0,left=0,bottom=rows-1,right=cols-1;
    int dir = 0;
    while(top <= bottom && left <= right)
    {
        if(dir == 0)
        {
            for(int i=top;i<=right;i++)
            {
                cout << matrix[top][i] << " ";
            }
            top++;
        }
        else if(dir == 1)
        {
            for(int i=top;i<=bottom;i++)
            {
                cout << matrix[i][right] << " ";
            }
            right--;
        }
        else if(dir == 2)
        {
            for(int i=right;i>=left;i--)
            {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }
        else if(dir == 3)
        {
            for(int i=bottom;i>=top;i--)
            {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
        dir = (dir+1)%4;
    }
}

int main()
{
    cout << "You're expected to enter rows and columns" << endl;
    int rows;cout << "Enter number of rows : ";cin >> rows;
    int cols;cout << "Enter number of cols : ";cin >> cols;
    vector<vector<int>> matrix(rows,vector<int>(cols));
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
        {
            cout << "Enter " << i << "th row " << j << "th column element : ";
            cin >> matrix[i][j];
        }
    cout << "Spiral Traversal of given matrix is : ";
    SpiralPrint(matrix);
    return 0;
}
