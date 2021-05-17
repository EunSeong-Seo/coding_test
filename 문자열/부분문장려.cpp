#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
	if(a.size()==b.size()) return a<b;
	else return a.size()<b.size();
	}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	string s[20004];
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	cout<<'\n';
	
	sort(s,s+n,cmp);
	for(int i=0;i<n;i++){
		cout<<s[i]<<'\n';
	}
} 
