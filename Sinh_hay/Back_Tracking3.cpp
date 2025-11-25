#include <bits/stdc++.h>
using namespace std;

int x[100], n;
bool used[100];

void Try(int i){
    for(int j = 1; j <= n; j++){
        if(used[j]==false){
            x[i] = j;
            used[j] = true;
            if(i==n){
                for(int i = 1; i <= n; i++) cout << x[i];
                cout << endl;
            }
            else Try(i+1);
            used[j] = false;
        }
    }
}

int main(){
    cin >> n;
    Try(1);
}