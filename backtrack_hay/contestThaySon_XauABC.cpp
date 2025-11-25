#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> result;

bool cmp(string a, string b){
	if(a.length() == b.length()) return a < b;
	return a.length() < b.length();
}

bool check(string s){
	int a = 0, b = 0, c = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == 'A') ++a;
		else if(s[i] == 'B') ++b;
		else ++c;
	}
	if(a >= 1 && b >= 1 && c >= 1 && a <= b && b <= c) return true;
	else return false;
}

void Try(string s, int n){
	if(s.length() > n) return;
	if(s.length() >= 3 && check(s)){
		result.push_back(s);
	}
	if(s.length() < n){
		Try(s + "A",n);
		Try(s + "B",n);
		Try(s + "C",n);
	}
}


int main(){
	cin >> n;
	string s = "";
	Try(s,n);
	sort(result.begin(),result.end(),cmp);
	for(auto x : result) cout << x << endl;
}