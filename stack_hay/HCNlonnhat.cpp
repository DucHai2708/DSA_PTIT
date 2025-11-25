#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

/*
|      __
|__   |  |__
|__|__|__|__|
|__|__|__|__|__
|__|__|__|__|__|______
-- Với mỗi cột a[i] ta xét xung quanh chúng xem phần tử đầu tiên nhỏ hơn chúng ở cả 2 bên trái phải
Cách tìm:
+) TÌm phần tử đầu tiên nhỏ hơn a[i] ở bên trái và phải 
-- Phần diện tích hình chữ nhật lớn nhất tạo bởi cột a[i] sẽ là: 
===> Độ cao của a[i] và độ rộng của 2 phần tử đầu tiên nhỏ hơn ấy
*/
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    int t = 1; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n], L[n], R[n];
        for(int &x : a) cin >> x;
        //Tìm phần tử đầu tiên nhỏ hơn bên trái
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && a[i] <= a[st.top()]) st.pop();
            if(st.empty()) L[i] = -1; // Nếu không có phần tử nào nhỏ hơn bên trái thì mốc là trước i0
            else L[i] = st.top(); // Chỉ số của phần tử đầu tiên < a[i]
            st.push(i);
        }

        while(!st.empty()) st.pop(); //reset stack

        //Tìm phần tử đầu tiên nhỏ hơn bên phải
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && a[i] <= a[st.top()]) st.pop();
            if(st.empty()) R[i] = n; // Nếu không có phần tử nào nhỏ hơn bên phải thì mốc là sau in-1
            else R[i] = st.top(); // Chỉ số của phần tử đầu tiên < a[i]
            st.push(i);
        }   
        ll res = 0;
        for(int i = 0; i < n; i++){
            ll area = 1ll*(R[i]-L[i]-1)*a[i];
            res = fmax(res,area);
        }
        cout << res << endl;
    }
}