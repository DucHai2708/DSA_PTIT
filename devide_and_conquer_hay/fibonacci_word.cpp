#include <bits/stdc++.h>
using namespace std;

const int Mod = 1e9+7;

long long fibo_word[100];

void fibo(){
	fibo_word[0] = 0; fibo_word[1] = 1;
	for(int i = 2; i <= 92; i++){
		fibo_word[i] = fibo_word[i-1] + fibo_word[i-2];
	}
}

char Try(int i, long long k){
	if(i == 1) return 'A';
	if(i == 2) return 'B';
	if(k <= fibo_word[i-2]) return Try(i-2,k);
	return Try(i-1,k-fibo_word[i-2]);
}

int main(){
	fibo();
	int n, k;
	cin >> n >> k;
	cout << Try(n,k);
}