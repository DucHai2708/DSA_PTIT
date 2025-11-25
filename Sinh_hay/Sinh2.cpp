#include <bits/stdc++.h>
using namespace std;

int x[1001], n, k;
bool ok = true;

void Create(){
    for(int i = 1; i <= k; i++) x[i] = i;
}

void Result(){
    for(int i = 1; i <= k; i++) cout << x[i];
    cout << endl;
}

void Sinh(){
    int i = k;
    while(i > 0 && x[i] == n - k + i){
        i--;
    }
    if(i > 0){
        x[i] = x[i] + 1;
        for(int j = i + 1; j <= k; j++){
            x[j] = x[i] + j - i;
        }
    }
    else ok = false;
}

int main(){
    cin >> n >> k;
    Create();
    while(ok){
        Result();
        Sinh();
    }
}