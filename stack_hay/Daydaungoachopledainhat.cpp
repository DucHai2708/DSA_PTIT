#include <bits/stdc++.h>

//https://www.geeksforgeeks.org/length-of-the-longest-valid-substring/

/*

*/
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here
	int t = 1; cin >> t;
	while(t--){
		string s; cin >> s;
		stack<int> st; //lưu mốc dấu ngoặc không hợp lệ để tính
		st.push(-1);
		int max_len = 0;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '(') st.push(i);
			else{
				st.pop();
				if(st.empty()){ 
					st.push(i); // cập nhật mốc tính mới
				}
				else{
					max_len = max(max_len,i-st.top()); // i-st.top() : Độ dài chuỗi hợp lệ tính từ mốc
				}
			}
		}
		cout << max_len << endl;
	}
} 