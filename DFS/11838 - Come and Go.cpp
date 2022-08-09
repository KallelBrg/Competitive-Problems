#include <cstdio>
#include <vector>

using namespace std;

#define pb push_back

vector<vector<int>> g;
vector<bool> vis;
int n, m;

void dfs(int x)
{
	vis[x]=true;
	for(auto i:g[x])
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}
}

int main()
{
    scanf("%d%d", &n,&m);
    while(n || m)
    {
        int ans=0;
        g = vector<vector<int>> (n);
        vis = vector<bool> (n);
        for(int i=0; i<n; i++)
        {
            vis[i]=false;
        }

        int V, W, P;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d", &V,&W,&P);
            V--; W--;
            if(P==1)
            {
                g[V].pb(W);
            }
            else
            {
                g[V].pb(W);
                g[W].pb(V);
            }
        }
        for(int j=0; j<n; j++)
        {
            if(!vis[j])
            {
                dfs(j);
            }
            for(int i=0; i<n; i++)
            {
                if(!vis[i])
                {
                    ans++;
                    i=n;
                    j=n;
                }
            }
            for(int k=0; k<n; k++)
            {
                vis[k]=false;
            }
        }

        if(ans)printf("0\n");
        else printf("1\n");

        scanf("%d%d", &n,&m);
    }
}
