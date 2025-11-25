#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

int tinhgiatri(int a, int b, char c){
    if(c == '+') return a+b;
    if(c == '-') return a-b;
    if(c == '*') return a*b;
    if(c == '/') return a/b;
}

int tinhhauto(string s){
    stack<int> st;
    for(int i = 0; i < s.length(); i++){
        if(isdigit(s[i])) st.push(s[i]-'0');
        else{
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int res = tinhgiatri(a,b,s[i]);
            st.push(res);
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
        int kq = tinhhauto(s);
        cout << kq << endl;
    }
}