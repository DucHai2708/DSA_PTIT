#include <bits/stdc++.h>
using namespace std;

int n, a[20][20], X[20], OK[20], cost = 0, cmin = 1e9, XOPT[20], FOPT = 1e9;
vector<string> v(20);

void setup(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int dem = 0;
			string s1 = v[i], s2 = v[j];
			if(i == j) a[i][j] = 0;
			else{
				int cnt[256] = {0};
				for(int x : s1) ++cnt[x];
				for(int x : s2){
					if(cnt[x]){
						++dem;
					}
				}
				a[i][j] = dem;
				cmin = min(cmin,a[i][j]);
			}
		}
	}
}

void update(){
	if(cost < FOPT){
		FOPT = cost;
		for(int i = 1; i <= n; i++){
			XOPT[i] = X[i];
		}
	}
}


void Brand_and_Bound(int i){
	for(int j = 1; j <= n; j++){
		if(!OK[j]){
			X[i] = j; OK[j] = 1;
			cost = cost + a[X[i-1]][X[i]];
			if(i == n) update();
			else if(cost + (n-i)*cmin < FOPT){
				Brand_and_Bound(i+1);
			}
			OK[j] = 0;
			cost = cost - a[X[i-1]][X[i]];
		}
	}
}

void result(){
	cout << FOPT << endl;
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> v[i];
	}
	setup();
	Brand_and_Bound(1);
	result();
}