#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
	int n;
	vector<pair <int ,int> > vv; // .first = m , .second = v
	
	int k;
	vector<int> c;
	
	cin>>n>>k;
	
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		vv.push_back({x,y});
	}
	for(int i=0;i<k;i++){
		int x;
		cin>>x;
		c.push_back(x);
	}
	
	sort(vv.begin(),vv.end());
	sort(c.begin(),c.end());
	
	
	
	
} 
