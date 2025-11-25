#include <bits/stdc++.h>
using namespace std;

int n, x, a[10005];

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

Node* creBST(int a[], int l, int r) {
    if (l > r) return NULL;
    int m = (l + r) / 2;
    Node *root = new Node(a[m]);
    root->left = creBST(a,l,m-1);
    root->right = creBST(a,m+1,r);
    return root;
}

void insert(Node* &root, int x) {
    if (root == NULL) {
        root = new Node(x);
        return; 
    }
    if (x < root->data) insert(root->left,x);
    if (x > root->data) insert(root->right,x);
}

bool search(Node* root, int x) {
    if (root == NULL) return false;
    if (root->data == x) return true;
    if (x < root->data) return search(root->left,x);
    if (x > root->data) return search(root->right,x);
}

void preOrder(Node* root) {
    if (root == NULL) return;
    cout << root->data << ' ';
    preOrder(root->left);
    preOrder(root->right);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    Node* root = creBST(a,0,n-1);
    // insert(root,x);
    preOrder(root);
}