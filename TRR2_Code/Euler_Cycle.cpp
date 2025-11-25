#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

int n, a[105][105];
 
void khoitao(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
}

bool kiemtra(){
    int d = 0;
    for(int i = 1; i <= n; i++){
        int s = 0;
        for(int j = 1; j <= n; j++){
            s += a[i][j];
        }
        if(s % 2) ++d;
    }
    if(d > 0) return false;
    else return true;
}

void Euler_Cycle(int u){
    stack<int> st; int arr[105], index = 0;
    st.push(u);
    while(!st.empty()){
        int s = st.top();
        int j = 1;
        while(j <= n && a[s][j] == 0){
            ++j;
        }
        if(j > n){ // Khong co dinh ke nao
            int x = st.top(); st.pop();
            ++index;
            arr[index] = x;
        }
        else{
            st.push(j);
            a[s][j] = 0; a[j][s] = 0;
        }
    }
    for(int i = index; i >= 1; i--){
        cout << arr[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    int t = 1;
    while(t--){
        khoitao();
        if(kiemtra()){
            Euler_Cycle(1);
        }
        else cout << "Ko co" << endl;
    }
}