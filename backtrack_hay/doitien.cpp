#include <bits/stdc++.h>

//ap dung day con co tong bang s
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

int n, s, ans = INT_MAX;
vector<int> t(34), v;
vector<vector<int>> result;

void Try(int i, int sum, int cnt){
	if(sum > s || cnt > ans) return;
	if(i == n - 1){
		if(sum == s){
			ans = min(ans,cnt);
		}
		return;
	}
	Try(i+1,sum + t[i], cnt+1);
	Try(i+1,sum,cnt);
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here
	int x = 1;
	while(x--){
		cin >> n >> s;
		for(int i = 0; i < n; i++) cin >> t[i];
		sort(t.begin(),t.end(),greater<int>());
		Try(0,0,0);
		if(ans == INT_MAX) cout << -1;
		else cout << ans;
	}
}