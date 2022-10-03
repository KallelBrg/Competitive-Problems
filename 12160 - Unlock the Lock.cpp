#include <bits/stdc++.h>

using namespace std;

int x, y, z;
int dist[10000];
int vet[10000];

int bfs(int a)
{
    queue<int> fila;
    dist[a]=0;
    fila.push(a);
    while(!fila.empty())
    {
        int u=fila.front();
        fila.pop();
        for(int i=0; i<z; i++)
        {
            if(dist[(u+vet[i])%10000] == -1)
            {
                dist[(u+vet[i])%10000]=dist[u]+1;
                fila.push((u+vet[i])%10000);
            }
        }
    }
    return dist[y];
}

int main()
{
    cin >> x >> y >> z;
    while(x || y || z)
    {
        memset(dist, -1, sizeof dist);
        
        for(int i=0; i<z; i++)
        {
            cin >> vet[i];
        }
        
        int ans= bfs(x);
        if(ans == -1) cout << "Permanently Locked" << endl;
        else cout << ans << endl;
        
        cin >> x >> y >> z;
    }
    
}
