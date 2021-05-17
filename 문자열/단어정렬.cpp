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
	
	sort(s,s+n,cmp);
	
	string temp; 
	for(int i=0;i<n;i++){
		if(temp ==s[i])continue;
		cout<<s[i]<<'\n';
		temp=s[i];
	}
} 
