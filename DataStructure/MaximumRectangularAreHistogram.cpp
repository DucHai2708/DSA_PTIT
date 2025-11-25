#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int &x : a) cin >> x;
        int Max_area = -1e9;
        stack<int> st;
        int i = 0;
        while(i < n){
            if(st.empty() || a[i] > a[st.top()]){
                st.push(i);
                ++i;
            }
            else{
                int idx = st.top();
                st.pop();
                if(st.empty()){
                    Max_area = max(Max_area, a[idx]*(i-idx));
                }
                else{
                    Max_area = max(Max_area, a[idx]*(i-st.top()-1));
                }
            }
        }
        while(!st.empty()){
            int idx = st.top();
            st.pop();
            if(st.empty()) Max_area = max(Max_area, a[idx]*(i-idx));
            else Max_area = max(Max_area, a[idx]*(i-st.top()-1));
        }
        cout << Max_area << endl;
    }
}