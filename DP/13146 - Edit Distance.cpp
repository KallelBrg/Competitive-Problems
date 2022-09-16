#include <bits/stdc++.h>

using namespace std;

int EditDist(string a, string b, int tamA, int tamB)
{
	int dp[tamA+1][tamB+1];
	for(int i=0; i<=tamA; i++)
	{
		for(int j=0; j<=tamB; j++)
		{
			if(!i)dp[i][j]=j;
			else if(!j)dp[i][j]=i;
			else if(a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1];
			else dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
		}
	}
	return dp[tamA][tamB];
}


int main()
{
	string a, b;
	int n; cin >> n;
	cin.ignore();
	while(n--)
	{
		getline(cin, a);
		getline(cin, b);
		if(a=="" || b=="")cout << max(a.size(), b.size()) << endl;
		else cout << EditDist(a,b,a.size(),b.size()) << endl;
	}	
}
