#include <stdio.h>

int main(){
	int a[24]={};
	int n;
	int t;
	
	scanf("%d",&n);
	
	for(int i =1;i<=n;i++){  //�̷��� �ؾ� n���� 
		scanf("%d ",&t);
		a[t]+=1;
	}
	for(int i =1;i<=23;i++){
		printf("%d ",a[i]);
	}
	return 0;

}
