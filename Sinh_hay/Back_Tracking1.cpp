#include <bits/stdc++.h>
using namespace std;

int x[100]; int n = 4;

void Try(int i){
    //Xây dựng bit thứ i cho xâu nhị phân
    for(int j = 0; j <= 1; j++){
        x[i] = j;
        if(i==n){
            for(int k = 1; k <= n; k++){
                cout << x[k];
            }
            cout << endl;
        }
        else{
            Try(i+1);
        }
    }
}

int main(){
    Try(1);
}