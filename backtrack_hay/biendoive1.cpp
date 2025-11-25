#include <bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// code here
	int T = 1; cin >> T;
	while(T--){
		int n;
		cin >> n;
		int ok = 1;
		queue<pair<int,int>> q;
		q.push({n,0});
		while(!q.empty() && ok){
			pair<int,int> p = q.front(); q.pop();
			if(p.first == 1){
				cout << p.second << endl;
				ok = 0;
			}
			else{
				if(p.first % 3 == 0){	
					q.push({p.first/3,p.second+1});
				}
				if(p.first % 2 == 0){
					q.push({p.first/2,p.second+1});
				}
				if(p.first > 1) q.push({p.first-1,p.second+1});
			}
		}
	}
}