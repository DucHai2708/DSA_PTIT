#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

int n, k, x, solt = 0, arr[104], a[104][104], visited[104], truoc[104];
vector<vector<int>> result;

void init(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> k;
		while(k--){
			cin >> x;
			a[i][x] = 1;
		}
	}
}

void reset(){
	memset(visited,0,sizeof(visited));
}

void DFS(int s){
	visited[s] = 1;
	for(int t = 1; t <= n; t++){
		if(a[s][t] && !visited[t]){
			DFS(t);
		}
	}
}

void DuyetTru(){
	vector<int> kq;
	for(int u = 1; u <= n; u++){
		visited[u] = 1;
		if(u == 1) DFS(2);
		else DFS(1); int ok = 0;
		for(int i = 1; i <= n; i++){
			if(!visited[i]){
				ok = 1;
				break;
			}
		}
		if(ok){
			kq.push_back(u);
		}
		reset();
	}
	if(!kq.empty()){
		cout << kq.size() << endl;
		for(auto x : kq) cout << x << " ";
	}
}


 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here
	init();
	DuyetTru();
}