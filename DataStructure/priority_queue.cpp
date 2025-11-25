#include <bits/stdc++.h>
using namespace std;

//priority_queue : Được cài bằng cấu trúc dữ liệu heap | Luôn duy trì phần tử top là lớn nhất or nhỏ nhất
// Dùng như hàng đợi
//size()
//empty()
//push()
//top() : Lấy ra phần tử ở đầu mặc định là lớn nhất
//pop() : Xóa phần tử ở đầu

// Áp dụng trong thuật toán CÂY KHUNG CỰC TIỂU


int main(){
    priority_queue<int> pq;
    pq.push(1);
    pq.push(3);
    pq.push(7);
    pq.push(4);
    pq.push(5);
    pq.push(2);
    cout << pq.top() << endl;
    pq.push(100);
    pq.push(30);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    //Nếu muốn phần tử ở đỉnh là nhỏ nhất thì dùng
    priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(1);
    pq1.push(3);
    pq1.push(7);
    pq1.push(4);
    pq1.push(5);
    pq1.push(2);
    cout << pq1.top() << endl;
    pq1.pop();
    cout << pq1.top() << endl;


    //PROBLEM 1: Bài toán nối dây
    /*Cho N sợi dây với độ dài khác nhau được lưu trong mảng A[]. Nhiệm vụ của bạn là nối N sợi dây 
    thành 1 sợi sao cho tổng chi phí nối dây là nhỏ nhất. Biết chi phí nối dây thứ i và thứ j là tổng 
    độ dài 2 sợi dây A[i] và A[j]
    4
    4 3 2 6 -> 29 
    5
    4 2 7 6 9 -> 62*/

    int n = 5; int a[5] = {4,2,7,6,9};
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0; i < n; i++) q.push(a[i]);
    int kq = 0;
    while(q.size() > 1){
        int top1 = q.top(); q.pop();
        int top2 = q.top(); q.pop();
        kq += top1 + top2;
        q.push(top1+top2);
    }
    cout << kq << endl;

    //PROBLEM 2: Giá trị nhỏ nhất của xâu
    /*AAABBCC = 3^2 + 2^2 + 2^2 = 17*/

    string s = "ABCC";
    map<char,int> mp;
    for(char x : s){
        mp[x]++;
    }
    priority_queue<int> p;
    for(auto x : mp) p.push(x.second);
    int k = 0;
    while(k--){
        int top = p.top() - 1;
        p.pop();
        p.push(max(top,0));
    }
    int ans = 0;
    while(!p.empty()){
        ans += p.top()*p.top();
        p.pop();
    } cout << ans << endl;

}