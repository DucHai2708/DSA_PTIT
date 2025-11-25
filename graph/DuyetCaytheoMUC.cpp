#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int Mod = 1e9+7;


struct Node{
	int data;
	Node *left, *right;
	Node (int x) {
		data = x;
		left = right = nullptr;
	}	
};


void lever_order(Node *root) {
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node* parent = q.front(); q.pop();
		cout << parent->data << ' ';
		if (parent->left != nullptr) q.push(parent->left);
		if (parent->right != nullptr) q.push(parent->right);
	}
}

void insert(Node *root, int n1, int n2, char c) {
	if (root == nullptr) return;
	if (root->data == n1) {
		if (c == 'L') {
			root->left = new Node(n2);
		}
		else root->right = new Node(n2);
	}
	else {
		insert(root->left,n1,n2,c);
		insert(root->right,n1,n2,c);
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    int tc= 1; cin >> tc;
    while (tc--){
		int n;
		cin >> n;
		Node *root = nullptr;
		while (n--) {
			int n1, n2; char x;
			cin >> n1 >> n2 >> x;
			if (root == nullptr) {
				root = new Node(n1);
				if (x == 'L') root->left = new Node(n2);
				else root->right = new Node(n2);
			}
			else {
				insert(root,n1,n2,x);
			}
		}
		lever_order(root);
		cout << '\n';
    }
}
