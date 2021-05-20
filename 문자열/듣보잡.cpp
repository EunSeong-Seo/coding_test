#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> vd;
vector<string> res;

int n,m;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		string x;
		cin>>x;
		vd.push_back(x);
	}
	
	sort(vd.begin(),vd.end());
	
	for(int i=0;i<m;i++){
		string y;
		cin>>y;
		if(binary_search(vd.begin(),vd.end(),y)) res.push_back(y);
	}
	
	sort(res.begin(),res.end());
	cout<<res.size()<<'\n';
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<'\n';
	}
}
