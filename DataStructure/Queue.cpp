
// FIFO
//O(1)
//push: đẩy vào cuối
//pop: xóa ở đầu
//empty : rỗng
//size: kích thước
//front: lấy ra phần tử ở đầu 
//back: lấy ra phần tử ở cuối
//include <queue>

// Thường dùng để giải bài toán phân tích theo trình tự từ đầu đến cuối
// Dùng để giải các bài toán biến từ số này sang số kia thông qua từng này bước..v..v..

#include <bits/stdc++.h>
using namespace std;

int idx[4] = {-1,0,1,0};
int idy[4] = {0,-1,0,1};

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.push(5);
    cout << "---------------------------" << endl;
    cout << "Number of elemnents in queue : " << q.size() << endl;
    cout << "---------------------------" << endl;
    cout << "Elements in queue: " << endl;
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
    cout << "---------------------------" << endl;

    // PROBLEM 1: Liệt kê tất cả các số nhị phân tử 1 đến n

    int n = 8;
    queue<string> proCess; //Hàng đợi dùng để xử lí
    vector<string> answer; // Lưu kết quả 
    proCess.push("1");
    answer.push_back("1");
    while(answer.size() < n){
        string tempAnal = proCess.front(); // Lấy phần tử đứng đầu hàng để thao tác
        answer.push_back(tempAnal + "0");
        answer.push_back(tempAnal + "1");
        //thêm vào các phần tử để tiếp tục thao tác
        proCess.push(tempAnal + "0");
        proCess.push(tempAnal + "1");
        proCess.pop(); // Xóa phần tử vừa được thao tác
    }
    for(int i = 0; i < n; i++) cout << answer[i] << " ";
    cout << endl;
    cout << "---------------------------" << endl;


    //PROBLEM 2: Bội số chỉ chứa 0 và 9
    /*Cho số tự nhiên N. Hãy tìm số nguyên dương X nhỏ nhất được tạo bởi số 9 và số 0 chia hết cho N
    Ví dụ N = 5 thì X = 90*/

    int N = 5;
    queue<string> proCess2;
    proCess2.push("9");
    bool ok = true;
    while(ok){
        string tempAnal = proCess2.front();
        long long tmp = stoll(tempAnal);
        if(tmp % N == 0){
            cout << tmp << endl;
            ok = false;
        }
        else{
            proCess2.push(tempAnal + "0");
            proCess2.push(tempAnal + "9");
            proCess2.pop();
        }
    }
    
    cout << "---------------------------" << endl;

    //PROBLEM 3: Số lộc phát
    /*Liệt kê các số lộc phát không có quá M chữ số và in theo thứ tự giảm dần*/

    int M = 2;
    queue<string> proCess3;
    proCess3.push("6"); proCess3.push("8");
    vector<long long> answer2;
    answer2.push_back(6);
    answer2.push_back(8);
    while(1){
        if(proCess3.front().length() >= M) break;
        else{
            string tmp = proCess3.front();
            answer2.push_back(stoll(tmp+"6"));
            answer2.push_back(stoll(tmp+"8"));
            proCess3.push(tmp+"6");
            proCess3.push(tmp+"8");
            proCess3.pop();
        }
    }
    sort(answer2.begin(), answer2.end(), greater<long long>());
    for(auto x : answer2) cout << x << " ";
    cout << endl;
    cout << "---------------------------" << endl;


    //PROBLEM 5: Biến đổi từ số S thành số T với 2 thao tác giảm S đi 1 đơn vị hoặc nhân S lên 2

    int s = 2, t = 5;
    queue<pair<int,int>> q1; // Kiểu dữ liệu pair ở đây được dùng để lưu số hiện tại và số bước đã qua
    set<int> se; // Dùng để lưu các giá trị đã được duyệt
    q1.push({s,0});
    se.insert(s);
    while(!q1.empty()){
        pair<int,int> top = q1.front(); q1.pop();
        if(top.first == t){
            cout << top.second << endl;
            break;
        }
        if(top.first * 2 == t || top.first - 1 == t){
            cout << top.second + 1 << endl;
            break;
        }
        if(se.find(top.first*2) == se.end() && top.first < t){
            se.insert(top.first*2);
            q1.push({top.first*2,top.second+1});
        }
        if(se.find(top.first-1) == se.end() && top.first > 1){
            se.insert(top.first-1);
            q1.push({top.first-1,top.second+1});
        }
    }
    cout << "---------------------------" << endl;

    //PROBLEM 6: Đường đi ngắn nhất trên lưới

    int a[6][6] = {
        {1,0,1,1,1,1},
        {1,0,1,0,1,1},
        {1,1,1,0,1,1},
        {0,0,0,0,1,0},
        {1,1,1,0,1,1},
        {1,0,1,1,1,1}
    };
    pair<int,int> start = {0,0}, end = {3,4};
    queue<pair<int,int>> q2;
    q2.push({start.first,start.second});
    int d[100][100];
    d[start.first][start.second] = 0;
    while(!q2.empty()){
        pair<int,int> top = q2.front(); q2.pop();
        int i = top.first;
        int j = top.second;
        for(int k = 0; k < 4; k++){
            int i1 = i + idx[k];
            int j1 = j + idy[k];
            if(a[i1][j1] && i1 >= 0 && i1 < 6 && j1 >= 0 && j1 < 6){
                a[i1][j1] = 0;
                if(i1 == end.first && j1 == end.second){
                    cout << d[i][j] + 1 << endl;
                    return 0;
                }
                q2.push({i1,j1});
                d[i1][j1] = d[i][j] + 1;
            }
        }
    }
    cout << -1 << endl;
    return 0;

}
