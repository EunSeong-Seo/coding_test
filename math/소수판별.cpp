#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int x){
	
	if(x==1)return false;
	
	for(int i =2;i<=(int)sqrt(x);i++){
		if(x%i==0)return false;
	}
	return true;
	
}


int main(){
	
	int n;
	int num=0;
	cin>>n;
	int a[101];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		if(isPrime(a[i])) num++;

	}
	
	cout<<num<<endl;
}
