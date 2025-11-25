#include <bits/stdc++.h>
using namespace std;

int x[100], n;
bool Column[100], Diagonal_1[100], Diagonal_2[100];

int a[100][100];

int cnt = 0;

void Result(){
    for(int i = 1; i <= n; i++){
        a[i][x[i]] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void Try(int i){
    for(int j = 1; j <= n; j++){
        if(Column[j] == false && Diagonal_1[i-j+n]==false && Diagonal_2[i+j-1]==false){
            x[i] = j;
            Column[j] = true; Diagonal_1[i-j+n] = true; Diagonal_2[i+j-1] = true;
            if(i==n){
                Result();
                ++cnt;
            }
            else Try(i+1);
            //back_track
            Column[j] = false; Diagonal_1[i-j+n] = false; Diagonal_2[i+j-1] = false;
        }
    }
}

int main(){
    cin >> n;
    Try(1);
    cout << "Số cách xếp n quân hậu vào bàn cờ là: " << cnt << endl;
}