#include <bits/stdc++.h>

using namespace std;

long long int dp[30010][6];

long long int moeda[5]={50,25,10,5,1};
long long int coin(long long int x, long long int sum, long long int i)
{
	if(dp[sum][i]!=-1)return dp[sum][i];
	if(sum == x)return dp[sum][i]=1;;
	if(sum > x || i >= 5)return dp[sum][i]=0;
	
	long long int pega=coin(x,sum+moeda[i],i);
	long long int npega=coin(x,sum,i+1);
	
	return dp[sum][i] = pega+npega;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int n;
	
	while(cin >> n)
	{
		memset(dp, -1, sizeof dp);
		if(coin(n, 0, 0)==1)
		{
			cout << "There is only 1 way to produce " << n << " cents change." << endl;
		}
		else
		{
			cout << "There are " << coin(n, 0, 0) << " ways to produce " << n << " cents change." << endl;
		}
	}
	
}
