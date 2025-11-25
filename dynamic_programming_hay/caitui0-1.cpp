#include <bits/stdc++.h>
using namespace std;

int F[5005][5005], n, m, A[5005], C[5005];

int qhd(){
	int i, j;
	memset(F,0,sizeof(F));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			F[i][j] = F[i-1][j];
			if(j >= A[i]){
				F[i][j] = max(F[i][j],F[i-1][j-A[i]]+C[i]);
			}
		}
	}
	return F[n][m];
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	//code here
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		int x, y;
		cin >> x >> y;
		A[i] = x; C[i] = y;
	}
	cout << qhd();
}