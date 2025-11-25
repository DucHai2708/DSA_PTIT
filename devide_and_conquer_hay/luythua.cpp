#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

ll power(ll a, ll b){
	if(b == 1) return a % Mod;
	ll x = power(a,b/2);
	x = (x * x) % Mod;
	if(b % 2) return (a * x) % Mod;
	return x;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here
	int t = 1; cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		cout << power(n,k) << endl;
	}
}