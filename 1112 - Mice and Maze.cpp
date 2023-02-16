#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define f first
#define s second
#define inf 1000000000

typedef pair<int, int> ii;


int V, S, T, C;
int ans;
vector<ii>g[105];

int Dijkstra(int ini, int fim)
{
	priority_queue<ii, vector<ii>, greater<ii>> q;
	vector<int> dist(105, inf);
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
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n; cin >> n;
	while(n--)
	{
		ans=0;
		/* V = qntd vertices
		 * S = saida do labirinto
		 * T = tempo inicial cronometro
		 * C = quantidade de conexões
		*/
		cin.ignore();
        string fds; getline(cin,fds);
        while(fds!="\0"){
            getline(cin,fds);
        }
		cin >> V >> S >> T >> C;
		for(int i=0; i<C; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			a--; b--;
			g[a].pb({b,c});
		}
		for(int i=0; i<V; i++)
		{
			int aux=Dijkstra(i,S-1);
			if(aux <= T)
			{
				ans++;
			}
		}
		cout << ans << endl;
		if(n>0)
		{
			cout << endl;
		}
		for(int i=0; i<100; i++){
            g[i].clear();
        }
	}
}
