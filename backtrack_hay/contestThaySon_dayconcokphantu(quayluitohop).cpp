#include <bits/stdc++.h>
using namespace std;

void Try(int start, int n, int k, vector<int> &a, vector<int> &result){
	if(result.size()==k){
		for(auto x : result) cout << x << " ";
		cout << endl;
		return;
	}
	for(int j = start; j <= n; j++){
		result.push_back(a[j]);
		Try(j+1,n,k,a,result);
		result.pop_back();
	}
}


int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n+1), result;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	Try(1,n,k,a,result);
}