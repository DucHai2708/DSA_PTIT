#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

/*
Duyệt từ đầu đến cuối đẩy những kí tự khác ')' vào stack.
Sau khi gặp kí tự ')' thì duyệt stack cho tới dấu ngoặc '(' gần ')' vừa gặp nhất 
-> tức là xét biểu thức chứa ngoặc đầu tiên
Nếu bên trong dấu ngoặc có ít nhất 1 kí tự là phép tính => có biểu thức => dấu ngoặc này là hợp lí
Nếu không có tức là ở dạng (a) => thừa dấu ngoặc
*/
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here
	int t = 1; cin >> t; cin.ignore();
	while(t--){
		string s; getline(cin,s);
		stack<char> st;
		int tool = 1;
		for(int i = 0; i < s.length(); i++){
			if(s[i] != ')') st.push(s[i]);
			else{
				int ok = 0;
				while(!st.empty()){
					char c = st.top(); st.pop();
					if(c == '+' || c == '-' || c == '*' || c == '/'){
						ok = 1;
					}
					if(c == '(') break;
				}
				if(!ok){
					cout << "Yes" << endl;
					tool = 0;
					break;
				}
			}
		}
		if(tool) cout << "No" << endl;
	}
}