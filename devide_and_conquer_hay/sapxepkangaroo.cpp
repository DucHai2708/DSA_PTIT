#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

/*
Sắp xếp tăng dần rồi chia đôi dãy ra
Duyệt từ cuối của dãy bên trái rồi tìm phần tử đầu tiên >= 2*x 
note: mỗi lần chọn đc 1 cặp thì gộp 2 con là 1 -> trừ đi 1 phần tử
--> Mid in the middle
*/

ll Try(vector<int> &v, int l, int m, int r){
	int n1 = m-l+1, n2 = r-m;
	vector<int> v1(n1), v2(n2);
	for(int i = 0; i < n1; i++) v1[i] = v[i+l];
	for(int i = 0; i < n2; i++) v2[i] = v[i+m+1];
	ll kq = v.size();
	int i = n1-1;
	while(i >= 0){
		auto it = lower_bound(v2.begin(),v2.end(),2*v1[i]);
		if(it != v2.end()){
			--kq;
			v1.erase(v1.begin()+i);
			v2.erase(it);
		}
		--i;
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
		vector<int> v;
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		cout << Try(v,0,(n-1)/2,n-1) << endl;
	}
}