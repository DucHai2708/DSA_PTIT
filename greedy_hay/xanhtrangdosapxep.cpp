#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

/*
    Vì chỉ có 3 màu nên khi sắp xếp đúng sẽ có 3 khoảng màu lần lượt là Xanh - Trắng Đỏ
    Độ dài mỗi khoảng = số kí tự đại diện của màu
    Duyệt rồi xử lí từ trái qua, từng khoảng màu 1 (n-1 màu).
	Kiểm tra kí tự ở sau đó có ở trong khoảng không rồi hoán vị
	Mỗi lần swap là cộng thêm 1 lần xử lí
    Xét riêng từng khoảng:
        - Nếu 1 trong khoảng tồn tại kí tự màu khác khoảng đó thì ta chỉ duyệt trong các khoảng có khả
        năng chứa nó. ví dụ: trong khoảng của x mà có của t thì sẽ tìm và hoán vị trong khoảng màu t và d
    Bản chất là màu nào phải về đúng vị trí của khoảng màu đó
	
*/
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here
	int t = 1;
	while(t--){
		int n; cin >> n;
		string s; cin >> s;
		int x = 0, t = 0, d = 0;
		for(char c : s){
			if(c == 'X') ++x;
			else if(c == 'T') ++t;
			else ++d;
		}
		int res = 0;
		for(int i = 0; i < x; i++){ // Duyệt khoảng đúng của X
			if(s[i] == 'T'){ 
				for(int j = x; j < n; j++){ // Duyệt ngoài khoảng X
					if(s[j] == 'X'){
						swap(s[i],s[j]);
						++res;
						break;
					}
				}
			}
			else if(s[i] == 'D'){
				for(int j = n-1; j >= x; j--){ // Duyệt từ cuối về vì đây là màu xanh nên ko hạn chế khả năng hoán vị khoảng T
					if(s[j] == 'X'){
						swap(s[i],s[j]);
						++res;
						break;
					}
				}
			}
		}
		for(int i = x; i < x+t; i++){ // Duyệt khoảng của t
			if(s[i] == 'D'){
				for(int j = n-d; j < n; j++){  // Duyệt khoảng của D
					if(s[j] == 'T'){
						swap(s[i],s[j]);
						++res;
						break;
					}
				}
			}
		}
		cout << res;
	}
}