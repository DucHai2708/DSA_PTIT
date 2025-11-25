#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//code here
	int t = 1; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n];
		for(int &x : a) cin >> x;
		vector<int> Lis;
		for(int i = 0; i < n; i++){
			if(Lis.size() == 0 || Lis.back() < a[i]){
				Lis.push_back(a[i]);
			}
			else{
				auto it = lower_bound(Lis.begin(),Lis.end(),a[i]);
				*it = a[i];
			}
		}
		cout << Lis.size() << endl;
	}	
	return 0;
}