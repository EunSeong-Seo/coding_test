#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

int map[30][30];
bool visited[30][30];

int n;
int home=0;
int group[700];
int danji =1;

int dx[4]={-1,0,1,0}; //¿ì  
int dy[4]={0,1,0,-1};


void input(){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			scanf("%1d",&map[i][j]);
		}
	}
}

int dfs(int x, int y){

	if(map[x][y]== 1&&visited[x][y]==false){
		home++;
		map[x][y]=0;
		visited[x][y]==true;
		
		for(int i=0;i<4;i++){
			int nx = x +dx[i];
			int ny = y + dy[i];
			
			if(nx<0 ||ny<0||nx>=n||ny>=n) continue;
			dfs(nx,ny);
		}
	
		return home;
	}
}


int  main(){
	
	cin>>n;
	input();
	for(int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if(map[i][j]==1&&visited[i][j]==false){
				home =0;
				int x = dfs(i,j);
				if(x!=0){
					group[danji]=x;
					danji++;
				}	
				
			}
			
			
		}
	}
	

	
	cout<<danji-1<<endl;
	for(int i=1;i<danji;i++){
		cout<<group[i]<<endl;
	}

} 
