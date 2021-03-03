#include <stdio.h>

int main(){
	int a[12]={};
	int n;
	int s=1000; //가장 작은 값  
	scanf("%d",&n);
	
	for(int i =0;i<n;i++){  //이렇게 해야 n번반 
		scanf("%d",&a[i]);
		if(a[i]<=s) s=a[i];
	}
	printf("%d",s);
}
