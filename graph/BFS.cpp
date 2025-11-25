#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

vector<int> List[1671];
bool visited[1671];

void BFS(int u){
	queue<int> q;
	q.push(u); visited[u] = true;
	while(!q.empty()){
		int s = q.front(); q.pop();
		cout << s << " ";
		for(int t : List[s]){
			if(!visited[t]){
				q.push(t); visited[t] = true;
			}
		}
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//data:
	//code here
	int t = 1; cin >> t;
	while(t--){
		int V, E, u;
		cin >> V >> E >> u;
		memset(visited,false,sizeof(visited));
		for(int i = 0; i < 1671; i++) List[i].clear();
		int s, t;
		for(int i = 1; i <= E; i++){
			cin >> s >> t;
			List[s].push_back(t);
			List[t].push_back(s);
		}
		BFS(u); cout << endl;
	}
}