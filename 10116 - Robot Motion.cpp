#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define f first
#define s second

typedef pair<int,int> ii;

int n, m, r, save1, save2; 
char grid[12][12];
int dist[12][12];

bool bfs(int x, int y)
{
    queue<ii>q;
    dist[x][y]=1;
    q.push({x,y});
    bool ok=true;
    while(!q.empty() && ok)
    {
        int u=q.front().f, v=q.front().s;
        bool ret = 1;
        q.pop();
        if(u+1>=0 && u+1<n && v>=0 && v<m && dist[u+1][v]==-1 && grid[u][v] == 'S')
        {
            dist[u+1][v]=dist[u][v]+1;
            ret = 0;
            q.push({u+1,v});
        }
        if(u>=0 && u<n && v+1>=0 && v+1<m && dist[u][v+1]==-1 && grid[u][v] == 'E')
        {
            dist[u][v+1]=dist[u][v]+1;
            ret = 0;
            q.push({u,v+1});
        }
        if(u-1>=0 && u-1<n && v>=0 && v<m && dist[u-1][v]==-1 && grid[u][v] == 'N')
        {
            dist[u-1][v]=dist[u][v]+1;
            ret = 0;
            q.push({u-1,v});
        }
        if(u>=0 && u<n && v-1>=0 && v-1<m && dist[u][v-1]==-1 && grid[u][v] == 'W')
        {
            dist[u][v-1]=dist[u][v]+1;
            ret = 0;
            q.push({u,v-1});
        }
        if(ret) 
        {
			if(u+1<n && dist[u+1][v] != -1 && grid[u][v] == 'S')
			{
				save1=u+1;
				save2=v;
				ok=false;
				break;
			}
			if(v+1<m && dist[u][v+1] != -1 && grid[u][v] == 'E')
			{
				save1=u;
				save2=v+1;
				ok=false;
				break;
			}
			if(u - 1 >= 0 && dist[u - 1][v] != -1 && grid[u][v] == 'N')
			{
				save1=u-1;
				save2=v;
				ok=false;
				break;
			}
			if(v - 1 >= 0 && dist[u][v-1] != -1 && grid[u][v] == 'W')
			{
				save1=u;
				save2=v-1;
				ok=false;
				break;
			}
		}
    }
    return ok;
    
}


int main()
{
    cin >> n >> m >> r;
    while(n || m || r)
    {
        memset(dist, -1, sizeof dist);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin >> grid[i][j];
            }
        }
        bool verifica = bfs(0,r-1);
        
        int mm=-1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(dist[i][j] > mm) mm=dist[i][j];
            }
        }
        if(verifica)
        {
            cout << mm << " step(s) to exit" << endl;
        }
        else
        {
			int kallel=dist[save1][save2]-1;
			cout << kallel << " step(s) before a loop of " << mm-kallel << " step(s)" << endl;
		}
      

        
        cin >> n >> m >> r;
    }
		
}
