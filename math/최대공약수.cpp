#include <iostream>

using namespace std;

int GCP(int a, int b){ 
	if(a%b==0) return b;
	else return GCP(b,a%b);
}

int main(){

	int a,b;
	
	cin>> a>>b;

	cout<<	GCP(a,b)<<endl;
	cout<<a*b/GCP(a,b)<<endl;;
	return 0;
}  
