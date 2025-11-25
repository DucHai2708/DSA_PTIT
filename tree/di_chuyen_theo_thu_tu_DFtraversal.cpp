#include <bits/stdc++.h>
using namespace std;

/*
Test case : 
10
1 2 3 4 5 6 7 8 9 10
*/

int a[10005], n;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node (int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
// Theo mảng
void preOrder(int i) {
    if (i >= n) return;
    cout << a[i] << ' ';
    preOrder(2*i + 1);
    preOrder(2*i + 2);
}
//Theo cây
void preOrder2(Node* root) {
    if (root == NULL) return;
    cout << root->data << ' ';
    preOrder2(root->left);
    preOrder2(root->right);
}
// Theo mảng
void inOrder(int i) {
    if (i >= n) return;
    inOrder(2*i + 1);
    cout << a[i] << ' ';
    inOrder(2*i + 2);
}
//Theo cây
void inOrder2(Node* root) {
    if (root == NULL) return;
    inOrder2(root->left);
    cout << root->data;
    inOrder2(root->right);
}
//Theo mảng
void postOrder(int i) {
    if (i >= n) return;
    postOrder(2*i+1);
    postOrder(2*i+2);
    cout << a[i] << ' ';
}
//Theo cây
void postOrder2(Node* root) {
    if (root == NULL) return;
    postOrder2(root->left);
    postOrder2(root->right);
    cout << a[i] << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << "preOrder: "; preOrder(0); cout << '\n';
    cout << "inOrder: "; inOrder(0); cout << '\n';
    cout << "postOder: "; postOrder(0); cout << '\n';
}