#include <bits/stdc++.h>
using namespace std;

int maxmid(int a[], int l, int m, int r){
	int left_max = -1e9, sum_left = 0;
	for(int i = m; i >= l; i--){
		sum_left += a[i];
		if(left_max < sum_left) left_max = sum_left;
	}
	int right_max = -1e9, sum_right = 0;
	for(int i = m+1; i <= r; i++){
		sum_right += a[i];	
		if(right_max < sum_right) right_max = sum_right;
	}
	return left_max + right_max;
}

int maxsubarr(int a[], int l, int r){
	if(l == r) return a[l];
	int m = (l+r)/2;
	return max(maxsubarr(a,l,m),max(maxsubarr(a,m+1,r),maxmid(a,l,m,r)));
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int &x : a) cin >> x;
		cout << maxsubarr(a,0,n-1) << endl;
	}
	
}