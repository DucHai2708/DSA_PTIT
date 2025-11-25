#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    int t = 1; cin >> t;
    while(t--){ 
        int n, k;
        cin >> n >> k;
        int a[n+1] = {0};
        for(int i = 1; i <= k; i++) cin >> a[i];
        int i = k;
        while(i > 0 && a[i] == a[i-1] + 1){
            --i;
        }
        if(i > 0){
            a[i] = a[i] - 1;
        }
        for(int j = i + 1; j <= k; j++){
            a[j] = n - k + j;
        }
        for(int j = 1; j <= k; j++){
            cout << a[j] << " ";
        }
        cout << endl;
    }
}