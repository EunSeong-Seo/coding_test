#include <iostream>

using namespace std;

int n=0;
int d[1010];


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	
	d[1]=1;
	d[2]=2;

	for(int i=3;i<=n;i++){
		d[i]= (d[i-1]+d[i-2])%10007;
	}
	
	int ans = d[n];
	cout<<ans;
}
