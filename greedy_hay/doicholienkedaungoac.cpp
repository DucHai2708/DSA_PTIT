#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

/*
Nếu tại thời điểm nào đó balance < 0, nghĩa là đang thiếu dấu [, 
--> Cần đổi chỗ một dấu [ nào đó bên phải để "cân bằng lại".
*/
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here
	int t = 1; cin >> t;
	while(t--){
		string s; cin >> s;
		int balance = 0, count = 0;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '[') ++balance;
			else{
				--balance;
				if(balance < 0){
					int pos;
					for(int j = i+1; j < s.length(); j++){
						if(s[j] == '['){
							pos = j;
							swap(s[i],s[j]);
							break;
						}
					}
					count += pos-i;
					balance = 1;  // Vì thay thế dấu '[' thành ']' nên trạng thái phải là 1
				}
			}
		}
		cout << count << endl;
	}
}