#include <bits/stdc++.h>
using namespace std;

/*
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R
*/

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

void insert(Node* root, int n1, int n2, char c) {
    if (root == NULL) return;
    if (root->data == n1) {
        if (c == 'L') root->left = new Node(n2);
        else root->right = new Node(n2);
    }
    else {
        insert(root->left,n1,n2,c);
        insert(root->right,n1,n2,c);
    }
}

vector<vector<int>> levelOrder(Node* root) {
    if (root == NULL) return {};
    queue<Node*> q;
    q.push(root);
    vector<vector<int>> ans;
    int currentLevel = 0;
    while (!q.empty()) {
        int len = q.size();
        ans.push_back({});
        for (int i = 0; i < len; i++) {
            Node* t = q.front(); q.pop();
            ans[currentLevel].push_back(t->data);
            if (t->left != NULL) q.push(t->left); //duyệt trái trước -> nếu muốn duyệt phải trước thì đổi thành right
            if (t->right != NULL) q.push(t->right);
        }
        currentLevel++;
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // code here
    int tc = 1; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        int u, v; char x;
        Node* root = NULL;
        for (int i = 0; i < n; i++) {
            cin >> u >> v >> x;
            if (root == NULL) {
                root = new Node(u);
                if (x == 'L') root->left = new Node(v);
                else root->right = new Node(v);
            }
            else insert(root,u,v,x);
        }
        vector<vector<int>> res = levelOrder(root);
        for (int i = 0; i < res.size(); i++) {
            cout << '[';
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size()-1) cout << res[i][j] << ' ';
                else cout << res[i][j];
            }
            cout << ']';
            cout << ' ';
        }
        cout << '\n';
    }
}