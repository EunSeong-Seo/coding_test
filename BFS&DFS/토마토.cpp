#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int n,m;
int map[1004][1004];
int dist[1004][1004];

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

int mx=0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	queue<pair<int,int> >q;
	
	for(int i=0;i<n;i++){
		fill(dist[n],dist[n]+m,0);
	}

	cin>>m>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
			if(map[i][j]==1){
				dist[i][j]=1;
				q.push({i,j});
			}
		}
	}
	

	
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int dir =0; dir<4;dir++){
			int nx = x + dx[dir];
			int ny = y +dy[dir];
			
			if(nx<0||ny<0||nx>=n||ny>=m) continue;
			if(dist[nx][ny]>=1)continue;
			if(map[nx][ny]==-1)continue;
			
			dist[nx][ny]= dist[x][y]+1;
			q.push({nx,ny});
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(dist[i][j]==0&&map[i][j]!=-1){
				cout<<-1<<'\n';
				return 0;
			}
			mx = max(mx,dist[i][j]);
		}
	}
	
	cout<<mx-1;
} 
