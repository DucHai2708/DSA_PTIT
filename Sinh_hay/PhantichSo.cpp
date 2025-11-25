#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

int n, a[50];

void result(int n){
    cout << "(";
    for(int i = 1; i <= n; i++){
        if(i != n) cout << a[i] << " ";
        else cout << a[i];
    }
    cout << ") ";
}

void Try(int i, int x, int s){
    for(int j = x; j >= 1; j--){ //Duyệt từ số hiện tại về 1
        a[i] = j;
        if(j == s) result(i); //Nếu số hiện tại thêm vào bằng lượng còn lại thì kết thúc
        else if(j < s) Try(i+1,j,s-j); //Thử với trường hợp số được thêm vào < lượng còn lại
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    int t = 1; cin >> t;
    while(t--){
        cin >> n;
        Try(1,n,n);
        cout << endl;
    }
}