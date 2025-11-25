#include <bits/stdc++.h>

using namespace std;

string answer = "";

void Try(int i, int n, string s){
	if(i == 1){
		s = "A";
	}
	if(i == n){
		answer = s;
		return;
	}
	if(i < n){
		Try(i+1,n,s + char(i+1+64) + s);
	}
}


int main(){
	int t; cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		string s = "";
		answer = "";
		Try(1,n,s);
		cout << answer[k-1] << endl;
	}
}