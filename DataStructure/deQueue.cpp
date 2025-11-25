#include <bits/stdc++.h>
using namespace std;


//size() : Kích thước của hàng đợi
//push_front() : Đẩy 1 phần tử vào đầu
//push_back() : Đẩy 1 phần tử vào cuối
//pop_front() : Xóa 1 phần tử ở đầu
//pop_back() : Xóa 1 phần tử ở cuối
//empty() : Kiểm tra stack rỗng
//front() : Lấy ra phần tử ở đầu
//back() : Lấy ra phần tử ở cuối
//O(1)

int main(){
    deque<int>q;
    q.push_front(2);
    q.push_front(1);
    q.push_front(7);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    deque<int> qq = q;
    deque<int> qqq = q;
    cout << "Size of deque : " << q.size() << " !" << endl;
    cout << "---------------------------" << endl;
    cout << "Elements of deque : " << endl;
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop_front();
    }
    cout << "!" << endl;
    cout << "---------------------------" << endl;
    cout << "Elements of deque back to the front : " << endl;
    while(!qq.empty()){
        cout << qq.back() << " ";
        qq.pop_back();
    }
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "Delete the last element !" << endl;
    qqq.pop_back();
    cout << "Elements of deque after edit : " << endl;
    while(!qqq.empty()){
        cout << qqq.front() << " ";
        qqq.pop_front();
    }
    cout << "!" << endl;
    cout << "---------------------------" << endl;

    //Số lớn nhất của mọi cửa sổ kích thước K của mảng (Sliding window maximum problem)

    //idea: thêm từ từ các phần tử trong mảng vào stack theo thứ tự giảm dần và lấy ptu ở đỉnh stack là kq( coi ptu đầu tiên là max)
    int n = 9, k = 3;
    int a[9] = {7,3,1,2,8,6,4,1,0};
    deque<int> q1;
    for(int i = 0; i < k; i++){
        while(!q1.empty() && a[i] > a[q1.back()]){ // Kiếm tra xem phần tử ở cuối nếu nhỏ hơn ptu đang xét thì xóa đi
            q1.pop_back();
        }
        q1.push_back(i); // đẩy chỉ số của ptu đang xét trong mảng a
    }
    cout << a[q1.front()] << " ";
    for(int i = k; i < n; i++){
        if(q1.front() <= i - k){ // kiểm tra xem ptu đang xét có nằm trong cửa sổ hay không
            q1.pop_front();
        }
        while(!q1.empty() && a[i] > a[q1.back()]){
            q1.pop_back();
        }
        q1.push_back(i);
        cout << a[q1.front()] << " ";
    }

}