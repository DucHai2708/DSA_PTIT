#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int FOPT = -1e9;
int b, n, cost = 0, weight = 0;
int XOPT[MAX]; int X[MAX];
int A[MAX], C[MAX];

void Init(){
    cout << "Nhập số lượng đồ vật: "; cin >> n;
    cout << "Nhập trọng lượng của túi: "; cin >> b;
    cout << "Vector giá trị của đồ vật: ";
    for(int i = 1; i <= n; i++){
        cin >> C[i];
    }
    cout << "Vector trọng lượng của đồ vật: ";
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }
}

void Update(){
    if(cost > FOPT){
        FOPT = cost;
        for(int i = 1; i <= n; i++){
            XOPT[i] = X[i];
        }
    }
}

void Result(){ 
    cout << "Kết quả tối ưu: " << FOPT << endl;
    cout << "Phương án tối ưu: ";
    for(int i = 1; i <= n; i++){
        cout << XOPT[i] << " ";
    }
}

void Branch_and_Bound(int i){
    int t = (b - weight) / A[i];
    for(int j = t; j >= 0; j--){
        X[i] = j;
        weight = weight + A[i]*X[i];
        cost = cost + C[i]*X[i];
        if(i == n){
            Update();
        }
        else if(cost + C[i+1]*(b-weight)/A[i+1] > FOPT){
            Branch_and_Bound(i+1);
        }
        weight = weight - A[i]*X[i];
        cost = cost - C[i]*X[i];
    }
}

int main(){
    Init();
    Branch_and_Bound(1);
    Result();
}