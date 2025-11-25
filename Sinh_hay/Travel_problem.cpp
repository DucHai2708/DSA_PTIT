#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
bool used[MAX];
int C[MAX][MAX], A[MAX], XOPT[MAX];
int n, cost = 0, c_min = 1e9 , FOPT = 1e9;

void Init(){
    cout << "Nhập số con đường: ";
    cin >> n;
    cout << "Nhập ma trận chi phí: " << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> C[i][j];
            if(C[i][j] < c_min && i != j) c_min = C[i][j];
        }
    }
    A[1] = 1;
}

void Update(){
    int sum = cost + C[A[n]][A[1]];
    if(sum < FOPT){
        FOPT = sum;
        for(int i = 1; i <= n; i++){
            XOPT[i] = A[i];
        }
    }
}

void Result(){
    cout << "Chi phí tối ưu: " << FOPT << endl;
    cout << "Đường đi tối ưu: " << endl;
    for(int i = 1; i <= n; i++){
        cout << XOPT[i] << "->";
    }
    cout << 1 << endl;
}

void Try(int i){
    for(int j = 2; j <= n; j++){
        if(used[j] == false){
            A[i] = j; used[j] = true;
            cost = cost + C[A[i-1]][A[i]];
            if(i == n){
                Update();
            }
            else if(cost + (n - i + 1)*c_min < FOPT){
                Try(i+1);
            }
            used[j] = false;
            cost = cost - C[A[i-1]][A[i]];
        }
    }
}

int main(){
    Init();
    Try(2);
    Result();
}