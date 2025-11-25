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

void insert(Node* &root, int x) {
    if (root == NULL) {
        root = new Node(x);
        return; 
    }
    if (x < root->data) insert(root->left,x);
    if (x > root->data) insert(root->right,x);
}

Node* find(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* deletee(Node* root, int x) {
    if (root == NULL) return root;
    if (x < root->data) root->left = deletee(root->left,x);
    else if (x > root->data) root->right = deletee(root->right,x);
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        if (root->left == NULL) {
            Node* tmp = root->right;
            delete root;
            return tmp;
        }
        else if (root->right == NULL) {
            Node* tmp = root->left;
            delete root;
            return tmp;
        }
        Node* tmp = find(root->right);
        root->data = tmp->data;
        root->right = deletee(root->right,tmp->data);
    }
    return root;
}

void preOrder(Node* root) {
    if (root == NULL) return;
    cout << root->data << ' ';
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << ' ';
    inOrder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << ' ';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    Node* root = NULL;
    int x, y;
    while (cin >> x) {
        if (x == 1) {
            cin >> y;
            insert(root,y);
        }
        else if (x == 2) {
            cin >> y;
            deletee(root,y);
        }
        else if (x == 3) {
            preOrder(root);
            cout << '\n';
        }
        else if (x == 4) {
            inOrder(root);
            cout << '\n';
        }
        else {
            postOrder(root);
            cout << '\n';
        }
    }
}