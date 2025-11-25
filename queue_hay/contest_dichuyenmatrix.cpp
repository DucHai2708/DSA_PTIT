#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

int C[1111][1111], a[1111][1111], n, m;

void prepare(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	memset(C,-1,sizeof(C));
}

void solution(){
	queue<pair<int,int>> q; q.push({1,1}); C[1][1] = 0;
	int i, j;
	while(!q.empty()){
		pair<int,int> t = q.front(); q.pop();
		i = t.first; j = t.second;
		int x;
		//Down
		if(i + 1 <= n){
			x = fabs(a[i+1][j]-a[i][j]);
			if(i+x <= n && C[i+x][j] == -1){
				q.push({i+x,j});
				C[i+x][j] = C[i][j] + 1;
			}
		}
		//right
		if(j + 1 <= m){
			x = fabs(a[i][j+1]-a[i][j]);
			if(j + x <= m && C[i][j+x] == -1){
				q.push({i,j+x});
				C[i][j+x] = C[i][j] + 1;
			}
		}
		//rightdown
		if(i+1 <= n && j+1 <= m){
			x = fabs(a[i+1][j+1]-a[i][j]);
			if(i+x <= n && j+x <= m && C[i+x][j+x] == -1){
				q.push({i+x,j+x});
				C[i+x][j+x] = C[i][j] + 1;
			}
		}
		if(C[n][m] != -1) break;
	}
	cout << C[n][m] << endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//data:
	//code here
	int t = 1; cin >> t;
	while(t--){
		prepare();
		solution();
	}
}