#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

int n, u, v, a[104][104], visited[104], truoc[104];

void init(){
	cin >> n >> u >> v;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
}

void DFS(int s){
	visited[s] = 1; truoc[s] = 0;
	for(int t = 1; t <= n; t++){
		if(a[s][t] && !visited[t]){
			DFS(t); truoc[t] = s;
		}
	}
}

void solve1(){
	int dem = 0;
	for(int t = 1; t <= n; t++){
		if(a[u][t] && a[t][v]) ++dem;
	}
	cout << dem << endl;
}

void solve2(){
	DFS(u);
	vector<int> path;
	if(truoc[v] == 0){
		cout << 0 << endl;
	}
	else{
		path.push_back(v);
		int x = truoc[v];
		while(x != u){
			path.push_back(x);
			x = truoc[x];
		}
		path.push_back(x);
		for(int i = path.size()-1; i >= 0; i--) cout << path[i] << " ";
		cout << endl;
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here
	int t; cin >> t;
	init();
	if(t == 1){
		solve1();
	}
	else{
		solve2();
	}
	return 0;
}