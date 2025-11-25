#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int Mod = 1e9+7;


int n, s, a[67], visited[67], kq = 0;

void backtrack(int i, int sum) {
	if (sum == s && i > 1) {
		++kq; 
	}
	for (int j = i; j <= n; j++) {
		if (sum + a[j] <= s) {
			backtrack(j+1, sum + a[j]);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here
	int tc = 1; 
	while (tc--) {
		cin >> n >> s;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		backtrack(1,0);
		cout << kq << '\n';
	}
}