#include <bits/stdc++.h>

using namespace std;


int main(){
	int n,m;
	
	cin>> n>>m;
	vector<int> arr;
	
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr.push_back(x);
	}
	
	vector<int> d(m+1, 10001);
	
	
	d[0]=0;
	for (int i =0; i<n;i++){
		for(int j=arr[i];j<=m;j++){
			if(d[j-arr[i]]!=10001){
				d[j]= min(d[j],d[j-arr[i]]+1);
			}
		}
	}
	
	if(d[m]==10001) cout<<-1<<'\n';
	else cout<< d[m]<<'\n';
	
	
} 
