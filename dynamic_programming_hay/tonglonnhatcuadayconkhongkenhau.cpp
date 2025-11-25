#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//data:
	//code here
	int t = 1; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n];
		for(int &x : a) cin >> x;
		int F[n];
		F[0] = a[0];
		F[1] = max(a[0],a[1]);
		for(int i = 2; i < n; i++){
			F[i] = max(F[i-1],F[i-2]+a[i]);
		}
		cout << F[n-1] << endl;
	}
}