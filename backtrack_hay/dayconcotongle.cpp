#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> result;

void Try(int start, int n, int s, vector<int> &a, vector<int> &v){
	if(s % 2 == 1){
		result.push_back(v);
	}
	for(int j = start; j <= n; j++){
		v.push_back(a[j]);
		s = s + a[j];
		Try(j+1,n,s,a,v);
		v.pop_back();
		s = s - a[j];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// code here
	int T = 1; cin >> T;
	while(T--){
		cin >> n; result.clear();
		vector<int> a(n+1), v;
		for(int i = 1; i <= n; i++) cin >> a[i];
		sort(a.begin()+1,a.end(), greater<int>());
		Try(1,n,0,a,v);
		sort(result.begin(),result.end());
		for(int i = 0; i < result.size(); i++){
			for(int j = 0; j < result[i].size(); j++){
				cout << result[i][j] << " ";
			}
			cout << endl;
		}
	}
}