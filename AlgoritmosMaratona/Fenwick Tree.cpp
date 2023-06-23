#include <bits/stdc++.h>
using namespace std;

class FenwickTree{
private:
	int N;
	vector<int>jt;
	int query(int id){
		int resp = 0;
		for(;id>0; id = id-(id&-id)){
			resp += jt[id];
		}
		return resp;
	}
	void update(int id, int x){
		for(; id<=N; id = id+(id&-id)){
			jt[id]+= x;
		}
	}
	
public:
	FenwickTree(){};
	FenwickTree(int N1){
		N = N1+1;
		jt.assign(N,0);
	}
	int query(int l, int r){
		return query(r)- (l ? query(l-1):0);
	}
	void up(int id, int x){
		update(id,x);
	}
};





int main(){
	FenwickTree obj(8);
	int valor;
	for(int i = 1; i<=8; i++){
		cin >> valor;
		obj.up(i,valor);
	}
	cout << obj.query(0,5) << endl;; 
	
}
