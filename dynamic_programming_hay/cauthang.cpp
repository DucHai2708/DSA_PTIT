#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int Mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//code here
	int t; cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		ll dp[n+1] = {0};
		dp[0] = 1; dp[1] = 1;
		for(int i = 2; i <= n; i++){
			for(int j = 1; j <= min(i,k); j++){
				dp[i] = (dp[i] + dp[i-j]) % Mod;
			}
		}
		cout << dp[n] % Mod << endl;
	}
}