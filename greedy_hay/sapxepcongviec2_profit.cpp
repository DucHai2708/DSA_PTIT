#include <bits/stdc++.h>
#include <numeric>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

struct task{
	int job, deadline, profit;
} C[1134];

typedef struct task task;

bool cmp(task a, task b){
	return a.profit > b.profit;
}

void Sort(task a[], int n){
	sort(a,a+n,cmp);
}

int n, Time[1134];
 
void init(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> C[i].job >> C[i].deadline >> C[i].profit;
	}
	memset(Time,0,sizeof(Time));
	sort(C,C+n,cmp);
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here
	int t = 1; cin >> t;
	while(t--){
		init();
		vector<int> coin;
		coin.push_back(C[0].profit);
		Time[C[0].deadline] = 1;
		int timemax = C[0].deadline;
		for(int i = 1; i < n; i++){
			if(C[i].deadline <= timemax){
				for(int j = C[i].deadline; j >= 1; j--){
					if(!Time[j]){
						Time[j] = 1;
						coin.push_back(C[i].profit);
						break;
					}
				}
			}
			else{
				timemax = C[i].deadline;
				Time[C[i].deadline] = 1;
				coin.push_back(C[i].profit);
			}
		}
		int max_profit = accumulate(coin.begin(),coin.end(),0);
		cout << coin.size() << " " << max_profit << endl;
	}
}