#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int Mod = 1e9+7;

ll F[167], len[167];

void Fibo() {
	F[0] = 1; F[1] = 1;
	len[0] = 1; len[1] = 0;
	for (int i = 2; i <= 92; i++) {
		len[i] = len[i-1] + len[i-2];
		F[i] = F[i-1] + F[i-2];
	}
}

int dvd (int n, int k) {
	if (k == F[n]) return len[n];
	if (k > F[n-1]) return len[n-1] + dvd (n-2,k-F[n-1]);
	else return dvd (n-1,k);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    int tc = 1; cin >> tc;
    Fibo();
    while (tc--) {
		int n, k; cin >> n >> k;
		cout << dvd (n,k) << '\n';
	}	
}
