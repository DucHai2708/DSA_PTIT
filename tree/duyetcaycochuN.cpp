#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

struct Node{
	string data;
	Node* left;
	Node* right;
	Node (string x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

Node* buildTree(string s) {
	vector<string> v;
	string token;
	stringstream ss(s);
	while (ss >> token) v.push_back(token);
	Node* root = new Node(v[0]);
	queue<Node*> q;
	q.push(root);
	int i = 1;
	while (!q.empty()) {
		Node* t = q.front(); q.pop();
		if (i == v.size()) break;
		t->left = new Node(v[i]);
		if (v[i] != "N") q.push(t->left);
		++i;
		if (i == v.size()) break;
		t->right = new Node(v[i]);
		if (v[i] != "N") q.push(t->right);
		++i;
	}
	return root;
}

void RNL(Node* root) {
	if (root == NULL || root->data == "N") return;
	RNL(root->right);
	cout << root->data << ' ';
	RNL(root->left);
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//code here
	int tc = 1; cin >> tc; cin.ignore();
	while (tc--){
		string s; getline(cin,s);
		Node* root = buildTree(s);
		RNL(root);
		cout << '\n';
	}
}