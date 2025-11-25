#include <bits/stdc++.h>

/*
Loại bỏ những đoạn dấu ngoặc hợp lệ
Mỗi 1 cặp (( hoặc )) sẽ có 1 cách
==> Chia đôi số lượng ) và (
*/
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

int solve(string s){
	stack<char> st; 
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '(' || st.empty()) st.push(s[i]);//Cách duyệt stack không bỏ đi dấu ) khi xh ở đầu
		else{
			if(!st.empty()){
				if(st.top() == '(') st.pop(); // Triệt tiêu dấu thỏa mãn ( )
				else st.push(s[i]);
			}
		}
	}
	int size = st.size();
	int n = 0;
	while(!st.empty() && st.top() == '('){
		++n; st.pop();
	}
	int m = size-n;
	int ans = 0;
	if(n % 2) ans += (n/2) + 1 + (m/2) + 1;
	else ans += n/2 + m/2;
	return ans;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here
	int t = 1; cin >> t;
	while(t--){
		string s; cin >> s;
		cout << solve(s);
		cout << endl;
	}
}