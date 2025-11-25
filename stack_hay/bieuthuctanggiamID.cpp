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
        string s; cin >> s;
        stack<int> st; st.push(1);
        int dem = 1;
        for(int i = 0; i < s.size(); i++){
            ++dem;
            if(s[i] == 'D'){
                st.push(dem);
            }
            else{
                while(!st.empty()){
                    cout << st.top();
                    st.pop();
                }
                st.push(dem);
            }
        }
        while(!st.empty()){
            cout << st.top(); st.pop();
        }
        cout << endl;
    }
}