#include <stdio.h>

int main(){
	int a[24]={};
	int n;
	int t;
	
	scanf("%d",&n);
	
	for(int i =1;i<=n;i++){  //이렇게 해야 n번반 
		scanf("%d ",&t);
		a[t]+=1;
	}
	for(int i =1;i<=23;i++){
		printf("%d ",a[i]);
	}
	return 0;

}
