#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const long long Mod = 1e9+7;

int n, k;

struct Matran{
	ll F[25][25];
};

typedef struct Matran Matran;

Matran operator*(Matran A, Matran B){
	Matran C;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			C.F[i][j] = 0;
			for(int k = 0; k < n; k++){
				C.F[i][j] = (C.F[i][j] + (A.F[i][k]*B.F[k][j]) % Mod) % Mod;
			}
		}
	}
	return C;
}

Matran bin_pow(Matran A, int r){
	if(r == 1) return A;
	Matran X = bin_pow(A,r/2);
	X = (X*X);
	if(r % 2 == 0) return X;
	return (A*X);
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		Matran A;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> A.F[i][j];
			}
		}
		Matran B = bin_pow(A,k);
		ll ans = 0;
		for(int i = 0; i < n; i++){
			ans = (ans + B.F[i][n-1]) % Mod;
		}
		cout << ans % Mod << endl;
	}
}


