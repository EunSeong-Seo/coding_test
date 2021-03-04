#include <stdio.h>

int main(){
	int a[11][11]={};
	for (int i=1;i<11;i++){
		for(int j =1; j<11;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	int x=2;
	int y=2;
	
	while(x<11&&y<11){
		
		if(a[x][y]==2){
		a[x][y]=9;
		break;}
		
		if(a[x][y]==0)a[x][y]=9;
		
		if (a[x][y+1]==0) y+=1;
		else if (a[x][y+1]==0) x+=1;
		
		if(a[x][y]==1 && a[x][y]==1)break;
		
	}
	
	
	for (int i=1;i<11;i++){
		for(int j =1; j<11;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}

}
	

