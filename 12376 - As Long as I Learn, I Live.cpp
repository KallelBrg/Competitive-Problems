#include <bits/stdc++.h>

using namespace std;

#define entrada freopen("input.txt", "r", stdin);
#define saida freopen("output.txt", "w", stdout);
#define pb push_back

vector<vector<int>> g;
bool vis[102];
int V, E, p;
int peso[102];

void dfs(int x, int &last)
{
    vis[x]=true;
    int maior=0;
    for(auto i : g[x])
    {
        if(peso[i] > maior)
        {
            maior=peso[i];
            p=i;
        }
    }
    if(!vis[p])
    {
        last=p; 
        peso[p]+=peso[x];
        dfs(p, last);
    }
}

int main()
{
    //~ entrada;
    //~ saida;
    int n, caso=1; cin >> n;
    
    
    while(n--)
    {
        cin >> V >> E;
        g = vector<vector<int>> (V);
        memset(vis, false, sizeof vis);
        for(int i=0; i<V; i++)
        {
            cin >> peso[i];
        }
        
        for(int i=0; i<E; i++)
        {
            int x, y; cin >> x >> y;
            g[x].pb(y);
        }
        int indice=0;
        dfs(0,indice);
        int maior=0;
        maior=peso[indice];
 
        cout << "Case " << caso++ << ": " << maior << " " << indice << endl;
        
        
    }
}
