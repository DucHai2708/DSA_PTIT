#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
	return a.first < b.first;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<pair<int,int>> v;
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			v.push_back({x,i});
		}
		sort(v.begin(),v.end(),cmp);
		int i = v[0].second;
		int res = -1e9;
		for(int t = 1; t < n; t++){
			if(v[t].second > i){
				res = max(res,v[t].second-i);
			}
			i = min(i,v[t].second);
		}
		if(res == -1e9) cout << -1 << endl;
		else cout << res << endl;
	}
}