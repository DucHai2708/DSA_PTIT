#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

/*
    B1: Đẩy s vào hàng đợi
    B2: Rẽ ra các nhánh để xét các trường hợp -1 và *2 của mỗi phần tử
    Chú ý: Chỉ đẩy vào hàng đợi khi thỏa mãn điều kiện :
	--Dk min là không duyệt lại những phần tử đã duyệt vì nó sẽ lặp lại ở phía sau
    --Giá trị sau khi thao tác phải đảm bảo đủ điều kiện để thực hiện các thao tác phía sau
    (x-1 > 0 và x*2 < 20000 và phần tử sau thao tác chưa từng được duyệt trước đó)
	Mảng đánh dấu a[] vừa kiểm tra xem phần tử đã từng dùng chưa vừa dùng để lưu số bước thực hiện
	tới phần tử i của a[i]
	---> a[t] là số bước để s->t
*/
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//data:
	//code here
	int t = 1; cin >> t;
	while(t--){
		int s, t;
		cin >> s >> t;
		int a[20001] = {0};
		queue<int> q; q.push(s);
		while(!q.empty()){
			int top = q.front(); q.pop();
			if(top-1 > 0 && !a[top-1]){
				a[top-1] = a[top] + 1;
				q.push(top-1);
			}
			if(top*2 < 20000 && !a[top*2]){
				a[top*2] = a[top] + 1;
				q.push(top*2);
			}
		}
		cout << a[t] << endl;
	}
}