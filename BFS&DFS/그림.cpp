#include <iostream>
#include <queue>

using namespace std;

int map[503][503];
bool vis[503][503];

int n,m;

int pictures =0;
int big =0;

int dx[4] = {-1,0,1,0};
int dy[4] ={0,1,0,-1};

void bfs(int fx, int fy){

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i =0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
		}
	}
	
	for(int i =0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]&& vis[i][j]==false){
				pictures++;
				queue<pair<int, int>> q;
				vis[i][j] = 1;
				q.push({i,j});
				
				int p_num=0;
				while(!q.empty()){
					p_num++;
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					
					for(int dir =0;dir<4;dir++){
						int nx = x +dx[dir];
						int ny = y +dy[dir];
						
						if(nx<0||ny<0||nx>=n||ny>=m) continue;
						
						if(map[nx][ny]!=1||vis[nx][ny]==true) continue;
						
						vis[nx][ny] =1;
						q.push({nx,ny});
					}
				}
	
	big = max(big,p_num);
			}
		}
	}
	cout<<pictures<<'\n';
	cout<<big<<'\n';
	
}
