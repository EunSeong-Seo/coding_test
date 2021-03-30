#include <bits/stdc++.h>

using namespace std;

int n,m;

int main(){
	cin>>n>>m;
	int a[n];
	
	int max_l=0;
	
	for (int i=0;i<n;i++){
		int x;
		cin>>x;
		a[i]=x;
		if (a[i] >max_l) max_l= a[i];
	}
	
	int start =0;
	int end=max_l;
	
	while(true){
		int mid = (start+end)/2;
		int result =0;
		
		for (int i=0;i<n;i++){
			if(a[i]-mid <=0) continue;
			result+=a[i]-mid;
		}
		
		if (result ==m){
			cout<< mid;
			break;
		}
		else if(result <m){
			end = mid -1;
		}
		else if (result>m){
			start = mid +1;
		}
	
	}
}
