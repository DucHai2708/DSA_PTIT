#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

/*
Kiem tra xem co chu trinh hay khong
*/

int n, m, parent[100001], num[1000001];

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

bool Union(int u, int v){
	int a = Find(u), b = Find(v);
	if(a == b) return false;
	if(num[a] < num[b]) swap(a,b);
	parent[b] = a;
	num[a] += num[b];
	return true;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//data:
	//code here
	int t = 1; cin >> t;
	while(t--){
		cin >> n >> m;
		init();
		int u, v;
		bool check = false;
		while(m--){
			cin >> u >> v;
			if(!Union(u,v)) check = true;
		}
		if(check) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}