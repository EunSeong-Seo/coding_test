#include <bits/stdc++.h>

#define INF 10001

using namespace std;
vector<int> arr;

int main(){
	int n;
	int m;
	
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr.push_back(x);
	}
	
	vector<int> d(m + 1, INF);
	
	d[0]=0;
	for (int i=0;i<n;i++){
		for(int j=arr[i]; j<=m;j++){
			if(d[j-arr[i]]!=INF){
				d[j]= min(d[j],d[j-arr[i]+1]);
			}
		}
	}
	
	if (d[m]==INF){
		cout<< -1<<'\n';
	}
	else cout<< d[m]<<'\n';
	
	
	
}
