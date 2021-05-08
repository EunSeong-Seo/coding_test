#include <iostream>
#include <queue>

using namespace std;

char c[1003][1003];
int dist[1003][1003];
bool fvis[1003][1003];


int n,m;


int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};


int main(void){
	queue<pair<int,int>>jq;
	queue<pair<int,int>>fq;
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			scanf("%1c",&c[i][j]);
			if (c[i][j]=='J'){
				jq.push({i,j});
				dist[i][j]=0;
			}
			if (c[i][j]=='F'){
				fq.push({i,j});
				dist[i][j]=-1;
				
			}
			else{
				dist[i][j]=-1;
			}			
		}
	}
	
	while(1){
		int x = jq.front().first;
		int y = jq.front().second;
		jq.pop();
		for(int dir =0;dir<4;dir++){
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			
			if(nx<0||ny<0||nx>=n||ny>=m){
				cout<< dist[x][y]+1;
				return 0;
			}
			
			if(dist[nx][ny]>=0)continue;
			
			if(c[nx][ny]=='.'){
				dist[nx][ny] = dist[x][y]+1;
				c[nx][ny]='J';
				c[x][y]='.';
				jq.push({nx,ny});
			}
		}
		
		int fx = fq.front().first;
		int fy = fq.front().second;
		fvis[fx][fy]=1;
		fq.pop();
		
		for(int dir =0;dir<4;dir++){
			int fnx = fx + dx[dir];
			int fny = fy + dy[dir];
			
			if(fnx<0||fny<0||fnx>=n||fny>=m) continue;
			
			if(!fvis[fnx][fny]&&c[fnx][fny]!='#'){
				c[fnx][fny]='F';
				fq.push({fnx,fny});
			}
			
		}
		
		bool escape =0;
		
		for(int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				if(c[i][j]=='J') escape= 1;
			}
		}
		
		if(escape == 0){
			cout<<"IMPOSSIBLE"<<'\n';
			return 0;
		}
		
	}
	
	
	
	
}
