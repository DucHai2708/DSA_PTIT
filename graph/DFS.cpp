#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9+7;
 
int n, mtk[101][101], vs[101];

void DFS(int u) {
    vs[u] = 1; cout << u << ' ';
    for (int i = 1; i <= n; i++) {
        if (!vs[i] && mtk[u][i]) {
            DFS(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    int tc = 1; cin >> tc;
    while (tc--){
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> mtk[i][j];
            }
        }
        memset(vs,0,sizeof(vs));
        DFS(1);
    }
}