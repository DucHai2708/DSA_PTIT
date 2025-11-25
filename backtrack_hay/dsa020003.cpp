#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int arr[100][100];
int n;

std::vector<std::string> str;

void backtrack(int i, int j, std::string s){
	if(i == n && j == n){
		str.push_back(s);
		return;
	}
	if(i < n && arr[i+1][j] == 1){
		backtrack(i+1,j,s+"D");	
	}
	if(j < n && arr[i][j+1] == 1){
		backtrack(i,j+1,s+"R");
	}
}

int main(){
	int t; std::cin >> t;
	while(t--){
		std::cin >> n;
		str.clear();
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				std::cin >> arr[i][j];
			}
		}
		backtrack(1,1,"");
		if(arr[1][1] == 0 || arr[n][n] == 0){
			std::cout << -1 << "\n";
			continue;
		}
		if(str.empty()){
			std::cout << -1 << "\n";
		}
		else{
			sort(str.begin(),str.end());
			for(auto x : str){
				std::cout << x << " ";
			}
			std::cout << "\n";
		}
	}
}