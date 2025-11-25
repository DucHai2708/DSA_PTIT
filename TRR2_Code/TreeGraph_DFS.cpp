#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

struct Edge{
	int start, end;
} T[167];

typedef struct Edge Edge;

int n, a[167][167], chuaxet[167], m;

void prepare(){
	cin >> n; m = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	memset(chuaxet,0,sizeof(chuaxet));
}

void resultTree(){
	for(int i = 1; i <= m; i++){
		cout << "(" << T[i].start << "," << T[i].end << ")";
		cout << endl;
	}
}

void TreeDFS(int u){
	chuaxet[u] = 1;
	for (int v = 1; v <= n; v++) {
		if (a[u][v] && !chuaxet[v]) {
			++m;
			T[m].start = u;
			T[m].end = v;
			TreeDFS(v);
		}
	}
}

void solveProblem(){
	int u; cin >> u;
	TreeDFS(u);
	if(m < n-1){
		return;
	} 
	else{
		resultTree();
	}
}

 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//data:
	//code here
	int t = 1; 
	while(t--){
		prepare();
		solveProblem();
	}
}

/*
13
0 1 1 1 0 0 0 0 0 0 0 0 0
1 0 1 1 0 0 0 0 0 0 0 0 0
1 1 0 1 1 0 0 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0 0 0 0 0
0 0 1 0 0 1 1 1 1 0 0 0 0
0 0 0 0 1 0 1 0 1 0 0 0 0
0 0 0 0 1 1 0 1 0 0 0 0 0
0 0 0 0 1 0 1 0 1 0 0 0 0
0 0 0 0 1 1 0 1 0 1 0 0 0
0 0 0 0 0 0 0 0 1 0 1 1 1
0 0 0 0 0 0 0 0 0 1 0 1 1
0 0 0 0 0 0 0 0 0 1 1 0 1
0 0 0 0 0 0 0 0 0 1 1 1 0
1
*/