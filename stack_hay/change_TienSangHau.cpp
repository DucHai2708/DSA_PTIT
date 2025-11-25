#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

/*
Duyệt từ cuối về.
Gặp chữ cái thì đẩy vào
Gặp dấu thì lấy 2 phần tử ra tạo phép hậu tố rồi đẩy vào
*/

void solve(string s){
	stack<string> st; int n = s.length();
	for(int i = n-1; i >= 0; i--){
		if(isalpha(s[i])){
			string tmp = ""; tmp += s[i];
			st.push(tmp);
		}
		else{
			string a = st.top(); st.pop();
			string b = st.top(); st.pop();
			string str = a + b + s[i];
			st.push(str);
		}
	}
	cout << st.top();
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