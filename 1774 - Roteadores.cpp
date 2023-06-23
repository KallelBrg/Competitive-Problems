#include <bits/stdc++.h>
using namespace std;
#define pb push_back
struct UF
{
	vector<int> pai,r;
	UF(int n)
	{
		pai.resize(n);
		r.resize(n);
		for(int i=0;i<n;i++)
		{
			pai[i]=i;
			r[i]=1;			
		}
	}
	int acha(int x)
	{
		if(pai[x]==x) 
			return x;
		return pai[x]=acha(pai[x]);
	}
	void unir(int x, int y)
	{
		x=acha(x);
		y=acha(y);
		if(r[x]>r[y])
		{
			pai[y]=x;
			r[x]+=r[y];
		}
		else
		{
			pai[x]=y;
			r[y]+=r[x];
		}
	}
	bool mesmoConjunto(int x,int y)
    {
		return acha(x)==acha(y);
	}
};

int main()
{
    int V,A,x,y,P;
    cin>>V>>A;
    vector<pair<int,pair<int,int>>>Arestas;
    for(int i=0;i<A;i++)
    {
        cin>>x>>y>>P;
        Arestas.push_back({P,{x,y}});
    }
    sort(Arestas.begin(),Arestas.end());
    UF MST(V+1);
    int S=0;
    for(int i=0;i<Arestas.size();i++)
    {
        P=Arestas[i].first;
        x=Arestas[i].second.first;
        y=Arestas[i].second.second;
        if(!MST.mesmoConjunto(x,y))
        {
            MST.unir(x,y);
            S+=P;
        }
    }
    cout<<S<<endl;
}
