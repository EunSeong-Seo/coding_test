#include <iostream>

using namespace std;

int cnt =0;
int n;

bool isused1[40];
bool isused2[40];
bool isused3[40];

void func(int cur){
	if (cur == n){
		cnt ++;
		return ;	
	}
	
	for(int i=0;i<n;i++){
		if(isused1[i]||isused2[i+cur]||isused3[cur-i+n-1]) continue;
		
		isused1[i]=1;	// i 는 y 
		isused2[i+cur]=1;	// cur 은 x 
		isused3[cur-i+n-1]=1;	//음의 범위를 넘지 않기 위해  
		
		func(cur+1);
		
		isused1[i]=0;
		isused2[i+cur]=0;
		isused3[cur-i+n-1]=0;
		
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	func(0);
	cout<< cnt;
}
