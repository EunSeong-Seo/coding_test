#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
vector <int> v;

int main(){
	cin>>n;
	v.push_back(0);
	
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(v.back()<x)v.push_back(x);
		else{
			int index =lower_bound(v.begin(),v.end(),x)-v.begin();
			v[index] = x;
		}
	}
	
	
	cout<<v.size()-1<<endl;
}
