    #include <bits/stdc++.h>

    // Hậu tố thì sửa lại duyệt for và a, b
    
    using namespace std;
    using ll = long long;
    const int Mod = 1e9+7;

    ll calculate_value(ll a, ll b, char c){
        if(c == '+') return a+b;
        if(c == '-') return a-b;
        if(c == '*') return a*b;
        if(c == '/') return a/b;
    }

    ll change(string s){
        ll res = 0;
        int j = 0;
        if(s[0] == '-') j = 1;
        for(int i = j; i < s.size(); i++){
            res = res * 10 + (s[i]-'0');
        }
        if(j) res *= -1;
        return res;
    }

    ll calculate_front(vector<string> v){
        stack<ll> st;
        for(int i = v.size()-1; i >= 0; i--){
            if(isdigit(v[i][0]) || v[i].size() >= 2){
                ll x;
                if(v[i].size() >= 2){
                    x = change(v[i]);
                }
                else x = v[i][0] - '0';
                st.push(x);
            }
            else{
                ll a = st.top(); st.pop();
                ll b = st.top(); st.pop();
                ll x = calculate_value(a,b,v[i][0]);
                st.push(x);
            }
        }
        return st.top();
    }
    
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        //code here
        int t = 1; cin >> t;
        while(t--){
            int	n; cin >> n;
            cin.ignore();
            string str; getline(cin, str);
            stringstream ss(str); string token;
            vector<string> v;
            while(ss >> token) v.push_back(token);
            cout << calculate_front(v) << endl;
        }
    }