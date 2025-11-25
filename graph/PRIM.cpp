#include <bits/stdc++.h>
#define fi first 
#define se second 
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

struct canh {
	int dau, cuoi, ts;
};

int n, s, a[105][105], vs[105];
vector<pair<int,int>> List[105];
vector<canh> T;

void init() {
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j] > 0 && a[i][j] <= 50) List[i].push_back({j,a[i][j]});
		}
	}
	memset(vs,0,sizeof(vs));
}

void prim(int u) {
	int res = 0;
	vs[u] = 1;
	int x, y;
	while (T.size() < n-1) {
		int min_w = INT_MAX;
		for (int i = 1; i <= n; i++) {
			if (vs[i]) {
				for (pair<int,int> p : List[i]) {
					int t = p.fi, w = p.se;
					if (!vs[t] && w < min_w) {
						min_w = w;
						x = i; y = t;
					}
				}
			}
		}
		res = res + min_w;
		T.push_back({x,y,min_w});
		vs[y] = 1;
	}
	if (res == 0) cout << 0;
	else {
		cout << res << '\n';
		for (auto x : T) {
			cout << min(x.dau,x.cuoi) << ' ' << max(x.dau,x.cuoi) << ' ' << x.ts << '\n';
		}
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// freopen("CK.INP", "r", stdin);
	// freopen("CK.OUT", "w", stdout);
	//code here
	init();
	prim(s);
} 