#include <bits/stdc++.h>
using namespace std;

//push đẩy 1 phần tử vào ngăn xếp
//pop xóa 1 phần tử ở đầu tiền trong ngăp xếp
//top lấy ra phần tử ở đầu ngăn xếp
//size kích thức ngăn xếp
//empty kiểm tra ngăn xếp rỗng
//O(1)

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.top ()<< endl; // in ra phần tử ở đỉnh ngăn xếp
    st.pop();
    cout << st.top() << endl;
    cout << st.size() << endl;
    if(st.empty()){ // nếu xâu rỗng thì trả về 1
        cout << "empty" << endl;
    } else cout << "no" << endl;
    cout << "-----------------------" << endl;


    //PROBLEM 1: Chuyển từ hệ 10 sang hệ 2

    int n = 34;
    stack<int> st1;
    while(n){
        st1.push(n%2);
        n /= 2;
    }
    while(!st1.empty()){
        cout << st1.top();
        st1.pop();
    }
    cout << endl;
    cout << "-----------------------" << endl;

    //PROBLEM 2: In ra các từ theo thứ tự ngược lại

    string s = "python java php c++";
    stack<string> st2;
    stringstream ss(s);
    string token;
    while(ss >> token){
        st2.push(token);
    }
    while(!st2.empty()){
        cout << st2.top() << " ";
        st2.pop();
    }
    cout << endl;
    cout << "-----------------------" << endl;

    //PROBLEM 3: Kiểm tra dấu ngoặc hợp lệ

    string s1 = "()()(((((()))))(";
    stack<char> st3;
    for(char x : s1){
        if(x == '('){
            st3.push(x);
        }
        else{
            if(st3.empty()){
                cout << "INVALID" << endl;
                return 0;
            }
            else st3.pop();
        }
    }
    if(st3.empty()) cout << "VALID" << endl;
    else cout << "INVALID" << endl;
    cout << "-----------------------" << endl;

    //PROBLEM 4 : Phần tử lớn hơn đầu tiên bên phải

    int a[] = {3,4,2,5,1,6,2};
    stack<int> st4; // dùng để lưu chỉ số
    int ans[7]; // dùng để lưu mảng kết quả
    for(int i = 0; i < 7; i++){
        if(st4.empty()){ // Nếu xâu rỗng thì đẩy chỉ số i vào
            st4.push(i);
        }
        else{
            while(!st4.empty() && a[st4.top()] < a[i]){ // Lặp cho hết phần tử nhỏ hơn a[i]
                ans[st4.top()] = a[i];
                st4.pop();
            }
            st4.push(i);
        }
    }
    while(!st4.empty()){
        ans[st4.top()] = -1;
        st4.pop();
    }
    for(int x : ans) cout << x << " ";
    cout << endl;
    cout << "-----------------------" << endl;

    //PROBLEM 4 : Diện tích lớn nhất của HCN trên biểu đồ

    /* tư tưởng: tính toán tất cả các hcn. trong đó coi mỗi cột của hcn là cột ngắn nhất của hcn có thể tạo thành
        */
    
    // Xem trong folder Datastructure


}