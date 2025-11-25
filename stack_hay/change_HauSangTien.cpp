#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

/*
Duyệt từ đầu về cuối
Gặp chữ cái thì đẩy vào
Gặp dấu thì tạo phép tiền tố rồi đẩy vào
*/

void solve(string s){
    stack<string> st; int n = s.length();
    for(int i = 0; i < n; i++){
        if(isalpha(s[i])){
            string tmp = ""; tmp += s[i];
            st.push(tmp);
        }
        else{
            string b = st.top(); st.pop();
            string a = st.top(); st.pop();
            string str = s[i] + a + b;
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