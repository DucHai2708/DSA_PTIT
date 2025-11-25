#include <bits/stdc++.h>
using namespace std;

const int Mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//code here
	int t=1; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n];
		priority_queue<int, vector<int>, greater<int>> pq;
		for(int &x : a){
			cin >> x;
			pq.push(x);
		}
		long long ans = 0;
		while(pq.size() > 1){
			long long top1 = pq.top(); pq.pop();
			long long top2 = pq.top(); pq.pop();
			long long top = top1 + top2;
			ans += top;
			pq.push(top);
		}
		cout << ans << endl;
	}
}