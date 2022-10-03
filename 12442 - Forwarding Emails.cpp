#include <bits/stdc++.h> 

using namespace std;

#define pb push_back

typedef pair<int,int> ii;

vector<vector<int>> g;
bool vis[50005],mark[50005];
int cont, ans, maior;
void dfs(int v)
{
    vis[v]=true;
    cont++;
    for(auto i : g[v])
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    //esse cara v=false
	vis[v]=false;
	mark[v]=true;
	//~ return;
}


int main()
{
    int n, num=1; cin >> n;
    while(n--)
    {
        ans=0; maior=-1;
        int V; cin >> V;
        g = vector<vector<int>>(V+1);
        for(int i=1; i<=V; i++)
        {
            int a, b; cin >> a >> b;
            g[a].pb(b);
        }
        
        for(int i=1; i<=V; i++)
		{
            if(!mark[i])
            {
                cont=0;
                dfs(i);
            }
            if(cont>maior)
			{
				maior=cont;
				ans=i;
			}
        }
		memset(vis, false, sizeof vis);
		memset(mark, false, sizeof mark);
        cout << "Case " << num++ << ": " << ans << endl;
    }
}
