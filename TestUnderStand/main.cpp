#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> SpiralCreation(int n)
{
	vector<vector<int>> grid(n,vector<int>(n,0));
	int inc = 1;
	int dir=0,top=0,left=0,right=n-1,down=n-1;

	while(top <= down && left <= right)
	{
		if(dir == 0)
		{
			for(int i=left;i<=right;i++)
			{
				grid[top][i] = inc;
				//cout << top << i << " ";
				inc++;
			}
			//cout << "\n";
			top++;
		}
		if(dir == 1)
		{
			//cout << "-----> right" << right << " ";
			for(int i=top;i<=down;i++)
			{
				grid[i][right] = inc;
				//cout << i << right << " ";
				inc++;
			}
			//cout << "\n";
			right--;
		}
		if(dir == 2)
		{
			for(int i=right;i>=left;i--)
			{
				grid[down][i] = inc;
				//cout << down << i << " ";
				inc++;
			}
			//cout << "\n";
			down--;
		}
		if(dir == 3)
		{
			for(int i=down;i>=top;i--)
			{
				grid[i][left] = inc;
				//cout << i << left << " ";
				inc++;
			}
			//cout << "\n";
			left++;
		}
		//dir++;
		dir = (dir+1)%4;
		//cout << dir << "\n";
	}
	//cout << "\n";
	return grid;
}

int main()
{
	int n;cout << "Enter a number : ";
	cin >> n;
	vector<vector<int>> grid(n,vector<int>(n));
	grid = SpiralCreation(n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout << grid[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
