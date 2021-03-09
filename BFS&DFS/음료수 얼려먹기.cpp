#include <bits/stdc++.h>

using namespace std;

int graph[1000][1000]; //visited room always have to exist
int n,m;
	
bool dfs(int x, int y){  // this method can work corectly if n,m are wildly varalble
	
	if (x<0||y<0||x>=n||y>=m){
		return false;
	}
	if (graph[x][y]==0){
		
		graph[x][y]=1; //this is verry important part in this cord
		
		dfs(x-1,y);
		dfs(x,y-1);
		dfs(x+1,y);
		dfs(x,y+1);
		return true;
	}
	return false;
}

int main(){
	
	cin>>n>>m;
	
	for (int i =0;i<n;i++)  // if you want to get 2D matrix, you should be like this
		for (int j =0;j<m;j++){
				scanf("%1d",&graph[i][j]);
		}
	
	int result =0;
	for (int i =0;i<n;i++){
		for (int j=0;j<m;j++)
			if(dfs(i,j)){
				result+=1;
			}
	}
	cout<<result;
}
