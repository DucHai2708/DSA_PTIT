#include <bits/stdc++.h>
#define fi first
#define se second
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

/*
- Mảng là 1 kho chứa các phần tử có cùng kiểu dữ liệu (cùng kiểu char, int, long long)


(kiểu dữ liệu) + (tên mảng) + [số phần tử] 


a       4,1,2,5,6,6,7
chỉ sổ  0,1,2,3,4,5,6
- muốn truy cập vào 1 phần tử trong mảng, ta cần biết vị trí chỉ số của phần tử ấy trong mảng
===> a[i] với i là chỉ số của phần tử trong mảng a

*/
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    // int a[8] = {2,3,6,7,11,9,14,16};

    /*
    in ra phần tử tại chỉ số i của mảng a
    for (int i = 0; i < 8; i++) {
        cout << a[i] << " ";
    }
    */
    
    /*
    cho mảng a như trên, in ra các số chia hết cho 3
    */
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i =0 ; i < n; i++) cout << a[i] << " ";

}