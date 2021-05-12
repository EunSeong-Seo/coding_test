#include<iostream>
#include <algorithm>

using namespace std;

int n,m;

int main(void){
	
	cin>>n>>m;
	
	if(n==1) cout<<1<<'\n';
	else if(n==2){
		cout<<min(4,(m+1)/2)<<'\n';
	}
	
	else if(n>=3){
		if(m<=6) cout<<min(4,m)<<'\n';
		else cout<<m-2<<'\n';
	}
	
	return 0;
	
	
}
