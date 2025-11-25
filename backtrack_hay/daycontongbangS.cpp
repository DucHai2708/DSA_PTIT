#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

int n, k;
vector<int> a(16), c;

// n <= 27

void backtrack(int i, int s, vector<int> &path) {
    if (s == k) {
        for (auto x : path) cout << x << ' ';
        cout << '\n';
        return;
    }
    if (s > k) return;
    for (int j = i; j < n; j++) {
        path.push_back(a[j]);
        backtrack(j+1,s+a[j],path);
        path.pop_back();
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    int tc = 1; cin >> tc;
    while (tc--){
        cin >> n >> k;
        a.resize(n,0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        backtrack(0,0,c);
    }
}