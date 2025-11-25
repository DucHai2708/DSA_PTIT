#include <bits/stdc++.h>
#define pe pair<int,int>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

struct canh{
    int dau, cuoi, ts;
} dsc[1671];

typedef struct canh canh;

vector<canh> T;
priority_queue<pair<int,pe>, vector<pair<int,pe>>, greater<pair<int,pe>>> q;

int V, E, parent[1006];

void init() {
    for (int i = 1; i <= V; i++) {
        parent[i] = -1;
    }
}

int find(int u) {
    if (parent[u] == -1) return u;
    return find(parent[u]);
}

bool un(int u, int v) {
    int a = find(u), b = find(v);
    if (a == b) return false;
    parent[b] = a;
    return true;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    int tc = 1; cin >> tc;
    while (tc--){
        cin >> V >> E;
        T.clear();
        for (int i = 1; i <= E; i++) {
            cin >> dsc[i].dau >> dsc[i].cuoi >> dsc[i].ts;
            q.push({dsc[i].ts,{dsc[i].dau,dsc[i].cuoi}});
        }
        init(); int d = 0;
        while (!q.empty()) {
            pair<int,pe> p = q.top(); q.pop();
            int a = p.second.first, b = p.second.second;
            if (un(a,b)) {
                T.push_back({a,b,p.first});
            } 
        }
        if (T.size() < V-1) {
            cout << "do thi khong lien thong" << '\n';
        }
        else {
            for (int i = 0; i < T.size(); i++) {
                d += T[i].ts;
            }
            cout << d << '\n';
        }
    }
}