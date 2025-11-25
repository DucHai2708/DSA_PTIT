#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

/*
Áp dụng dãy cách duyệt kiểm tra dấu ngoặc thừa

Tạo 2 stack để lưu số nguyên và lưu kí tự.
stack<int> lưu số nguyên. stack<char> lưu '[' và chữ cái.
DUYỆT TỪ ĐẦU ĐẾN CUỐI

B1: Nếu gặp số thì đẩy số ấy vào stack<int>. Nếu gặp '[' hoặc chữ cái thì đẩy vào stack<char>
B2: Nếu gặp dấu ngoặc đóng ']' ta lần lượt pop hết kí tự trong stack<char> cho đến ghi gặp '['. 
	Sau đó tạo ra 1 xâu nối các kí tự lại. Tiếp đến pop phần tử đầu tiên của stack<int> để
	lặp lại xâu vừa tạo n lần (n là đỉnh stack<int>). Rồi đẩy lại toàn bộ kí tự của xâu mới
	vào stack<char>
B3: Sau khi duyệt xong thì stack<int> rỗng và xâu cuối cùng ở stack<char> chính là kết quả

//NOTE: Nếu trước [] không có số nào thì ngầm hiểm là 1 =)))
*/
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here
	int t = 1; cin >> t;
	while(t--){
		string s; cin >> s;
		int n = s.length();
		stack<int> sti; stack<char> stc;
		for(int i = 0; i < n; i++){
			int number = 0; // Số ở trước ngoặc
			if(i < n && isdigit(s[i])){
				while(i < n && isdigit(s[i])){
					number = number * 10 + (s[i]-'0');
					i++;
				}
				i--;
				sti.push(number);
			}
			else if(s[i] == ']'){
				string str = ""; // Lưu xâu xử lí
				while(!stc.empty() && stc.top() != '['){
					str = stc.top() + str;
					stc.pop();
				}
				stc.pop(); // Xóa dấu '['
				int count;
				if(!sti.empty()){
					count = sti.top();
					sti.pop();
				} else count = 1;
				string res = "";
				while(count--){
					res += str;
				}
				for(int i = 0; i < res.length(); i++) stc.push(res[i]); // Đẩy các kí tự vừa tạo vào lại
			}
			else{
				stc.push(s[i]);
				if(s[i] == '[' && (i == 0 || !isdigit(s[i-1]))){
					sti.push(1);
				}
			}
		}
		string ans = "";
		while(!stc.empty()){
			ans = stc.top() + ans;
			stc.pop();
		}
		cout << ans << endl;
	}
}