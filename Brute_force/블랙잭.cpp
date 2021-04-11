#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;

int sum=0, maxi=0;

int main(){
	
	cin>>n>>m;
	
	vector<int> v;
	
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				sum = v[i]+v[j]+v[k];
				if(sum>maxi&&sum<=m){
					maxi= sum;
				}
			}
		}
	}
	 
	cout<<maxi<<endl;
	
	
}
