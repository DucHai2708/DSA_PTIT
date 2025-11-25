#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int Mod = 1e9+7;

int n, m, parent[100001], num[100001];

void init(){
	for(int i = 1; i <= n; i++){
		parent[i] = i;
		num[i] = 1;
	}
}

int Find(int u){
	if(u != parent[u])
		parent[u] = Find(parent[u]);
	return parent[u];
}

void Union(int u, int v){
	int a = Find(u), b = Find(v);
	if(a == b) return;
	if(a > b) swap(a,b);
	parent[b] = a;
	num[a] += num[b];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    int t = 1; 
    while(t--) {
		cin >> n >> m;
		init();
		int u, v;
		for (int i = 1; i <= m; i++) {
			cin >> u >> v;
			Union(u,v);
		}
		int ans = num[1];
		int maxx = 0;
		for (int i = 2; i <= n; i++) {
			int x = Find(i);
			if( x > 1) {
				maxx = max(maxx,num[x]);
			}
  	 	}
  	 	cout << ans+maxx;
	}	
}
