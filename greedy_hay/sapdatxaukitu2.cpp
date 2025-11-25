#include <bits/stdc++.h>
using namespace std;

const int Mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//code here
	int t=1; cin >> t;
	while(t--){
		int d; string s;
		cin >> d >> s;
		int n = s.length();
		int cnt['Z'+1] = {0};
		for(auto x : s) ++cnt[x];
		int *maxfre = max_element(cnt,cnt+'Z');
		int tmp = n-*maxfre;
		if(tmp >= (d-1)*(*maxfre-1)) cout << 1 << endl;
		else cout << -1 << endl;
 	}
}