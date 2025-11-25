#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int Mod = 1e9+7;

int n, m, C[1006][1006];

void Floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (C[i][j] > C[i][k] + C[k][j]) {
					C[i][j] = C[i][k] + C[k][j];
				}
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here:
	int tc = 1;
	while (tc--) {
		cin >> n >> m;
		int u, v, w;
		for (int i = 1; i <= 1000; i++) {
			for (int j = 1; j <= 1000; j++) {
				C[i][j] = 1e9;
			}
			C[i][i] = 0;
		}
		for (int i = 1; i <= m; i++) {
			cin >> u >> v >> w;
			C[u][v] = C[v][u] = w;
		}
		Floyd();
		int qq, x, y;
		cin >> qq;
		while (qq--) {
			cin >> x >> y;
			cout << C[x][y] << '\n';
		}
	}
}