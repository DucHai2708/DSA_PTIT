#include <bits/stdc++.h>
using namespace std;

struct task{
	int start, finish;
} a[1005];

bool cmp(task a, task b){
	return a.finish < b.finish;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//code here	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i].start;
		for(int i = 0; i < n; i++) cin >> a[i].finish;
		sort(a,a+n,cmp);
		int dem = 1; int j = 0;
		for(int i = 1; i < n; i++){
			if(a[i].start >= a[j].finish){
				++dem; j = i;
			}
		}
		cout << dem << endl;
	}
	
	return 0;
}