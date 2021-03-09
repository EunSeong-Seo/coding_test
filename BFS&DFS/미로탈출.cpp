#include<bits/stdc++.h>

 using namespace std;
 
 int n,m;
 int graph[201][201]; // it is easy to make graph big rather than tight
 
 int dx[4]={0,-1,0,1}; //left up right down movement
 int dy[4]={-1,0,1,0};
 
int bfs(int x, int y){
 	queue<pair <int,int> >q;
 	q.push({x,y}) ; 		//First. push in q
 	
 	while(!q.empty()) 	//Second. repeat untill q is empty
 	{
 		int x= q.front().first;
 		int y= q.front().second;
 		q.pop();
 		
 		for (int i =0;i<4;i++){
 			
 			int nx = x +dx[i];
 			int ny = y+ dy[i];
 			
 			
 			if(nx<0||ny<0||nx>=n||ny>=m)continue; //this is method which use in a movement or even BFS
		 	if(graph[nx][ny]==0) continue;
		 	if(graph[nx][ny]==1){
		 		graph[nx][ny]=graph[x][y]+1;
		 		q.push({nx,ny});
			 }
		 }
		 
	 }
 	return graph[n-1][m-1];
 }
 
 int main(){
 	cin>>n>>m;
 	
 	for (int i =0;i<n;i++)
 		for(int j =0;j<m;j++){
 			scanf("%1d",&graph[i][j]);
		 }
	bfs(0,0);
	for (int i =0;i<n;i++){
 		for(int j =0;j<m;j++){
 			printf("%d ",graph[i][j]);
		 }
		 printf("\n");}
	return 0;
 }
