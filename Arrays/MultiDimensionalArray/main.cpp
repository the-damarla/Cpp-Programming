// CPP program
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n = 2;
	int m = 2;

	/*
	Create a vector containing "n"
	vectors each of size "m".
	*/
	vector<vector<int>> vec( n , vector<int> (m));

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int x; cin >> x;
			vec[i][j] = x;
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}

return 0;
}
