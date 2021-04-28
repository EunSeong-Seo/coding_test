#include <iostream>

using namespace std;

int GDC(int a,int b){
	if (a%b ==0) return b;
	else return GDC(b, a%b);
}

int main(){
	int T;
	int n; 
	int a[100];
	
	cin>>T;
	for(int t=0;t<T;t++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		
		long sum=0;
		for(int i=0;i<n;i++){
			for (int j=i+1;j<n;j++){
				sum+=GDC(a[i],a[j]);
			}
		}
		
		cout<<sum<<endl;
		
	}
	
}
