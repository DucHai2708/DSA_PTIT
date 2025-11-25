#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

/*
Dem thanh phan lien thong
*/

int n, m, parent[1000005], num[100005];

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
	if(num[a] < num[b]) swap(a,b);
	parent[b] = a;
	num[a] += num[b];
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//data:
	//code here
	int t = 1;
	while(t--){
		cin >> n >> m;
		init();
		int u, v;
		while(m--){
			cin >> u >> v;
			Union(u,v);
		}
		int dem = 0;
		for(int i = 1; i <= n; i++){
			if(parent[i] == i) ++dem;
		}
		cout << dem;
	}
}