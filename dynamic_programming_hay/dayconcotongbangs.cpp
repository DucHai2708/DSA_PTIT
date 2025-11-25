#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//code here
	int t = 1; cin >> t;
	while(t--){
		int n, s;
		cin >> n >> s;
		vector<int> arr(n);
		for(int i = 0; i < n; i++) cin >> arr[i];
		vector<bool> dp(s+1,false);
		dp[0] = true;
		for(int i = 0; i < n; i++){
			for(int sum = s; sum >= arr[i]; sum--){
				if(dp[sum-arr[i]]) dp[sum] = true;
			}
		}
		if(dp[s]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}