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
 
int vx[]={1,0,-1,0}, vy[]={0,1,0,-1};
int dist[105][105];
char grid[105][105];
int n, m;
 
void bfs(int a, int b)
{
	queue<ii> q;
	dist[a][b]=0;
	q.push({a,b});
	while(!q.empty())
	{
		int u=q.front().f , v=q.front().s;
		q.pop();
		for(int i=0; i<4;i++)
		{
			int x = u+vx[i];
			int y = v+vy[i];
			if(x>=0 && x<n && y>=0 && y<m && grid[x][y] == '.' && dist[x][y]==-1)
			{
				dist[x][y]=dist[u][v]+1;
				q.push({x,y});
			}
		}
	}
	
}
 
 
 
int main()
{
	cin >> n >> m;
	
	int x; cin >> x;
	while(x--)
	{
		memset(grid, '.', sizeof grid);
		int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
		a--;b--;c--;d--;e--;f--;
		grid[a][b]='R';
		grid[c][d]='G';
		grid[e][f]='G';
		memset(dist, -1, sizeof dist);
		bfs(a,b);
		int rato[4]={dist[0][b],dist[a][m-1],dist[n-1][b],dist[a][0]};
		memset(dist, -1, sizeof dist);
		bfs(c,d);
		int gato1[4]={dist[0][b],dist[a][m-1],dist[n-1][b],dist[a][0]};
		memset(dist, -1, sizeof dist);
		bfs(e,f);
		int gato2[4]={dist[0][b],dist[a][m-1],dist[n-1][b],dist[a][0]};
		bool ok=true;
		
		for(int i=0; i<4 && ok; i++)
		{
			if(rato[i] < gato1[i] && rato[i] < gato2[i]) ok=false;
		}
		if(ok) cout << "NO" << endl;
		else cout << "YES" << endl;
		
		
	}
