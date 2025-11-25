#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int Mod = 1e9+7;

/*
greedy: Ưu tiên duyệt các đỉnh ngọn trước rổi mới duyệt đỉnh còn dư
	Thêm 1 mảng đánh dấu các đỉnh là ngọn của đường đi (deleted) -> đánh dấu các đính khác là đã xóa
---> Duyệt từ đỉnh 1 đến n rồi dfs các đỉnh ngọn ->> mỗi lần dfs thì tăng thêm 1 lần duyệt
---> sau khi duyệt đỉnh ngọn, thì ta dfs các đỉnh còn lại mà chưa được đánh dấu
*/

vector<int> List[1671];
int visited[1671], deleted[1671];

void DFS(int u) {
	visited[u] = 1;
	for (int v : List[u]) {
		if (!visited[v]) {
			DFS(v);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here
	int tc = 1; 
	while (tc--) {
		int n, m; cin >> n >> m;
		int x, y;
		for (int i = 1; i <= m; i++) {
			cin >> x >> y;
			List[x].push_back(y);
		}
		//Đánh dấu các đỉnh không phải ở ngọn là đã xóa 
		for (int i = 1; i <= n; i++) {
			for (int j : List[i]) {
				deleted[j] = 1;
			}
		}
		// duyệt các đỉnh ngọn
		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (!deleted[i]) {
				DFS(i);
				++res;
			}
		}
		// duyệt các đỉnh còn lại
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				DFS(i);
				++res;
			}
		}
		cout << res << '\n';
	}	
}