#include <bits/stdc++.h>

using namespace std;

bool is_Primenumber(int x){
	
	for (int i=2; i<x;i++){
		if(x%i ==0)return false;
	}
	return true;
	
	
}

int main(){
	cout<<is_Primenumber(4)<<'\n';
	cout<<is_Primenumber(7)<<'\n';
}
