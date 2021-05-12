#include <iostream>
#include <queue>
using namespace std;


int h,w;
string picture[100010];
bool visited[100010][100010];

int ans =0;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

void bfs(int a, int b, char c){
	queue<pair<int,int> > q;
	visited[a][b]= 1;
	q.push({a,b});
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int dir =0;dir<4;dir++){
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			
			if(nx<0||ny<0||nx>=h||ny>=w) continue;
			if(!visited[nx][ny]&&picture[nx][ny]==c){
				visited[nx][ny]=1;
				q.push({nx,ny});
			}
		}
		
	}
	
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>h;
	for(int i=0;i<h;i++){
		cin>>picture[i];
	}
	int w = picture[0].size();
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(!visited[i][j]){
				ans++;
				bfs(i,j,picture[i][j]);
				
			}
		}
	}
	
	cout<<ans<<'\n';
	
}
