#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

/*
Duyệt từ cuối về đầu.
Nếu gặp chữ cái thì đẩy vào ngăn xếp.
Nếu gặp dấu thì tạo phép toán trung tố với 2 phần tử đầu stack rồi đẩy trở lại vào ngăn xếp
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
			string str = "(" + a + s[i] + b + ")";
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