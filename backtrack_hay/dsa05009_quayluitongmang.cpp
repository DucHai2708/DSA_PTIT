#include <bits/stdc++.h>

using namespace std;

int n, sumArr;
int a[105];
bool ok = false;

void Try(int i, int sum){
	if(i == n) return;
	if(sum = sumArr/2 || ok == true){
		ok = true;
		return;
	}
	if(sum + a[i] <= sumArr/2){
		Try(i+1,sum+a[i]);
	}
	Try(i+1,sum);
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		cin >> n;
		sumArr = 0;
		ok = false;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			sumArr += a[i];
		}
		if(sumArr % 2 == 0) Try(0,0);
		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
}