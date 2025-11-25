#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

ll solve(int n){
    queue<string> q;
    q.push("9");
    while(!q.empty()){
        string s = q.front();
        ll tmp = stoll(s);
        if(tmp % n == 0){
            return tmp;
        }
        q.push(s + "0");
        q.push(s + "9");
        q.pop();
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    int t = 1; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << solve(n) << endl;
    }
}