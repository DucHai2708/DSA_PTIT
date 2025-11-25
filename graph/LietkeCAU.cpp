#include <bits/stdc++.h>

 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

vector<vector<int>> List;
vector<pair<int,int>> Edge;
bool visited[1671];
int V, E, x, y, solt = 0;

void init(){
	cin >> V >> E;
	memset(visited,false,sizeof(visited));
	Edge.clear(); Edge.resize(E+1);
	List.clear(); List.resize(V+1);
	int u, v;
	for(int i = 1; i <= E; i++){
		cin >> u >> v;
		Edge[i].first = u; Edge[i].second = v;
		List[u].push_back(v);
		List[v].push_back(u);
	}
	solt = 0; x = -1; y = -1;

}

void DFS(int u){
	visited[u] = true;
	for(int v : List[u]){
		if((u == x && v == y) || (u == y && v == x)){
			continue;
		}
		if(!visited[v]){
			DFS(v);
		}
	}
}

void Cau(){
	memset(visited,false,sizeof(visited));
	int cnt = 0;
	for(int i = 1; i <= V; i++){
		if(!visited[i]){
			DFS(i);
			++cnt;
		}
	}
	if(cnt > solt){
		cout << x << " " << y << " ";
	}
}

void solve(){
	init();
	for(int i = 1; i <= V; i++){
		if(!visited[i]){
			DFS(i);
			++solt;
		}
	}
	for(int i = 1; i <= E; i++){
		x = Edge[i].first;
		y = Edge[i].second;
		Cau();
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//data
	//code here
	int t = 1; cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
}