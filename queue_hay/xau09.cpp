#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //data:
    //code here
    int t = 1; cin >> t;
    while(t--){
        int n; cin >> n;
        queue<string> q;
        q.push("9");
        while(!q.empty()){
			string s = q.front();
			int x = stoi(s);
			if(x % n == 0){
				cout << x << endl;
				break;
			}
			q.pop();
			q.push(s + "0");
			q.push(s + "9");
		}
    }
}