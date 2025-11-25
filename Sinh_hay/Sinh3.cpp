#include <bits/stdc++.h>
using namespace std;

int x[1001], n;
bool ok = true;

void Create(){
    for(int i = 1; i <= n; i++) x[i] = i;
}

void Result(){
    for(int i = 1; i <= n; i++) cout << x[i];
    cout << endl;
}

void Sinh(){
    int i = n-1;
    while(i > 0 && x[i] > x[i+1]){
        i--;
    }
    if(i > 0){
        int k = n;
        while(x[i] > x[k]){
            k--;
        }
        swap(x[i], x[k]);
        int l = i + 1, r = n;
        while(l < r){
            swap(x[l],x[r]);
            ++l; --r;
        }
    }
    else ok = false;
}


int main(){
    cin >> n;
    Create();
    while(ok){
        Result();
        Sinh();
    }
}