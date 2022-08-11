#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int vx[] = {-1,0,1,0}, vy[] = {0,1,0,-1};
int const MAX=50;
char aux;
int ans, n, m;
bool vis[MAX][MAX];
char mat[MAX][MAX];

bool cmp(pair<int, char> a, pair<int, char> b) {
	if(a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}

void floodf(int a, int b)
{
	vis[a][b]=true;
	ans++;
	for(int i=0; i<4; i++)
	{
		int x = a+vx[i];
		int y = b+vy[i];
		if(x < n && x >= 0 && y < m && y >= 0 && !vis[x][y] && mat[x][y] == aux)
		{
			floodf(x,y);
		}
	}
}

int main()
{ 
	int caso=1;
	cin >> n >> m;
	while(n || m)
	{
		vector<pair<int,char> > result;
		memset(vis, false, sizeof vis);
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				cin >> mat[i][j];
			}
		}
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				if(!vis[i][j] && mat[i][j]!='.')
				{
					ans=0;
					aux = mat[i][j];
					floodf(i,j);
					result.pb({ans,aux});
				}
			}
		}
		sort(result.begin(), result.end(), cmp);
		cout << "Problem " << caso++ << ":" << endl;
		
		for(auto [a, b] : result) {
			cout << b << ' ' << a << '\n';
		}
		cin >> n >> m;
	}
	
}
