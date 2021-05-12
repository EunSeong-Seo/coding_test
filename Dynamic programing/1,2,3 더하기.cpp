#include<iostream>

using namespace std;

 
int d[13];
int t=0;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(d,d+13,0);
	d[1]=1;
	d[2]=2;
	d[3]=4;
	
	cin>>t;
	while(t){
		int x;
		cin>>x;
		for(int i=4;i<=x;i++){
			if(d[i]==0){d[i]=d[i-1]+d[i-2]+d[i-3];}
			}
		cout<<d[x]<<'\n';
		t--;
	}
	
}
