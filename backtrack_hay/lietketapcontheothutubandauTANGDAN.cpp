#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

int n, X[111], A[111];
vector<vector<int>> result;

void Backtrack(int i, int start) {
    for (int j = start; j <= n; j++) {
        // if (A[j] > X[i-1]) {
            X[i] = A[j];
            if (i >= 1) {
                vector<int> tmp;
                for (int k = 1; k <= i; k++) {
                    tmp.push_back(X[k]);
                }
                result.push_back(tmp);
            }
            Backtrack(i+1,j+1);
        // }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    int tc = 1; 
    while (tc--){
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> A[i];
        Backtrack(1,1);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int  j = 0; j < result[i].size(); j++) {
                cout << result[i][j];
            }
            cout << '\n';
        }
    }
}