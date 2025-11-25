#include <bits/stdc++.h>

using namespace std;

//8
//1 1 2 1 3 5 1 -4


//map<data type1, data type2>
//map<key, value>
//key la duy nhat, 1 key chi luu duoc 1 value
//1 value co the luu o nhieu key
//chi tim kiem duoc key
//insert
//find tra ve iterator cua cap key value. Neu ko tim thay thi se tra ve mp.end()
//count O(logN)
//erase
//odered : co thu tu, duoc sap xep tang dan theo key
//Duoc dung de:
//Dem tan suat xuat hien: key luu gtri so xh trong mang, value luu gtri tan suat

//vd: dem so lan xuat hien cua cac phan tu trong mang va in ra tan suat
//Input
//8
// 1 1 2 1 3 5 1 -4
//Output: // theo thu tu xuat hien
//1 4
//2 1
//3 1
//-4 1
//5 1
//Dem xau ki tu xh bn lan hoac dem tu xh bn lan theo thu tu xh
//Tim phan tu co tsxh nhieu nhat
//neu co nhieu tu con cung tsxh, hay in ra tu co thu tu tu dien nho nhat
//Input:
//10
//python java c++ sql python python c++ c++ java java
//Output:
//python 4
//java 4
//c++ 2
//sql1

//multimap: nhieu key co the giong nhau
//ko the gan mp[key] = value duoc boi vi tinh chat tren cua multimap
//dung insert
//erase se xoa het cac key. neu muon xoa 1 cai thi xoa thong qua iterator

//unordered_map: ko co thu tu



int main(){
	map<int,int> mp;
	mp[100] = 200; // key = 100 & value = 200 (100,200)
	mp[200] = 300; // (200,300)
	mp.insert({300,400}); //(300,400)
	mp.insert({400,500}); //(400,500)
	cout << mp.size() << endl;
	mp[100] = 600;   //(100,200) duoc thay the bang (100,600) | ban chat la thay doi gia tri cua key
	mp[500] = 300;
	cout << mp.size() << endl; // khong lam thay doi kich thuoc
	//duyet qua map
	for(pair<int, int> x :mp){ // vi map luu kieu pair nen khi duyet phai duyet theo kieu pair
		cout << x.first << " " << x.second << endl; 
	}
	cout << "------------" << endl;
	//co the dung auto thay cho pair
	for(auto x : mp) cout << x.first << " " << x.second << endl;
	cout << "------------" << endl;
	//duyet bang iterator
	for(map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
		cout << (*it).first << " " << (*it).second << endl;
	}
	cout << "------------" << endl;
	if(mp.count(100)!=0) cout << "FOUND\n";
	else cout << "NOT FOUND\n";
	cout << "------------" << endl;
	if(mp.find(100)!=mp.end()) cout << "FOUND\n";
	else cout << "NOT FOUND\n";
	cout << "------------" << endl;
	mp.erase(100); // xoa cap key value (100,600)
	for(auto x : mp) cout << x.first << " " << x.second << endl;
	cout << "------------" << endl;
	map<int, int> mp1;
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		mp1[x]++;  //neu truy cap vao key nao do ko ton tai trong map thi value = 0. VD: mp1[x] = 0;
	}
	for(auto it : mp1) cout << it.first << " " << it.second << endl; // duyet ko theo thu tu xh ma theo thu tu cua map
	cout << "------------" << endl;
	//in theo thu tu xh
	map<int, int> mp2;
	int m; cin >> m;
	int a[1000];
	for(int i = 0; i < m; i++){
		cin >> a[i];
		mp2[a[i]]++;
	}
	for(int i = 0; i < m; i++){
		if(mp2[a[i]]!=0){
			cout <<a[i] << " " << mp2[a[i]] << endl;
			mp2[a[i]] = 0;
		}
	}
	cout << "------------" << endl;
	map<string, int> mp3;
	int p; cin >> p;
	for(int i = 0; i < p; i++){
		string s; cin >> s;
		mp3[s]++;
	}
	for(auto it : mp3){
		cout << it.first << " " << it.second << endl;
	}
	cout << "------------" << endl;
	//tim tu co tan suat xh nhieu nhat
	int max_fre = 0;
	string res;
	for(auto x : mp3){
		if(x.second >= max_fre){
			max_fre = x.second;
			res = x.first;
		}
	}
	cout << res << " " <<  max_fre << endl;
	cout << "------------" << endl;
	multimap<int,int> mtp;
	mtp.insert({100,200});
	mtp.insert({200,300});
	mtp.insert({100,250});
	mtp.insert({300,400});
	mtp.insert({400,500});
	for(auto it : mtp){
		cout << it.first << " " << it.second << endl;
	}
	cout << mtp.count(100) << endl;
	cout << "------------" << endl;
	//xoa chi 1 ptu bang erase
	mtp.erase(mtp.begin());
	for(auto x : mtp){
		cout << x.first << " " << x.second << endl;
	}
	cout << "------------" << endl;
	
}
