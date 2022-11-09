#include <bits/stdc++.h>

using namespace std;

#define int long long int

int vet[21];
int dp[30010][22];

int coin(int x, int sum, int i)
{
	if(dp[sum][i]!=-1) return dp[sum][i];
	if(sum == x) return 1;
	if(sum > x || i >= 21) return 0;
	
	int pego=coin(x,sum+vet[i],i);
	int npego=coin(x,sum,i+1);
	
	return dp[sum][i]=pego+npego;
}

signed main()
{
	for(int i=0; i<21; i++)
	{
		vet[i]=pow(i+1, 3);
	}
	int n;
	while(cin >> n)
	{
		memset(dp, -1, sizeof dp);
		cout << coin(n,0,0) << endl;
	}
	
}
