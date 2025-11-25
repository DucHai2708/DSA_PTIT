#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

string a[25], b[25];
int n, k, visited[25], X[25], ans = INT_MAX;


void solve(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            b[i][j] = a[i][X[j]];
        }
    }
    sort(b,b+n);
    string s1 = b[n-1], s2 = b[0];
    int maxx = stoi(s1);
    int minn = stoi(s2);
    ans = min(ans, maxx - minn);
}

void Try(int i){
    for(int j = 0; j < k; j++){
        if(!visited[j]){
            X[i] = j; visited[j] = 1;
            if(i == k-1){
                solve();
            }
            else Try(i+1);
            visited[j] = 0;
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    int t = 1; 
    while(t--){
        cin >> n >> k;
        memset(visited,0,sizeof(visited));
        for(int i = 0; i < n; i++){
            cin >> a[i];
            b[i] = a[i];
        }
        Try(0);
        cout << ans << endl;
    }
}