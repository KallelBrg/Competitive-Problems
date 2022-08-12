#include <bits/stdc++.h>

using namespace std;

#define pb push_back

vector<vector<int>> g;
vector<vector<int>> g2;
vector<bool> vis;
stack<int>stk;

void dfs1(int x)
{
	vis[x]=true;
	for(auto i : g[x])
	{
		if(!vis[i])
		{
			dfs1(i);
		}
	}
	stk.push(x);
}

void dfs2(int x)
{
	vis[x]=true;
	for(auto i : g2[x])
	{
		if(!vis[i])
		{
			dfs2(i);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int V, A; // vértices e arestas
	cin >> V >> A;
	while(V || A)
	{
		int ans=0, k=1;
		map<string,int>mp;
		vector<string> lx; 
		g = vector<vector<int>> (V+1);
		g2 = vector<vector<int>> (V+1);
		vis = vector<bool> (V+1);
		
		string a, b, nomes;
		cin.ignore();
		for(int i=0; i<V; i++)
		{
			getline(cin, nomes);
			lx.pb(nomes);
		}
		for(int i=0; i<A; i++)
		{
			getline(cin, a);
			getline(cin, b);
			if(!mp[a]) {mp[a] = k; k++;}
			if(!mp[b]) {mp[b] = k; k++;}
			g[mp[a]].pb(mp[b]);
			g2[mp[b]].pb(mp[a]);
		}
		for(int i=1; i<=V; i++)
		{
			if(!vis[i])
			{
				dfs1(i);
			}
		}
		vis.assign(V+1, false);
		while(!stk.empty())
		{
			int u=stk.top(); stk.pop();
			if(!vis[u])
			{
				ans++;
				dfs2(u);
			}
		}
		cout << ans << endl;
		cin >> V >> A;
	}
	
}
