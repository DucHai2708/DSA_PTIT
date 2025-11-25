#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

/*
Kiem tra xem co chu trinh hay khong
*/

int n, m, parent[100001], num[1000001], ans = INT_MIN;

void init(){
	for(int i = 1; i <= n; i++){
		parent[i] = i;
		num[i] = 1;
	}
	ans = INT_MIN;
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
	ans = max(ans,num[a]);
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
		while(m--){
			cin >> u >> v;
			Union(u,v);
		}
		cout << ans << endl;
	}
}