#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int Mod = 1e9+7;

int n, m, s, D[1671];// luu kc min t? s d?n D[i]
vector<pair<int,int>> List[1671];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

void Dijiktra(int ss) {
	for (int i = 1; i <= n; i++) D[i] = 1e9;
	D[ss] = 0;
	while (!q.empty()) q.pop();
	q.push({0,ss});
	while (!q.empty()) {
		int u = q.top().second; q.pop();
		for (pair<int,int> p : List[u]) {
			int v = p.second, duv = p.first; // duv: kc t? u d?n v
			if (D[v] > D[u] + duv) {
				D[v] = D[u] + duv;
				q.push({D[v],v});
			}
		}
	}	
	for (int i = 1; i <= n; i++) cout << D[i] << ' ';
	cout << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here:
	int tc = 1; cin >> tc;
	while (tc--) {
		cin >> n >> m >> s;
		int u, v, w;
		for (int i = 1; i <= n; i++) List[i].clear();
		for (int i = 1; i <= m; i++) {
			cin >> u >> v >> w;
			List[u].push_back({w,v});
			List[v].push_back({w,u});
		}
		Dijiktra(s);
	}
}