#include <string>
#include <vector>
#include <queue>

using namespace std;
int dist[5][5];
int copy_dist[5][5];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

bool check;
queue<pair<int,int>> Pq;
string map[5];

void bfs(int a, int b ){
    queue<pair<int,int>> q;
    dist[a][b]= 0;
    q.push({a,b});
    
    while(!q.empty()){
        
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int dir= 0;dir<4;dir++){
            int nx = x +dx[dir];
            int ny = y +dy[dir];

            if(nx<0||ny<0||nx>=5||ny>=5) continue;
            if(map[nx][ny]=='X')continue; // "X"가 아니라 'X'라는 사실

            dist[nx][ny]= dist[x][y]+1;

            if(dist[nx][ny]<=2&& dist[nx][ny]>=0&&map[nx][ny]=='P'){
                check = true;
                return;
            }
            if(dist[nx][ny]==3){
                return;
            }
            q.push({nx,ny});
        }
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int tcase = 0; tcase<5;tcase++){
        while(!Pq.empty())Pq.pop();
        for(int i=0;i<5;i++){
        	map[i]= places[tcase][i];
		}
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(map[i][j]=='P'){
                    Pq.push({i,j});
                }
            }
        }
        while(!Pq.empty()){
            bool check = false;
            
            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    dist[i][j]= -1; 
                }
            }
         
            int a = Pq.front().first;
            int b = Pq.front().second;
            Pq.pop();
            bfs(a,b);
            
            if(check==true)break;
        }
        
        if(check==true) answer.push_back(0);
        else answer.push_back(1);

    }
    
    
    return answer;
}


int main(){
	vector<vector<string>> places=[["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], ["PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]
	solution(places);
} 
