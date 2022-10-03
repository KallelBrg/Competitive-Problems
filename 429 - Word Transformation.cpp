#include <bits/stdc++.h>

using namespace std;

#define pb push_back

vector<string>vec;
map<string,int> dist;

int bfs(string o, string d)
{
	queue<string> q;
	dist[o]=1;
	q.push(o);
	while(!q.empty())
	{
		string u=q.front();
		q.pop();
		for(int i=0; i<(int)vec.size(); i++)
		{
			if(u.size() == vec[i].size())
			{
				int aux=0;
				for(int j=0; j<(int)vec[i].size(); j++)
				{
					if(u[j] != vec[i][j])
					{
						aux++;
					}
				}
				if(aux == 1 && dist[vec[i]] == 0)
				{//Posso ir
					dist[vec[i]]=dist[u]+1;
					q.push(vec[i]);
				}
			}
		}
	}
	return dist[d];
}


int main()
{
	int t; cin >> t;
	string fds;
	getline(cin, fds);
	while(t--)
	{
		string str, lixo;
		cin >> str;
		while(str!="*")
		{
			vec.pb(str);
			cin >> str;
		}
		cin.ignore();
		getline(cin, lixo);
		while(lixo.size() > 0)
		{
			string n1, n2;
			bool muda=true;
			for(int i=0; i<(int)lixo.size(); i++)
			{
				if(lixo[i] != ' ' && muda)
				{
					n1+=lixo[i];
				}
				else
				{
					if(!muda) n2+=lixo[i];
					muda=false;
				}
			}
			dist.clear();
			cout << n1 << " " << n2 << " " << bfs(n1,n2)-1 << endl;
			getline(cin, lixo);
		}
		
		if(t>0) cout << endl;
		vec.clear();
	}
	//~ cout << "t = " << t;
	
	
	
}
