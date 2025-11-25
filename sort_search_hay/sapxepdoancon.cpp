#include <bits/stdc++.h>

//cpp06037

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		vector<int> left_max(n), right_min(n);
		left_max[0] = a[0]; right_min[n-1] = a[n-1];
		for(int i = 1; i < n; i++){
			left_max[i] = max(left_max[i-1],a[i]);
		}
		for(int i = n-2; i >= 0; i--){
			right_min[i] = min(right_min[i+1],a[i]);
		}
		vector<int> result;
		for(int i = 0; i < n-1; i++){
			if(left_max[i] <= right_min[i+1]){
				result.push_back(i+1);
			}
		}
		if(result.size()==0){
			cout << result.size() << endl << endl;
		}
		else{
			cout << result.size() << endl;
			for(auto element : result) cout << element << " ";
			cout << endl;
		}
	}
}