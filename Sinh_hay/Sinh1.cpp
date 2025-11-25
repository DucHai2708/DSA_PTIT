#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
int x[MAX], n;
bool OK = true;

void Init(){
    for(int i = 1; i <= n; i++) x[i] = 0;
}

void Result(){
    for(int i = 1; i <= n; i++) cout << x[i];
    cout << endl;
}

void Sinh(){
    int i = n;
    while(i > 0 && x[i] == 1){
        x[i] = 0;
        i--;
    }
    if(i > 0){
        x[i] = 1;
    }
    else OK = false;
}

int main(){
    cin >> n;
    while(OK){
        Result();
        Sinh();
    }
}