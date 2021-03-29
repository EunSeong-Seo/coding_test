#include <bits/stdc++.h>

using namespace std;

int n =5;
int data[] = {10,20,30,40,50};
int prefix_sum[6];

int main(){
	int sum_value =0;
	
	for(int i=0; i<n;i++){
		sum_value +=data[i];
		prefix_sum[i+1]= sum_value;
	}
	int left =3;
	int right =4;
	cout<< prefix_sum[right]-prefix_sum[left-1];
} 
