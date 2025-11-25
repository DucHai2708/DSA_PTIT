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
        q.push("6"); q.push("8");
		vector<string> res;
        while(!q.empty()){
			string s = q.front();
			res.push_back(s);
			q.pop();
			if(s.size()+1 <= n){
				q.push(s + "6");
				q.push(s + "8");
			}
		}
		for(int i = res.size()-1; i >= 0; i--){
			cout << res[i] << " ";
		}
		cout << endl;
    }
}