#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

int n, u, v, solt = 0, a[104][104], visited[104], truoc[104];
vector<vector<int>> result;

void init(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
}

void DFS(int s, vector<int> &v){
	visited[s] = 1; v.push_back(s);
	for(int t = 1; t <= n; t++){
		if(a[s][t] && !visited[t]){
			DFS(t,v);
		}
	}
}

void TPLT(){
	for(int u = 1; u <= n; u++){
		if(!visited[u]){
			vector<int> v;
			++solt;
			DFS(u,v);
			result.push_back(v);
		}
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here
	init();
	TPLT();
	cout << solt << endl;
	sort(result.begin(),result.end());
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}