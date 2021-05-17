#include <iostream>

using namespace std;

string a[15];

int main(void){

	for(int i=0;i<5;i++){
		cin>>a[i];
	}
	
	int l = a[0].size();
	
	for(int i=0;i<l;i++){
		for(int j=0;j<5;j++){
			cout<<a[j][i];
		}
	}
}
