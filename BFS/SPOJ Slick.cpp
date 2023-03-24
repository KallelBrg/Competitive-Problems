#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
typedef pair<int,int> ii;

int vx[]={0,1,0,-1}, vy[]={1,0,-1,0};
int n, m;
int grid[255][255];
int dist[255][255];
map<int,int>mp;
map<int,int>::iterator it;

void bfs(int x, int y)
{
	queue<ii> q;
	dist[x][y]=1;
	q.push({x,y});
	int sum=0;
	while(!q.empty())
	{
		sum++;
		int u = q.front().f, v=q.front().s;
		q.pop();
		for(int i=0; i<4; i++)
		{
			int a = u+vx[i];
			int b = v+vy[i];
			if(a>=0 && b>=0 && a<n && b<m && grid[a][b]==1 && dist[a][b]==-1)
			{
				dist[a][b]=dist[u][v]+1;
				q.push({a,b});
			}
		}
	}
	mp[sum]++;
}


int main()
{
	cin >> n >> m;
	while(n || m)
	{
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				cin >> grid[i][j];
			}
		}
		memset(dist,-1,sizeof dist);
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				if(grid[i][j]==1 && dist[i][j]==-1)
				{
					bfs(i,j);
				}
			}
		}
		int resp=0;
		for(int i=0; i<(int)mp.size(); i++)
		{
			resp+=mp[i];
		}
		cout << resp << endl;
		for(it=mp.begin(); it!=mp.end(); it++)
		{
			if(it->second!=0)cout << it->first << " " << it->second << endl;
		}
		mp.clear();
		
		cin >> n >> m;
	}
}
