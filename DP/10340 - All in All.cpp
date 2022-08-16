#include <bits/stdc++.h>

using namespace std;

int lcs(string a, string b, int n, int m){
    int resposta[n+1][m+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0 || j==0) resposta[i][j]=0;
            else if(a[i-1]==b[j-1]) resposta[i][j]=resposta[i-1][j-1]+1;
            else resposta[i][j]=max(resposta[i-1][j], resposta[i][j-1]);
        }
    }
    return resposta[n][m];
}

int main(){
    string a,b; 
    while(cin>>a>>b)
    {
		int ans=lcs(a,b,a.size(),b.size());
		if(ans==a.size()) cout<<"Yes";
		else cout<<"No";
		cout << endl; 
	}
    
}
