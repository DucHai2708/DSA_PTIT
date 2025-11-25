#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

int n, m, a[104][104], visited[104];

struct edge{
	int dau, cuoi;
} G[104];

typedef struct edge edge;

void init(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> G[i].dau >> G[i].cuoi;
		a[G[i].dau][G[i].cuoi] = 1; 
		a[G[i].cuoi][G[i].dau] = 1;
	}
}

void reset(){
	memset(visited,0,sizeof(visited));
}

void DFS(int s){
	visited[s] = 1;
	for(int t = 1; t <= n; t++){
		if(a[s][t] && !visited[t]){
			DFS(t);
		}
	}
}

void DuyetCau(){
	vector<edge> v;
	for(int e = 1; e <= m; e++){
		a[G[e].dau][G[e].cuoi] = 0;
		a[G[e].cuoi][G[e].dau] = 0;
		DFS(1);
		int ok = 0;
		for(int u = 1; u <= n; u++){
			if(!visited[u]){
				ok = 1;
				break;
			}
		}
		if(ok){
			v.push_back(G[e]);
		}
		reset();
		a[G[e].dau][G[e].cuoi] = 1;
		a[G[e].cuoi][G[e].dau] = 1;
	}
	if(!v.empty()){
		cout << v.size() << endl;
		for(auto x : v) cout  << x.dau << " " << x.cuoi << endl;
	}
}


 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here
	init();
	DuyetCau();
}