#include <bits/stdc++.h>

using namespace std;

bool isSafe(int i,int j,vector<vector<int>> maze,int N)
{
    if(i >= 0 && j >= 0 && i < N && j < N && maze[i][j] == 1)
    {
        return true;
    }
    return false;
}

bool SolveMazeRecur(int N,vector<vector<int>> maze,int i,int j,vector<vector<int>> &Sol)
{
    if(i == N-1 && j == N-1 && maze[i][j] == 1)
    {
        Sol[i][j] = 1;
        return true;
    }
    if(isSafe(i,j,maze,N))
    {
        if(Sol[i][j] == 1)
            return false;

        Sol[i][j] = 1;
        if(SolveMazeRecur(N,maze,i+1,j,Sol))
            return true;
        if(SolveMazeRecur(N,maze,i,j+1,Sol))
            return true;
        if(SolveMazeRecur(N,maze,i-1,j,Sol))
            return true;
        if(SolveMazeRecur(N,maze,i,j-1,Sol))
            return true;
        Sol[i][j] = 0;
        return false;
    }
    return false;
}

bool SolveMaze(int N,vector<vector<int>> maze)
{
    vector<vector<int>> Sol(N,vector<int>(N,0));
    if(!SolveMazeRecur(N,maze,0,0,Sol))
    {
        cout << " Solution Does not exist ";
        return false;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout << Sol[i][j] << " ";
        }
        cout << "\n";
    }
    return true;
}

int main()
{
    cout << "You are expected to enter the size of the grid : ";int N;cin >> N;
    vector<vector<int>> maze(N,vector<int> (N));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout << "Enter " << j << "th element of " << i << "th row : ";cin >> maze[i][j];
        }
    }
    SolveMaze(N,maze);
    return 0;
}
