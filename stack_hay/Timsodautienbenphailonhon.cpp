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
        int n; cin >> n;
        int a[n];
        for(int &x : a) cin >> x;
        int R[n];
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && a[i] >= st.top()){
                st.pop();
            }
            if(st.empty()) R[i] = -1;
            else R[i] = st.top();
            st.push(a[i]);
        }
        for(int i = 0; i < n; i++) cout << R[i] << " ";
        cout << endl;
    }
}