#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

struct canh{
    int dau, cuoi, ts;
} dsc[1671];

typedef struct canh canh;

int n, m, vs[1671];
vector<int> parent(1671,-1);
vector<pair<int,int>> List[1671];
vector<canh> T;

void Prim(int u) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,u});
    int d = 0;
    while (!pq.empty()) {
        pair<int,int> top = pq.top(); pq.pop();
        int w = top.first;
        int v = top.second;
        if (vs[v]) continue;
        vs[v] = 1;
        d += w;
        if (parent[v] != -1) {
            T.push_back({parent[v],v,w});
        }
        for (auto it : List[v]) {
            int minn = it.first;
            int vv = it.second;
            if (!vs[vv]) {
                if (parent[vv] == -1 || minn < List[parent[vv]][vv].first) {
                    parent[vv] = v;
                }
                pq.push({minn,vv});
            }
        }
    }
    cout << d << '\n';
    for (int i = 0; i < T.size(); i++) cout << '(' << T[i].dau << ',' << T[i].cuoi << ')' << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    int tc = 1; cin >> tc;
    while (tc--){
        cin >> n >> m;
        memset(vs,0,sizeof(vs));
        parent.resize(n+1,-1);
        for (int i = 1; i <= n; i++) List[i].clear();
        int u, v, w;
        for (int i = 1; i <= m; i++) {
            cin >> dsc[i].dau >> dsc[i].cuoi >> dsc[i].ts;
            u = dsc[i].dau; v = dsc[i].cuoi; w = dsc[i].ts;
            List[u].push_back({w,v});
            List[v].push_back({w,u});
        }   
        int x; cin >> x;
        Prim(x);
    }
}