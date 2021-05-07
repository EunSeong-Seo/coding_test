#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

int map[110][110];
bool vis[110][110]; 
int n,m;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

void bfs(int fx,int fy){
	queue<pair<int,int>>q;
	vis[fx][fy]= 1;
	q.push({fx,fy});
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();	//@@@ 撇啡带 何盒@@@
		
		for(int dir =0; dir<4;dir++){
			int nx = x +dx[dir];
			int ny = y + dy[dir];
			
			if(nx<0||ny<0||nx>=n||ny>=m)continue;
			if(vis[nx][ny]||map[nx][ny]==0) continue;
			
			vis[nx][ny]=1;
			map[nx][ny]=map[x][y]+1; //@@@ 撇啡带 何盒@@@ 
			q.push({nx,ny});
		}
	}
	
	
}

int main(){

	cin>> n>>m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d", &map[i][j]);
		}
	}
	bfs(0,0);
	
	

	cout<<map[n-1][m-1]<<'\n';	
	
	
	
	
	
}
