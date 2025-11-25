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
		for(int i = 0; i < n; i++){
			F[i] = a[i];
			for(int j = 0; j < i; j++){
				if(a[i] > a[j]){
					F[i] = max(F[i],F[j]+a[i]); 
				}
			}
		}
		cout << *max_element(F,F+n) << endl;
	}
}