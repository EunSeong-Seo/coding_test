#include <iostream>

using namespace std;

int GDC(int a,int b){
	return b ? GDC(b,a%b):a;
}

int main(){
	int a, b;
	int t;
	cin>>t; 
	for(int i=0;i<t;i++){
		cin>>a>>b;
		cout<<a*b/GDC(a,b)<<endl;
		
	}
	
	
}
