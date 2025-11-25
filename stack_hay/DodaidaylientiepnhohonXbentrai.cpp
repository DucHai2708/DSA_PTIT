#include <bits/stdc++.h>

// Nhip chung khoan

/*
Tìm phần tử đầu cuối cùng bên trái nhỏ hơn x trong dãy liên tiếp phần tử nhỏ hơn x ở bên trái x
Hay nói cách khác là phần tử đầu tiên bên trái lớn hơn x
Thao tác với chỉ sổ -> đưa ra chỉ số i đầu tiên bên trái lớn hơn x rồi tính khoảng cách từ x tới i
*/
 
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
		stack<int> st;
		for(int i = 0; i < n; i++){
			while(!st.empty() && a[i] >= a[st.top()]) st.pop();
			if(st.empty()) cout << i + 1 << " ";
			else cout << i - st.top() << " ";
			st.push(i);
		}
		cout << endl;
	}
}