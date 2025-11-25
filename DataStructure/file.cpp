#include <bits/stdc++.h>
using namespace std;

//ifstream : Đọc file
//ofstream : Ghi file
//fstream : Cả đọc và ghi file

//ios::in : Đọc file
//ios::out : Ghi file
//ios::binary : Mở kiểu nhị phân
//ios::app : Mở file để ghi nhưng ghi vào cuối file
//ios::ate : Đặt vị trí con trỏ vào cuối file. Nếu mà mode này không được bật thì vị trí con trỏ sẽ là đầu file
//ios::trunc : Mở file để đọc, những nội dung trước đó trong file sẽ bị mất trước khi ghi nd mới vào
//close() : Đóng file
//is_open() : Ktra xem có mở được file hay không

struct SinhVien{
    string name, date;
    string email, password;
};

void TK(SinhVien &a){
    stringstream ss(a.name);
    string token;
    vector<string> v;
    while(ss >> token){
        for(int i = 0; i < token.length(); i++) token[i] = tolower(token[i]);
        v.push_back(token);
    }
    string res = v[v.size()-1];
    for(int i = 0; i < v.size()-1; i++){
        res += v[i][0];
    }
    a.name = res;
    a.email = a.name + "@stu.ptit.edu.vn";
}

void MK(SinhVien &a){
    stringstream ss(a.date);
    string token;
    string pass = a.name;
    while(getline(ss, token, '/')){
        pass += token;
    }
    a.password = pass;
}

int main(){
    ifstream in("PTIT.txt");
    ofstream out("output.txt");
    
    SinhVien a[3];
    for(int i = 0; i < 3; i++){
        string s1; getline(in, s1);
        a[i].name = s1;
        string s2; getline(in, s2);
        a[i].date = s2;
    }
    for(int i = 0; i < 3; i++){
        TK(a[i]);
        MK(a[i]);
    }
    for(int i = 0; i < 3; i++){
        out << a[i].email << " " << a[i].password << "\n";
    }

}