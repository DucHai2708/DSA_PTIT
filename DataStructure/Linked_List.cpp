#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    //phần tử này trỏ tới node tiếp theo
};

typedef struct Node* node;






//Hàm tạo DSLK : Cấp phát động 1 node mới với dữ liệu (data) là 1 số nguyên x

node Make_Node(int x){
    node tmp = new Node();
    tmp->data = x; // Vì tmp lúc này là con trỏ (tmp có kiểu dữ liệu là node, mà node là con trỏ) nên dùng ->
    tmp->next = NULL; // con trỏ null
    return tmp;
}

//Hàm kiểm tra xem node có rỗng hay không?

bool isEmpty(node a){
    if(a == NULL) return true;
    return false;
}

//Hàm đếm số lượng phần tử trong DSLK

int Size(node a){
    int cnt = 0;
    while(a!=NULL){
        a = a->next; //gán địa chỉ của node phía sau a cho a. Nên a quản lí node ở sau.. và lặp lại tương tự
        ++cnt;
    }
    return cnt;
}

//Hàm thêm 1 phần tử vào đầu DSLK

//Vì cần thay đổi giá trị của node a thì cần truyền tham chiếu mặc dù nó đang là con trỏ rồi
void Insert_First(node &a, int x){
    node tmp = Make_Node(x); // Tạo 1 node mới có tên là tmp
    if(a==NULL){  // Nếu node rỗng
        a = tmp;
    }
    else{
        tmp->next = a; // tmp trỏ vào a để giữ kết nối đằng sau( tức là a trỏ dến a1, a1 trỏ đến a2,..v..v)
        a = tmp; // phần tử đầu tiên lúc này sẽ được gán = tmp nên sẽ là tmp trỏ đến a(vì vừa gán ở dòng trên) và a trỏ tới a1, a1 trỏ a2,..v..v
    }
}

//Hàm thêm 1 phần tử vào cuối DSLK

void Insert_Last(node &a, int x){
    node tmp = Make_Node(x);
    if(a == NULL){ //Nếu node rỗng
        a = tmp;
    }
    else{
        node p = a; // Nếu dùng node a để duyệt thì sẽ thay đổi DSLK, mất hết node ở trước sau khi vòng lặp kết thúc
        while(p->next != NULL){ //Kiểm tra xem node hiện tại trỏ tới node có phải là NULL không
            p = p->next;
        }
        p->next = tmp; // sau khi hết vòng lặp thì sẽ dừng ở node cuối
    }
}

//Hàm thêm 1 phần tử ở giữa

void Insert_Mid(node &a, int x, int pos){
    int n = Size(a);
    if(pos <= 0 || pos > n + 1){
        cout << "This position is invalid" << endl;
    }
    if(pos == 1){ // Nếu chèn vào vị trí đầu tiên
        Insert_First(a,x);
        return;
    }
    else if(pos == n+1){ // Nếu chèn vào vị trí cuối
        Insert_Last(a,x);
        return;
    }
    else{ // Nếu chèn vào giữa
        node tmp = Make_Node(x);
        node p = a;
        for(int i = 1; i < pos - 1; i++){
            p = p->next;
        }
        tmp->next = p->next; // p->next là phần tử ở vị trí pos
        p->next = tmp; // next của con trỏ p hiện tại trỏ vào tmp
    }
}

//Hàm xóa 1 phần tử ở đầu

void Delete_First(node &a){
    if(a==NULL) return; // Nếu DSLK rỗng
    else{
        a = a->next;
    }
}

//Hàm xóa 1 phần tử ở cuối

void Delete_Last(node &a){
    if(a==NULL) return; //Nếu DSLK rỗng
    else{
        node truoc = NULL, sau = a; // Tạo node ở trước và ở sau 
        while(sau->next!=NULL){
            truoc = sau;
            sau = sau->next;
        }
        if(truoc == NULL){
            a = NULL;
            return;
        }
        else{
            truoc->next = NULL;
        }
    }
}

//Hàm xóa 1 phần tử ở giữa

void Delete_Mid(node &a, int pos){
    if(pos <= 0 || pos > Size(a)){
        cout << "Position is invalid" << endl;
        return;
    }
    else{
        node truoc = NULL, sau = a;
        for(int i = 1; i < pos; i++){
            truoc = sau;
            sau = sau->next;
        }
        if(truoc == NULL){
            a = a->next;
            return;
        }
        else{
            truoc->next = sau->next;
        }
    }
}

//Hàm sắp xếp các phần tử trong DSLK theo thứ tự tăng dần

void sortElements_increase(node &a){
    for(node p = a; p != NULL; p=p->next){
        node min_pos = p;
        for(node q = p->next; q != NULL; q=q->next){
            if(min_pos->data > q->data){
                min_pos = q;
            }
        }
        int tmp = min_pos->data;
        min_pos->data = p->data;
        p->data = tmp;
    }
}


//Hàm in ra DSLK

void Print_Node(node a){
    cout << "All of nodes in Linked list: " << endl;
    while(a!=NULL){
        cout << a->data << " ";
        a = a->next;
    }
    cout << endl;
}


int main(){
    node head = NULL;
    while(1){
        cout << "-----------------Menu-----------------" << endl;
        cout << "0.Duyệt DSLK" << endl;
        cout << "1.Chèn 1 phần tử vào đầu DSLK" << endl;
        cout << "2.Chèn 1 phần tử vào cuối DSLK" << endl;
        cout << "3.Chèn 1 phần tử vào giữa DSLK" << endl;
        cout << "4.Xóa 1 phần tử ở đầu DSLK" << endl;
        cout << "5.Xóa 1 phần tử ở cuối DSLK" << endl;
        cout << "6.Xóa 1 phần tử ở giữa DSLK" << endl;
        cout << "7.Sắp xếp các phần tử theo thứ tự tăng dần" << endl;
        cout << "8.Sắp xếp các phần tử theo thứ tự giảm dần" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Nhập lựa chọn: ";
        int opt; cin >> opt;
        int x, y;
        if(opt == 0) Print_Node(head);
        else if(opt == 1){
            cout << "Nhập phần tử bạn muốn chèn: "; cin >> x;
            Insert_First(head,x);
        }
        else if(opt == 2){
            cout << "Nhập phần tử bạn muốn chèn: "; cin >> x;
            Insert_Last(head,x);
        }
        else if(opt == 3){
            cout << "Nhập phần tử bạn muốn chèn: " << endl; cin >> x;
            cout << "Nhập vị trí bạn muốn chèn: "; cin >> y;
            Insert_Mid(head,x,y);
        }
        else if(opt == 4){
            Delete_First(head);
        }
        else if(opt == 5){
            Delete_Last(head);
        }
        else if(opt == 6){
            cout << "Nhập vị trí bạn muốn xóa: "; cin >> y;
            Delete_Mid(head,y);
        }
        else if(opt == 7){
            sortElements_increase(head);
        }
    }
}