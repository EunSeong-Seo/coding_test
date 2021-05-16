#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

string map[1010];
int n,m;
int fire_dist[1010][1010];
int jihun_dist[1010][1010];

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	queue<pair<int,int> >fq;
	queue<pair<int,int> >jq;
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>map[i];
	}
	
	for(int i=0;i<n;i++){
		fill(fire_dist[i],fire_dist[i]+m,-1);
		fill(jihun_dist[i],jihun_dist[i]+m,-1);
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]=='F'){
				fire_dist[i][j]=0;
				fq.push({i,j});
			}
			if(map[i][j]=='J'){
				jihun_dist[i][j]=0;
				jq.push({i,j});
			}
		}
	}
	
	while(!fq.empty()){
		int x= fq.front().first;
		int y = fq.front().second;
		fq.pop();
		
		for(int dir=0;dir<4;dir++){
			int nx = x+dx[dir];
			int ny = y +dy[dir];
			
			if(nx<0||ny<0||nx>=n||ny>=m) continue;
			if(map[nx][ny]=='#') continue;
			if(fire_dist[nx][ny]>=0) continue;
			
			fire_dist[nx][ny]= fire_dist[x][y]+1;
			fq.push({nx,ny});
		}
	}
	
	while(!jq.empty()){
		int x= jq.front().first;
		int y = jq.front().second;
		jq.pop();
		
		for(int dir=0;dir<4;dir++){
			int nx = x+dx[dir];
			int ny = y +dy[dir];
			
			if(nx<0||ny<0||nx>=n||ny>=m){
				cout<<jihun_dist[x][y]+1;
				return 0;
			}
			if(map[nx][ny]=='#') continue;
			if(jihun_dist[nx][ny]>=0) continue;
			if(fire_dist[nx][ny]!=-1&&jihun_dist[x][y]+1>= fire_dist[nx][ny]) continue;
			
			jihun_dist[nx][ny]= jihun_dist[x][y]+1;
			jq.push({nx,ny});
			
		}
	}

	 cout<<"IMPOSSIBLE";
}
