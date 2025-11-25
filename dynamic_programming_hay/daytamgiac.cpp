#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int &x : a) cin >> x;
		vector<int> dp1(n,1), dp2(n,1);
		for(int i = 1; i < n; i++){
			if(a[i] > a[i-1]){
				dp1[i] = dp1[i-1] + 1;
			}
		}
		for(int i = n-2; i >= 0; i--){
			if(a[i] > a[i+1]){
				dp2[i] = dp2[i+1] + 1;
			}
		}
		long long ans = 0;
		for(int i = 0; i < n; i++){
			ans = max(ans,1ll*(dp1[i]+dp2[i]-1));
		}
		cout << ans << endl;
	}
}