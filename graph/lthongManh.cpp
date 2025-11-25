#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;
 
vector<int> List[1671];
int visited[1671];

void DFS(int u){
	visited[u] = 1;
	for(int v : List[u]){
		if(!visited[v]){
			DFS(v);
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
		int V, E;
		cin >> V >> E;
		memset(visited,0,sizeof(visited));	
		for(int i = 1; i <= V; i++){
			List[i].clear();
		}
		int u, v;
		for(int i = 1; i <= E; i++){
			cin >> u >> v;
			List[u].push_back(v);
		}
		int ok = 1;
        for(int i = 1; i <= V; i++){
            if(!visited[i]){
                DFS(i);
                for(int j = 1; j <= V; j++){
                    if(!visited[j]){
                        ok = 0;
                        break;
                    }
                }
                if(!ok) break;
            }
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
	}  
}