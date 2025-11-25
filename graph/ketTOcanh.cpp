#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//data:
	//code here
	int t = 1;
	while(t--){
		int n; cin >> n; cin.ignore();
		vector<vector<int>> list(n+1);
		for(int i = 1; i <= n; i++){
			string s; getline(cin,s);
			stringstream ss(s);
			string token;
			while(ss >> token){
				int x = stoi(token);
				if(x > i) list[i].push_back(x);
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < list[i].size(); j++){
				cout << i << " " << list[i][j] << endl;
			}
		}
	}
}