#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int main()
{
	int n;
	while(cin >> n)
	{
		vector<int>vec;
		int num;
		//~ cout << "s" << endl;
		for(int i=0; i<n; i++)
		{
			int fds; cin >> fds;
			vec.pb(fds);
			//~ cout << "ss" << endl;
		}
		cin >> num;
		sort(vec.begin(), vec.end());
		int x=num/2, aux, x2;
		bool ok=true;
		while(ok)
		{
			int ub=upper_bound(vec.begin(), vec.end(), x)-vec.begin();
			aux=vec[ub-1];
			x2=num-aux;
			ub=upper_bound(vec.begin(), vec.end(), x2)-vec.begin();
			if(vec[ub-1] == x2) ok=false;
			else x++;
		}
		if(x2 < aux) swap(x2,aux);
		cout << "Peter should buy books whose prices are " << aux << " and " << x2 << "." << endl << endl;
		
	}
}
