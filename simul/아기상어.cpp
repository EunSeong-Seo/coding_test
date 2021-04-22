#include <iostream>
#include <queue>
using namespace std;

int N;
int map[30][30];
int copy_map[30][30];
int shark_size = 2;
int ate = 0;
int time = 0;
int shark_x = 0;
int shark_y = 0;

queue <pair<int,int>>fq; //fish queue
int fish_num = 0;

int dx[4] = {0,1,0,-1};//오 아 왼 위
int dy[4] = {1,0,-1,0};



class fish {
public:
	int x = 0;
	int y = 0;
};

void init() {
	int shark_size = 2;
	int ate = 0;
	int time = 0;
	int shark_x = 0;
	int shark_y = 0;
	int fish_num = 0;
	while(!fq.empty())fq.pop();
}

void input() {

	cin>> N;
	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
}

void change_map() {
	fish_num = 0;

	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++) {
			int k = map[i][j];
			if (k > shark_size && k != 9) copy_map[i][j] = -1;
			else if (k == shark_size) copy_map[i][j] = 0;
			else if (k == 0)copy_map[i][j] = 0;
			else if (k == 9) {
				shark_x = i;
				shark_y = j;
				copy_map[i][j] = 0;
			}
			else{
				fq.push({ i,j });
				fish_num++;
				copy_map[i][j] = 0;
			}
		}

}


void bfs(int sx, int sy) {		//shrk 위치가 x y
	queue<pair <int, int> >q;
	q.push({sx, sy});

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
			if (copy_map[nx][ny] == -1)continue;
			if (copy_map[nx][ny] == 0) {
				copy_map[nx][ny] = copy_map[x][y] + 1;
				q.push({ nx,ny });
			}
		}

	}
	
}




int solution() {
	init();
	input();

	while (true) {
		change_map();

		if (fish_num == 0) return time;

		bfs(shark_x, shark_y);

		int short_cut = 60;
		fish eating;
		eating.x = 30;
		eating.y = 30;

		while(!fq.empty()){
			int i = fq.front().first;
			int j = fq.front().second;
			fq.pop();

			if (copy_map[i][j] < short_cut) {
				short_cut = copy_map[i][j];
				eating.x = i;
				eating.y = j;
			}
			if (copy_map[i][j] == short_cut) {
				if (i < eating.x) {
					short_cut = copy_map[i][j];
					eating.x = i;
					eating.y = j;
				}
				if (i == eating.x) {
					if (j < eating.y) {
						short_cut = copy_map[i][j];
						eating.x = i;
						eating.y = j;
					}
				}
			}
			
		}


	
	//move
		map[shark_x][shark_y] = 0;
		shark_x = eating.x;
		shark_y = eating.y;
		map[eating.x][eating.y] = 9;
		time += copy_map[shark_x][shark_y];

		ate++;
		if (ate >= shark_size) {
			ate -= shark_size;
			shark_size++;
		}
	}
}


int main() {

	cout<<solution();
}

