#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll multiples(ll x, ll y){
	if(x < 10 ||  y < 10){
		return x*y;
	}
	int n = max(to_string(x).size(),to_string(y).size());
	int m = n / 2;
	ll a = x / pow(10,m);
	ll b = x % (ll)pow(10,m);
	ll c = y / pow(10,m);
	ll d = y % (ll)pow(10,m);
	
	ll ac = multiples(a,c);
	ll bd = multiples(b,d);
	ll p = multiples(a+b,c+d);
	
	return ac*pow(10,2*m) + (p-ac-bd)*pow(10,m) + bd;
}



int main(){
	long long x = 1234567890123456789;
    long long y = 9876543210987654321;
    cout << multiples(x,y);
}