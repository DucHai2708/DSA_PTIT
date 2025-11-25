#include <bits/stdc++.h>

using namespace std;

int n, X[25];

void in(int m){
	cout << "(";
	for(int i = 1; i <= m-1; i++){
		cout << X[i] << " ";
	}
	cout << X[m] << ")";
	cout << " ";
}

void Try(int i, int x, int s){
	for(int j = x; j >= 1; j--){
		X[i] = j;
		if(j == s){
			in(i);
		}
		else if(j < s) Try(i+1,j,s-j);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// code here
	int T = 1; cin >> T;
	while(T--){
		cin >> n;
		Try(1,n,n);
		cout << endl;
	}
}