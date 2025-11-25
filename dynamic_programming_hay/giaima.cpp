#include <bits/stdc++.h>
using namespace std;

/*

dp[i] là số cách có thể tạo được tính từ vị trí i đến vị trí cuối của xâu
basic dp[n] = 1 và dp[n-1] = 1 nếu số cuối khác 0 vì 0 không nằm trong khoảng được tạo
+) nếu s[i] là 1 số thỏa mãn thì số cách chọn 1 chữ số là 1 và số cách chọn từ i+1 là dp[i+1]
-> quy tắc nhân là 1 x dp[i+1]
+) nếu s[i] và s[i+1] có thể tạo thành 1 số thỏa mãn thì số cách chọn là 1 và số cách chọn từ i+2 là dp[i+2]
-> quy tắc nhân là 1 x dp[i+1]

-> dp[i] = tổng 2 trường hợp trên !
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    int t = 1; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.length();
        int dp[100] = {0};
        dp[n] = 1;
        dp[n-1] = (s[n-1]!='0') ? 1 : 0;
        for(int i = n-2; i >= 0; i--){
            if(s[i] >= '1' && s[i] <= '9'){
                dp[i] += dp[i+1];
            }
            int x = (s[i]-'0')*10 + (s[i+1]-'0');
            if(x >= 10 && x <= 26) dp[i] += dp[i+2];
        }
        cout << dp[0] << endl;
    }
}