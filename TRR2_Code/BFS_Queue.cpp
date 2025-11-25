#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

/*
Duyệt đỉnh nào thì sẽ xem xét hết các đỉnh kề của nó chứ không chỉ xét 1 đỉnh như DFS
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

void BFS(int u){ // xuất phát từ đỉnh u
    queue<int> q;
    q.push(u); visited[u] = true;
    cout << u << " ";
    while(!q.empty()){
        int s = q.front(); q.pop();
        for(int t = 1; t <= n; t++){
            if(a[s][t] && !visited[t]){
                cout << t << " ";
                q.push(t); visited[t] = true;
            }
        }
    }
}

int main(){
    khoitao();
    int u; cin >> u;
    BFS(u);
}