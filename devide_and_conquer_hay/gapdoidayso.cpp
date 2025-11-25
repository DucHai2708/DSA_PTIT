#include <bits/stdc++.h>
using namespace std;

long long F[105];

void prepare(){ // Khởi tạo độ dài dãy số thứ n
	F[1] = 1;
	for(int i = 2; i <= 100; i++){
		F[i] = 2*F[i-1]+1;
	}
}

int Try(long long n, long long k){
	if(n == 1) return 1;
	if(k == F[n-1]+1) return n; // Chính giữa
	if(k <= F[n-1]) return Try(n-1,k); // nửa trái
	return Try(n-1,k-F[n-1]-1); // nửa phảis
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	prepare();
	int t; cin >> t;
	while(t--){
		long long n, k;
		cin >> n >> k;	
		cout << Try(n,k) << endl;

	}
	return 0;
}