#include <bits/stdc++.h>
using namespace std;

long long F[100];

void prepare(){
	F[1] = 1;
	for(int i = 2; i <= 100; i++){
		F[i] = 2*F[i-1]+1;
	}
}

char Try(long long n, long long k){
	if(n == 1) return 'A';
	if(k == F[n-1]+1) return char(n+64); 
	if(k <= F[n-1]) return Try(n-1,k);
	else return Try(n-1,k-F[n-1]-1); 
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//Code here
	prepare();
	int t; cin >> t;
	while(t--){
		long long n, k;
		cin >> n >> k;
		cout << Try(n,k) << endl;
	}
	
}