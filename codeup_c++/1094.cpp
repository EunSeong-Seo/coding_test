#include <stdio.h>

int main(){
	int a[12]={};
	int n;
	int s=1000; //���� ���� ��  
	scanf("%d",&n);
	
	for(int i =0;i<n;i++){  //�̷��� �ؾ� n���� 
		scanf("%d",&a[i]);
		if(a[i]<=s) s=a[i];
	}
	printf("%d",s);
}
