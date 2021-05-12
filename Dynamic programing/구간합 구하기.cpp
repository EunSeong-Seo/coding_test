#include<iostream>

using namespace std;

int n,m;
int d[100004];
int a[100004];


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	d[0]=0;
	for(int i =1;i<=n;i++){
		cin>>a[i];
		d[i] = d[i-1]+a[i];	
	}
/*
	for (int i=0;i<m;i++){		//print overflow 
		int x,y;
		cin>>x>>y;
		cout<<d[y]-d[x-1]<<'\n';
	}
	
*/

	while(m--){
		int x,y;
		cin>>x>>y;
		cout<<d[y]-d[x-1]<<'\n';
	}
}
