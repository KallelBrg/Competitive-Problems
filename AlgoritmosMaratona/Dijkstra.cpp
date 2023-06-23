#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define tos to_string
#define inf 1000000000
#define entrada freopen("input.txt", "r", stdin);
#define saida freopen("output.txt", "w", stdout);

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
vector<ii>g[5];

int Dijkstra(int ini, int fim)
{
	priority_queue<ii, vector<ii>, greater<ii>> q;
	vector<int> dist(100, inf);
	q.push({0,ini});
	dist[ini]=0;
	while(!q.empty())
	{
		ii u=q.top();
		q.pop();
		if(u.f > dist[u.s]) continue;
		for(ii i:g[u.s])
		{
			int v=i.f;
			int p=i.s;
			if(dist[v]>dist[u.s]+p)
			{
				dist[v]=dist[u.s]+p;
				q.push({dist[v],v});
			}
		}
	}
	return dist[fim];
}

int main()
{
		
	for(int i=0; i<4; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a].pb({b,c});
		g[b].pb({a,c});
	}
	cout << Dijkstra(1,4) << endl;
	
}
