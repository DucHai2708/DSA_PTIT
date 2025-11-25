#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

int ut(char c){
	if(c == '^') return 4;
	if(c == '*' || c == '/') return 3;
	if(c == '+' || c == '-') return 2;
	return 1;
}

void solve(string s){
	stack<char> st; string ans = "";
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '(') st.push(s[i]);
		else if(s[i] == ')'){
			while(!st.empty() && st.top() != '('){
				ans += st.top();
				st.pop();
			}
			if(st.top() == '(') st.pop();
		}
		else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^'){
			while(!st.empty() && ut(st.top()) >= ut(s[i])){
				ans += st.top();
				st.pop();
			}
			st.push(s[i]); // Duy trì mức độ ưu tiên từ thấp đến cao trong stack
		}
		else ans += s[i];
	}
	while(!st.empty()){
		if(st.top() != '(') ans += st.top();
		st.pop();
	}
	cout << ans;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here
	int t = 1; cin >> t;
	while(t--){
		string s; cin >> s;
		solve(s);
		cout << endl;
	}
}