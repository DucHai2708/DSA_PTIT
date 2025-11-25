#include <bits/stdc++.h>
using namespace std;
/*
Depth first search : Tìm kiếm theo chiều sâu
-> Duyệt rồi xét từng đỉnh kề với  đỉnh đang xét để xuống dưới nhanh nhất có thể rồi quay lại
note: Đỉnh nào xét rồi thì cần đánh dấu và không xét lại
*/ 
int n, a[105][105];
bool visited[105];

void khoitao(){
    cin >> n;
    // Tạo ma trận kề
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j]; 
        }
    }
}

void DFS(int u){ // Tìm kiếm từ đỉnh u.
    stack<int> st;
    st.push(u); visited[u] = true;
    cout << u << " ";
    while(!st.empty()){
        int s = st.top(); st.pop();
        for(int t = 1; t <= n; t++){
            if(a[s][t] && !visited[t]){
                cout << t << " ";
                visited[t] = true;
                st.push(s);
                st.push(t);
                break; // Chỉ lấy 1 đỉnh rồi duyệt đỉnh kề của đỉnh mới
            }
        }
    }
}


int main(){
    khoitao();
    int u; cin >> u; // Đỉnh xuất phát
    DFS(u);

}