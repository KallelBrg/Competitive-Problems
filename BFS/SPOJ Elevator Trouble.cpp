#include <bits/stdc++.h>
 
using namespace std;
 
int dist[1000005];
int a, b, c, d, e;
 
int bfs(int x)
{
	queue<int> q;
	dist[x]=0;
	q.push(x);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(u+d<=a && dist[u+d]==-1)
		{
			dist[u+d]=dist[u]+1;
			q.push(u+d);
		}
		if(u-e>=0 && dist[u-e]==-1)
		{
			dist[u-e]=dist[u]+1;
			q.push(u-e);
		}
	}
	return dist[c];
}
 
 
 
int main()
{
	cin >> a >> b >> c >> d >> e;
	memset(dist, -1, sizeof dist);
	int ans=bfs(b);
	if(ans==-1) cout << "use the stairs" << endl;
	else cout << ans << endl;
	
	
	
	
}
