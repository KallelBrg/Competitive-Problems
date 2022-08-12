#include <bits/stdc++.h> 

using namespace std;

#define pb push_back

vector<vector<int>> g;
vector<bool> vis;
stack<int>stk;

void dfs(int x)
{
	vis[x]=true;
	for(auto i : g[x])
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}
	stk.push(x);
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n; cin >> n;
	while(n--)
	{
		int v, a;
		int ans=0;
		cin >> v >> a;
		g = vector<vector<int>> (v);
		vis = vector<bool> (v);
		for(int i=0; i<a; i++)
		{
			int x, y; cin >> x >> y;
			x--; y--;
			g[x].pb(y);
		}
		for(int i=0; i<v; i++)
		{
			if(!vis[i])
			{
				dfs(i);
			}
		}
		vis.assign(v, false);
		while(!stk.empty())
		{
			int u = stk.top(); stk.pop();
			if(!vis[u])
			{
				ans++;
				dfs(u);
			}
			
		}
		while(!stk.empty())
		{
			stk.pop();
		}
		cout << ans << endl;
		
	}
		
}
