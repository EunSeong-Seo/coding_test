#include <bits/stdc++.h>
using namespace std;

int factorial_iterative(int n){
	int result =1;
	for (int i =1;i<=n;i++){
		result *=i;
	}
	return result;
}

int factorial_recursive(int n){
	if (n<=1) return 1; //0!과 1!은 1이다
	return n * factorial_recursive(n-1); 
}

int main(){
	
	printf("iterative : %d\n", factorial_iterative(5));
	printf("recursive : %d", factorial_recursive(5));
}
