#include<iostream>

using namespace std;

int d[1010][3];
int h[1010][3]; //h is home
int n;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++) cin>>h[i][0]>>h[i][1]>>h[i][2];
	
	d[0][0]=h[0][0];
	d[0][1]=h[0][1];
	d[0][2]=h[0][2];
	
	for(int i=1;i<n;i++){
		d[i][0]= min(d[i-1][1],d[i-1][2]) +h[i][0];
		d[i][1]= min(d[i-1][0],d[i-1][2]) +h[i][1];
		d[i][2]= min(d[i-1][0],d[i-1][1]) +h[i][2];
	}
	
	int ans = min(min(d[n-1][0],d[n-1][1]),d[n-1][2]);
	cout<<ans<<'\n';
}
