#include <bits/stdc++.h>

using namespace std;

#define int long long int

const int INF = (int)1e9;
int n, ans = 0;
vector<vector<int>>dist(1000, vector<int>(1000, INF));

void makeset()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			dist[i][j] = INF;
		}
	}
	for(int i = 0; i < n; i++)
	{
		dist[i][i] = 0;
	}
}


void floyd()
{
	for(int k = 0; k < n; k++)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(dist[i][k]+dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k]+dist[k][j];
				}
			}
		}
	}
}


signed main()
{
	int tt, caso=1; cin >> tt;
	while(tt--)
	{
		int m;
		cin >> n >> m;
		makeset();
		for(int i = 0; i < m; i++)
		{
			int a, b; cin >> a >> b;
			dist[a][b]=1;
			dist[b][a]=1;
		}
		floyd();
		//~ for(int i = 0; i < n; i++)
		//~ {
			//~ for(int j = 0; j < n; j++)
			//~ {
				//~ cout << dist[i][j] << " ";
			//~ }
			//~ cout << endl;
		//~ }
		
		int a, b; cin >> a >> b;
		for(int i = 0; i < n; i++)
		{
			if(dist[a][i]+dist[i][b] > ans)
			{
				ans = dist[a][i]+dist[i][b];
			}
		}
		
		cout << "Case " << caso++ << ": " << ans << endl;
		ans=0;
	}
	
	
	
	
}
