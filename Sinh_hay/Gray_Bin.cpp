#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

string toGray(string s){
    string ans = s;
    for(int i = 1; i < s.length(); i++){
        if(s[i] == s[i-1]) ans[i] = '0';
        else ans[i] = '1';
    } 
    return ans;
}

string toBin(string s){
    string ans = s;
    for(int i = 1; i < s.length(); i++){
        if(s[i] == ans[i-1]) ans[i] = '0';
        else ans[i] = '1';
    }
    return ans;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    int t = 1; cin >> t;
    while(t--){
        string s; cin >> s;
        cout << toBin(s) << endl;

    }
}