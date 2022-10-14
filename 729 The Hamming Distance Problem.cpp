#include <bits/stdc++.h>

using namespace std;

int k, x;
void f(string str, int n)
{
	if(str.size()==k)
	{
		if(!n) cout << str << endl;
		return;
	}
	f(str+"0",n);
	f(str+"1",n-1);
}



int main()
{
	int t; cin >> t;
	while(t--)
	{
		cin>>k>>x;
		f("",x);
	}
}
