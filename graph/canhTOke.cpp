#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

/*
Vô hướng
*/
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//data:
	//code here
	int t = 1; cin >> t;
	while(t--){
		int V, E;
		cin >> V >> E;
		vector<vector<int>> List(V+1);
		int u, v;
		for(int i = 1; i <= E; i++){
			cin >> u >> v;
			List[u].push_back(v);
			List[v].push_back(u); // nếu có hướng thì k cần xử lí dòng này
		}
		for(int i = 1; i <= V; i++){
			cout << i << ": ";
			for(int j = 0; j < List[i].size(); j++){
				cout << List[i][j] << " ";
			}
			cout << endl;
		}
	}
}