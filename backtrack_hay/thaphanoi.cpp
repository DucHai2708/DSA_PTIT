#include <bits/stdc++.h>
using namespace std;

char C[3] = {'A', 'B', 'C'};

void toh(int n, int i, int j, int k ){
	if(n == 1){
		cout << C[i] << " -> " << C[j] << endl;
	}
	else{
		toh(n-1,i,k,j);
		cout << C[i] << " -> " << C[j] << endl;
		toh(n-1,k,j,i);
	}
}


int main(){
	int n; cin >> n;
	toh(n,0,2,1);
}