#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

int n, s, t, a[105][105], D[105], fr[105];

void init() {
	cin >> n >> s >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		D[i] = a[s][i];
		fr[i] = s;
	}
	D[s] = 0;
}

void bellman_ford() {
	for (int k = 1; k <= n-1; k++) {
		for (int u = 1; u <= n; u++) {
			for (int v = 1; v <= n; v++) {
				if (D[u] < 10000 && a[u][v] < 10000 && D[v] > D[u] + a[u][v]) {
					D[v] = D[u] + a[u][v];
					fr[v] = u;
				}
			}
		}
	}
	for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++) {
			if (D[u] < 10000 && a[u][v] < 10000 && D[v] > D[u] + a[u][v]) {
				cout << -1 << '\n';
				return;
			} 
		}
	}
	if (D[t] == 10000) cout << 0 << '\n';
	else {
		cout << D[t] << '\n';
		vector<int> path;
		path.push_back(t);
		int u = fr[t];
		while (u != s) {
			path.push_back(u);
			u = fr[u];
		}
		path.push_back(u);
		reverse(path.begin(),path.end());
		for (auto x : path) cout << x << ' ';
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here
	freopen("BN.INP", "r", stdin);
	freopen("BN.OUT", "w", stdout);
	init();
	bellman_ford();
}