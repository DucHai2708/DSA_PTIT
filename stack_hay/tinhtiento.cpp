#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

int value(int a, int b, char c){
	if(c == '+') return a+b;
	if(c == '-') return a-b;
	if(c == '*') return a*b;
	if(c == '/') return a/b;
}

int fcal(string s){
	stack<int> st;
	for(int i = s.size()-1;  i >= 0; i--){
		if(isdigit(s[i])) st.push(s[i]-'0');
		else{
			int a = st.top(); st.pop();
			int b = st.top(); st.pop();
			int x = value(a,b,s[i]);
			st.push(x);
		}
	}
	return st.top();
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here
	int t = 1; cin >> t;
	while(t--){
		string s; cin >> s;
		cout << fcal(s) << endl;
	}
}