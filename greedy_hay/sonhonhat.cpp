#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here
	int t = 1; cin >> t;
	while(t--){
		int s, d;
		cin >> s >> d;
		if(s > 9 * d || s == 0){
			cout << -1 << endl;
		}
		else{
			--s;
			string ans = "";
			for(int i = d-1; i >= 0; i--){
				if(s > 9){
					ans = to_string(9) + ans;
					s -= 9;
				}
				else{
					ans = to_string(s) + ans;
					s = 0;
				}
			}
			int tmp = ans[0]-'0';
			++tmp;
			ans[0] = tmp + '0';
			cout << ans << endl;
		}
	}
}