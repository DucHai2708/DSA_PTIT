#include <bits/stdc++.h>
using namespace std;

int a[40], c[40], n, x, ok = 0;

void in(int m){
	cout << "[";
	for(int i = 1; i <= m; i++){
		if(i!=m) cout << c[i] << " ";
		else cout << c[i];
	}
	cout << "]";
}

void Try(int i, int s){
	for(int j = 1; j <= n; j++){
		if(a[j] >= c[i-1] && s + a[j] <= x){
			c[i] = a[j]; s += a[j];
			if(s == x){
				ok = 1; in(i);
			}
			else Try(i+1,s);
			s -= a[j];
		}
	}
}


int main(){
	int t; cin >> t;
	while(t--){
		cin >> n >> x;
		for(int i = 1; i <= n; i++) cin >> a[i];
		memset(c,0,sizeof(c));
		Try(1,0);
		if(!ok) cout << -1;
		cout << endl;
	}
}