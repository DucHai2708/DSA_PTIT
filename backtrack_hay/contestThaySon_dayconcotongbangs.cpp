#include <bits/stdc++.h>
using namespace std;

int a[40], c[40], n, s, mini_size = 1e9;


void Try(int i, int start, int sum){
	for(int j = start; j <= n; j++){
		if(sum + a[j] <= s){
			c[i] = a[j]; sum += a[j];
			if(sum == s){
				mini_size = min(mini_size,i);
			}
			else Try(i+1,j+1,sum);
			sum -= a[j];
		}
	}
}

int main(){
	cin >> n >> s;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	Try(1,1,0);
	cout << mini_size;
	
}