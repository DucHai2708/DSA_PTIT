#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

/*
 Tìm phân số đơn vị nhỏ nhất lớn hơn hoặc bằng phân số p có tử số là a và mẫu là b, tức là:
	1/n >= a/b --> n = ceil(b/a)
	in ra 1/n.
	Cập nhật lại phân số p = p - 1/n.
	LẶP LẠI CÁC BƯỚC CHO ĐẾN KHI TỬ SỐ CỦA P BẰNG 1.
*/

struct PhanSo{
	ll tu, mau;
};

typedef PhanSo PhanSo;

PhanSo rutgon(PhanSo &a){
	ll uc = __gcd(a.tu,a.mau);
	a.tu /= uc;
	a.mau /= uc;
	return a;
}

PhanSo operator- (PhanSo a, PhanSo b){
	PhanSo c;
	c.tu = a.tu*b.mau - b.tu*a.mau;
	c.mau = a.mau*b.mau;
	return c;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here
	int t = 1; cin >> t;
	while(t--){
		ll a, b;
		cin >> a >> b;
		PhanSo p;
		p.tu = a; p.mau = b;
		rutgon(p);
		if(a == 1){
			cout << p.tu << "/" << p.mau << endl;
			continue;
		}
		while(p.tu >= 1){
			ll x = ceil((double)p.mau / p.tu);
			PhanSo tmp;
			tmp.tu = 1; tmp.mau = x;
			cout << tmp.tu << "/" << tmp.mau;
			if(p.tu>1) cout << " + ";
			p = p - tmp;
			rutgon(p);
		}
		cout << endl;
	}
}