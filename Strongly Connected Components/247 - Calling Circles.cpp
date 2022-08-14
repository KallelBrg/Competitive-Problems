#include <bits/stdc++.h>

using namespace std;

#define pb push_back

map<string,vector<string>>g, g2;
map<string,vector<string>>::iterator it;
map<string, bool> vis;
stack<string>stk;
vector<string> ans;

void dfs1(string x)
{
	vis[x]=true;
	for(auto i : g[x])
	{
		if(!vis[i]) dfs1(i);
	}
	stk.push(x);
}

void dfs2(string x)
{
	vis[x]=true;
	ans.pb(x);
	for(auto i : g2[x])
	{
		if(!vis[i]) dfs2(i);
	}
}

int main()
{
	int V, A, caso=1;
	bool fim = false;
	cin >> V >> A;
	while(V || A)
	{
		if(fim) cout << endl;
		for(int i=0; i<A; i++)
		{
			string x, y; cin >> x >> y;
			g[x].pb(y);
			g2[y].pb(x);
		}
		for(it=g.begin(); it!= g.end(); it++)
		{
			if(!vis[it->first]) dfs1(it->first);
		}
		vis.clear();
		cout << "Calling circles for data set " << caso++ << ":" << endl;
		while(!stk.empty())
		{
			string u=stk.top(); stk.pop();
			if(!vis[u])
			{
				dfs2(u);
				for(int i=0; i<ans.size(); i++)
				{
					cout << ans[i];
					if(i!=ans.size()-1)
					{
						cout << ", ";
					}
				}
				cout << endl;
				ans.clear();
			}
		}
		fim = true;
		vis.clear();
		g.clear();
		g2.clear();
		cin >> V >> A;	
	}
}
