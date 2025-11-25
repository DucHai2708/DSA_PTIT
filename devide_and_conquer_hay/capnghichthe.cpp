#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

/*
Ý tưởng sử dụng merge_sort.
Chia ra thành 2 dãy rồi tìm kiếm
Nếu phần tử bên dãy trái lớn hơn bên phải thì tất cả phần tử thuộc dãy trái ở phía sau phần tử ấy cũng
sẽ lớn hơn => Với mỗi vị trí i thỏa mãn thì sẽ có n1-i trường hợp thỏa mãn
*/

ll solve(ll a[], int l, int m, int r){
	int n1 = m-l+1, n2 = r-m;
	ll x[n1], y[n2];
	for(int i = 0; i < n1; i++) x[i] = a[i+l];
	for(int i = 0; i < n2; i++) y[i] = a[i+m+1];
	int i = 0, j = 0, index = l;
	ll kq = 0;
	while(i < n1 && j < n2){
		if(x[i] <= y[j]) a[index++] = x[i++];
		else{
			kq = kq + n1 - i;
			a[index++] = y[j++];
		}
	}
	while(i < n1) a[index++] = x[i++];
	while(j < n2) a[index++] = y[j++];
	return kq;
}

ll Try(ll a[], int l, int r){
	ll kq = 0;
	if(l < r){
		int m = (l+r)/2;
		kq = kq + Try(a,l,m);
		kq = kq + Try(a,m+1,r);
		kq = kq + solve(a,l,m,r);
	}
	return kq;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//data:
	//code here
	int t = 1; cin >> t;
	while(t--){
		int n; cin >> n;
		ll a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		cout << Try(a,0,n-1) << endl;
	}
}