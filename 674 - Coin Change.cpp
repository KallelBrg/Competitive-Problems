#include <bits/stdc++.h>

using namespace std;

int dp[30005][6];

int moeda[5]={50,25,10,5,1};
int coin(int x, int sum, int i)
{
	if(dp[sum][i]!=-1)return dp[sum][i];
	if(sum == x)return dp[sum][i]=1;;
	if(sum > x || i >= 5)return dp[sum][i]=0;
	
	int pega=coin(x,sum+moeda[i],i);
	int npega=coin(x,sum,i+1);
	
	return dp[sum][i] = pega+npega;
}

int main()
{
	int n;
	
	while(cin >> n)
	{
		memset(dp, -1, sizeof dp);
		cout << coin(n, 0, 0) << endl;
	}
	
}
