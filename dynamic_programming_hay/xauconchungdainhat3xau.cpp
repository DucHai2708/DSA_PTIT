#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

int dp[134][134][134];
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//data:
	//code here
	int t = 1; cin >> t;
	while(t--){
		int nx, ny, nz;
		cin >> nx >> ny >> nz;
		string x, y, z;
		cin >> x >> y >> z;
		memset(dp,0,sizeof(dp));
		for(int i = 1; i <= nx; i++){
			for(int j = 1; j <= ny; j++){
				for(int k = 1; k <= nz; k++){
					if(x[i-1] == y[j-1] && x[i-1] == z[k-1]){
						dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
					}
					else{
						dp[i][j][k] = max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
					}
				}
			}
		}
		cout << dp[nx][ny][nz] << endl;
	}
}