#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int n;
int vet[(int)1e8];

bool ok(int k)
{
	if(vet[0] > k) return false;
	if(vet[0] == k) k--;
	for(int i=1; i<n; i++)
	{
		if(vet[i]-vet[i-1]>k)return false;
		if(vet[i]-vet[i-1]==k)k--;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int tt; cin >> tt;
	int caso=1;
	while(tt--)
	{
		cin >> n;
		for(int i=0; i<n; i++)cin >> vet[i];
		int l=1, r=(int)1e7-1;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(ok(mid))
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
			//~ cout << l << " " << r << endl;
		}
		cout << "Case " << caso++ << ": "  << l << endl;
	}
	
}
