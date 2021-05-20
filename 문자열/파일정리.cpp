#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<string, int> > extension;
vector<string>ss;

int main(){
	cin>>n;
	
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		int p =0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='.'){
				p =i;
			}
		}
		ss.push_back(s.substr(p+1));
	}
	
	sort(ss.begin(),ss.end());
	
	string temp = ss[0];
	int cnt=0;
	for(int i=0;i<ss.size();i++){
		if(temp == ss[i])cnt++;
		else if(temp !=ss[i]){
			extension.push_back({temp,cnt});
			temp = ss[i];
			cnt =1;
		}
	}
	extension.push_back({temp,1});

	for(int i=0;i<extension.size();i++){
		cout<<extension[i].first<<' '<<extension[i].second<<'\n';
	}

} 
