#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

string s; vector<string> v; int n;

ll calc(ll a, ll b, char c) {
	if(c == '+') return a+b;
	else if(c == '-') return a-b;
	else if(c == '*') return a*b;
	else return a/b;
}

ll to_num(string a) {
	int dau = 0;
	if (a[0] == '-') dau = 1;
	ll res = 0;
	for (int i = dau; i < a.length(); i++) { 
		res = res * 10 + (a[i]-'0');
	}
	if (dau) return res*(-1);
	return res;
}

ll hauto() {
	stack<ll> st; ll kq = 0;
	for (int i = 0; i < n; i++) {
		if (isdigit(v[i][0]) || v[i].length() > 1) {
			ll x = to_num(v[i]);
			st.push(x);
		}
		else {
			ll a = st.top(); st.pop();
			ll b = st.top(); st.pop();
			ll x = calc(b,a,v[i][0]);
			st.push(x);
		}
	}
	return st.top();
}

ll tiento() {
	stack<ll> st; ll kq = 0;
	for (int i = n-1; i >= 0; i--) {
		if (isdigit(v[i][0]) || v[i].length() > 1) {
			ll x = to_num(v[i]);
			st.push(x);
		}
		else {
			ll a = st.top(); st.pop();
			ll b = st.top(); st.pop();
			ll x = calc(a,b,v[i][0]);
			st.push(x);
		}
	}
	return st.top();	 
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//data:
	//code here
	int t = 1; cin >> t; 
	while (t--){
		cin >> n; v.clear();
		string tmp;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			v.push_back(tmp);
		}
		if (v[0].size() > 1 || isdigit(v[0][0])) {
			cout << hauto() << '\n';
		}
		else cout << tiento() << '\n';
	}
}