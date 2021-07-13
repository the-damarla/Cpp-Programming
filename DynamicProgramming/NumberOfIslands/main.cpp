#include <bits/stdc++.h>

using namespace std;

void mark(vector<vector<char>> &matrix,int x,int y, int r,int c)
{
    if(x < 0 || x >= r || y < 0 || y >= c || matrix[x][y] != '1')
        return;
    matrix[x][y] = '2';
    mark(matrix,x+1,y,r,c);
    mark(matrix,x,y+1,r,c);
    mark(matrix,x-1,y,r,c);
    mark(matrix,x,y-1,r,c);
}

int numIslands(vector<vector<char>> &grid)
{
    int rows = grid.size();
    if(rows == 0)
        return 0;
    int cols = grid[0].size();
    int num = 0;
    for(int i=0;i<rows;++i)
    {
        for(int j=0;j<cols;++j)
        {
            if(grid[i][j] == '1')
            {
                mark(grid,i,j,rows,cols);
                num += 1;
            }
        }
    }
    return num;
}

int main()
{
    cout << "Here I am taking 5*5 matrix So enter accordingly" << endl;
    vector<vector<char>> matrix(5,vector<char> (5));
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout << "Enter " << i << "th row " << j << "th element : ";
            cin >> matrix[i][j];
        }
    }
    int res = numIslands(matrix);
    cout << "No of Islands found are : " << res;
    return 0;
}
