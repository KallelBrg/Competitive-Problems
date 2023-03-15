#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define f first
#define s second
#define inf 1000000000

typedef pair<int, int> ii;

vector<ii>g[20005];

int Dijkstra(int ini, int fim)
{
	priority_queue<ii, vector<ii>, greater<ii>> q;
	vector<int> dist(20005, inf);
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
	int T, caso=1; cin >> T;
	while(T--)
	{
		int n, m, o, d;
		cin >> n >> m >> o >> d;
		for(int i=0; i<m; i++)
		{
			int a, b, c; cin >> a >> b >> c;
			g[a].pb({b,c});
			g[b].pb({a,c});
		}
		int ans=Dijkstra(o,d);
		
		if(ans == inf) cout << "Case #" << caso++ << ": unreachable" << endl;
		else cout << "Case #" << caso++ << ": " << ans << endl;
		for(int i=0; i<n; i++)
		{
            g[i].clear();
        }
	}
}
