#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

/*
4a + 7b = n
a là số chữ số 4
b là số chữ số 7
Ưu tiên dùng nhiều số 4 hơn, vì chữ số 4 nhỏ hơn chữ số 7
Ta sẽ thử tất cả số lượng chữ số 7 có thể (b từ 0 đến n//7)
Với mỗi b, ta tính thử a = (n - 7b) / 4
Nếu a là số nguyên (chia hết), thì 4a + 7b = n hợp lệ
Lúc này ta lưu lại cặp (a, b) nào có tổng số chữ số (a + b) nhỏ nhất 
(vì số càng ít chữ số càng nhỏ), nếu bằng nhau thì chọn cái nào có nhiều số 4 hơn để số tạo ra bé hơn.
*/
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here
	int t = 1; cin >> t;
	while(t--){
		int n; cin >> n;
		int best_a = -1, best_b = -1;
		int minn = INT_MAX;
		for(int b = 0; b <= n / 7; b++){
			int tmp = n - 7*b;
			if(tmp % 4 == 0){
				int a = tmp / 4;
				if(a + b == minn){
					if(best_a < a) best_a = a;
					best_b = b;
				}
				else if(a + b < minn){
					best_a = a;
					best_b = b;
					minn = a + b;
				}
			}
		}
		if(best_a == -1) cout << -1 << endl;
		else{
			for(int i = 0; i < best_a; i++) cout << 4;
			for(int i = 0; i < best_b; i++) cout << 7;
			cout << endl;
		}

	}
}