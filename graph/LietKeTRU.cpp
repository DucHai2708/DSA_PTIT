#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

int n, m, visited[1671];
vector<int> List[1671];

void DFS(int u) {
	visited[u] = 1;
	for (int v : List[u]) {
		if (!visited[v]) {
			DFS(v);
		}
	}
}

int tplt() {
	int dem = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			++dem;
			DFS(i);
		}
	}
	return dem;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here
	int tc = 1; cin >> tc;
	while (tc--){
		cin >> n >> m;
		for (int i = 1; i <= n; i++) List[i].clear();
		memset(visited,0,sizeof(visited));
		int u, v;
		for (int i = 1; i <= m; i++) {
			cin >> u >> v;
			List[u].push_back(v);
			List[v].push_back(u);
		}
		int solt = tplt();
		for (int i = 1; i <= n; i++) {
			memset(visited,0,sizeof(visited));
			visited[i] = 1;
			if (solt < tplt()) {
				cout << i << ' ';
			}
		}
		cout << '\n';
	}
}