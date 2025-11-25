#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

vector<int> List[1671];
int visited[1671], parent[1671], s, t, V, E;

void BFS(int u){
	queue<int> q;
	q.push(u); visited[u] = 1;
	while(!q.empty()){
		int S = q.front(); q.pop();
		for(int i : List[S]){
			if(!visited[i]){
				q.push(i); parent[i] = S;
				visited[i] = 1;
			}
		}
	}
}

void retracePath(){
	if(!parent[t]){
		cout << -1;
	}
	else{
		vector<int> path;
		path.push_back(t);
		int u = parent[t];
		while(u != s){
			path.push_back(u);
			u = parent[u];
		}	
		path.push_back(u);
		for(int i = path.size()-1; i >= 0; i--) cout << path[i] << " ";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//data:
	//code here
	int T = 1; cin >> T;
	while(T--){
		cin >> V >> E >> s >> t;
		memset(visited,0,sizeof(visited));
		memset(parent,0,sizeof(parent));
		for(int i = 1; i <= V; i++) List[i].clear();
		int arr[2*E+1];
		for(int i = 1; i <= 2*E; i++){
			cin >> arr[i];
		}
		for(int i = 1; i <= 2*E; i+=2){
			List[arr[i]].push_back(arr[i+1]);
		}
		BFS(s);
		retracePath();
		cout << endl;
	}
}
