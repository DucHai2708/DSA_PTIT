#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

/*
nPk = (n-1)Pk + k.(n-1)P(k-1)
*/

ll P[1671][1671];

void nPk(){
	for(int i = 0; i <= 1000; i++){
		for(int j = 0; j <= 1000; j++){
			if(i > j) P[i][j] = 0;
			else if(i == 0) P[i][j] = 1;
			else P[i][j] = (P[i][j-1] + (1ll*i*P[i-1][j-1])) % Mod;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//data:
	nPk();
	//code here
	int t = 1; cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		cout << P[k][n] << endl;
	}
}