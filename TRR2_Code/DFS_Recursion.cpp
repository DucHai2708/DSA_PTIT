#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

/*
Duyệt các đỉnh kề tới khi không thể duyệt nữa thì quay lại duyệt đỉnh khác
*/

int a[105][105], n;
bool visited[105];

void khoitao(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
}

void DFS2(int u){
    cout << u << " ";
    visited[u] = true;
    for(int t = 1; t <= n; t++){
        if(!visited[t] && a[u][t]){
            DFS2(t);
        }
    }
}
 
int main(){
    khoitao();
    int u; cin >> u;
    DFS2(u);
}