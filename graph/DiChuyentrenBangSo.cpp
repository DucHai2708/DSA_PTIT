#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int Mod = 1e9+7;

// D[i][j] luu kc min t? 1,1 d?n i,j

int n, m, D[671][671], A[671][671];
vector<pair<pair<int,int>,int>> List[1671];
priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, greater<pair<pair<int,int>,int>>> q;


const int dx[4] = {-1,0,0,1};
const int dy[4] = {0,-1,1,0};

int check(int x, int y) {
	return (x <= n && y <= m && x >= 1 && y >= 1);
}

void Dijiktra() {
	D[1][1] = A[1][1];
	while (!q.empty()) q.pop();
	q.push({{1,1},D[1][1]});
	while (!q.empty()) {
		pair<int,int> p = q.top().first;
		int u = p.first, v = p.second, w = q.top().second; // w: kc t? 1,1 d?n u,v
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = u + dx[i], y = v + dy[i];
			if(check(x,y)) {
				if (D[x][y] > w + A[x][y]) {
					D[x][y] = w + A[x][y];
					q.push({{x,y},D[x][y]});
				}
			}
		}	
	}
	cout << D[n][m] << '\n';
} 


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here:
	int tc = 1; cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> A[i][j];
			}
		}
		memset(D,11,sizeof(D));
		Dijiktra();
	}
}