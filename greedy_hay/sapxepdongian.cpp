#include <bits/stdc++.h>
using namespace std;

const int Mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//code here
	int t = 1;
	while(t--){
		int n; cin >> n;
		int a[n];
		for(int &x : a) cin >> x;
		int dp[n+1] = {0}; int lis = 0;
		for(int i = 0; i < n; i++){
			dp[a[i]] = dp[a[i]-1] + 1;
			lis = max(lis,dp[a[i]]);
		}
		cout << n - lis;
	}
}