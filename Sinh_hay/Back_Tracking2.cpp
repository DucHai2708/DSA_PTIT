#include <bits/stdc++.h>
using namespace std;

int x[100]; int n, k;

void Try(int i){
    for(int j = x[i-1]+1; j <= n-k+i; j++){
        x[i] = j;
        if(i == k){
            for(int z = 1; z <= k; z++){
                cout << x[z];
            }
            cout << endl;
        }
        else Try(i+1);
    }
}

int main(){
    cin >> n >> k;
    Try(1);
}