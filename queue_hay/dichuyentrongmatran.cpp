#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

 
int a[1167][1167];
int C[1167][1167];
int n, m;

void init(){
	cin >> m >> n;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	memset(C,-1,sizeof(C));
}

void solve(){
	queue<pair<int,int>> q;
	q.push({1,1}); C[1][1] = 0;
	int i,j; pair<int,int> t;
	while(!q.empty()){
		t = q.front(); q.pop();
		i = t.first; j = t.second;
		int x = a[i][j];
		if(i + x <= m && C[i+x][j] == -1){
			q.push({i+x,j});
			C[i+x][j] = C[i][j] + 1;
		}
		if(j + x <= n && C[i][j+x] == -1){
			q.push({i,j+x});
			C[i][j+x] = C[i][j] + 1;
		}
		if(C[m][n] != -1) break;
	}
	cout << C[m][n] << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//data:
	//code here
	int t = 1; cin >> t;
	while(t--){
		init();
		solve();
	}
}