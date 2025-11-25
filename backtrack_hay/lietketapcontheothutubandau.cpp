#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int Mod = 1e9+7;

vector<vector<int>> result;

int n, k;

void Backtrack(int start, int k, vector<int> &a, vector<int> &v) {
	if (v.size() == k) {
		result.push_back(v);
		return;
	}
	for (int i = start; i < n; i++) {
		v.push_back(a[i]);
		Backtrack(i+1,k,a,v);
		v.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here
	int tc = 1; 
	while (tc--) {
		cin >> n >> k;
		vector<int> a(n), v;
		for (int i = 0; i < n; i++) cin >> a[i];
		Backtrack(0,k,a,v);
		int len = result.size();
		vector<string> ans(len);
		for (int i = 0; i < len; i++) {
			ans[i] = "";
			for (int j = 0; j < k; j++) {
				ans[i] += to_string(result[i][j]);
			}
		}
		set<string> se;
		for (int i = 0; i < len; i++) se.insert(ans[i]);
		for (auto str : se) cout << str << '\n';
	}
}