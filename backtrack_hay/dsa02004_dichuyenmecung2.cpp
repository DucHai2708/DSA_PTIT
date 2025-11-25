#include <bits/stdc++.h>

using namespace std;

vector<string> result;
int a[105][105], n;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
string str = "DURL";

void Try(int i, int j, string s){
	if(i == n && j == n){
		result.push_back(s);
		return;
	}
	for(int k = 0; k < 4; k++){
		int i1 = i + dx[k], j1 = j + dy[k];
		if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1] == 1){
			a[i1][j1] = 0;
			Try(i1,j1,s+str[k]);
			a[i1][j1] = 1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cin >> a[i][j];
			}
		}
		result.clear();
		if(a[1][1] == 0 || a[n][n] == 0){
			cout << -1 << endl;
			continue;
		}
		a[1][1] = 0;
		Try(1,1,"");
		if(result.size() == 0){
			cout << -1 << endl;
		}
		else{
			sort(result.begin(),result.end());
			for(auto x : result) cout << x << " ";
			cout << endl;
		}
	}
	
}