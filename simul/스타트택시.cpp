#include <iostream>
#include <vector>
#include<queue>
#include <algorithm>

#define WALL -1
#define MAX 1000

using namespace std;

int n, m;
int fuel;
int taxy_x, taxy_y;
int map[30][30];
int move_map[30][30];

int dx[4] = {-1,0,1,0};//left,up,right, down
int dy[4] = {0,-1,0,1};



class people {
public:
	int start_x, start_y, end_x, end_y;
	int d;
	bool done;
	people();
};

people::people() {
	start_x = 0;
	start_y = 0;
	end_x = 0;
	end_y = 0;
	d = MAX;
	done = false;
}



vector<people> M(MAX);

void input() {
	cin >> n >> m >> fuel;
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= n; j++) {
			int key;
			cin >> key;
			if (key == 1) key = WALL;
			map[i][j]=key;
		}
	cin >> taxy_x >> taxy_y;

	for (int i = 0; i < m; i++) {
		cin >> M[i].start_x >> M[i].start_y >> M[i].end_x >> M[i].end_y;
		
	}
}


void bfs(int t_x, int t_y) {

	for(int i=1;i<=n;i++)
		for (int j = 1; j <= n; j++) {
			move_map[i][j] = map[i][j];
		}
	queue < pair<int, int>>q;
	q.push({ t_x,t_y });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || ny <= 0 || nx > n || ny > n)continue;
			if (move_map[nx][ny] == WALL)continue;
			if (nx == t_x && ny == t_y)continue;
			if (move_map[nx][ny] == 0) {
				move_map[nx][ny] = move_map[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
}



int solve() {
	while (true) {
		bfs(taxy_x, taxy_y);

		/*for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << move_map[i][j] << " ";
			}
			cout << endl;
		}*/

		people N;	//°¡±î¿î ½Â°´

		N.start_x = MAX;
		N.start_y = MAX;
		N.end_x = 0;
		N.end_y = 0;
		N.d = MAX;
		int ack = 0;

		for (int i = 0; i < m; i++) {
			M[i].d = move_map[M[i].start_x][M[i].start_y];
			if (M[i].start_x!=taxy_x&&M[i].start_y!=taxy_y&&M[i].d == 0)return -1;
		}

		for (int i = 0; i < m; i++) {
			if (M[i].done) {
				ack++;
				continue;
				
			}
			if (M[i].d < N.d) {
				N.start_x = M[i].start_x;
				N.start_y = M[i].start_y;
				N.end_x = M[i].end_x;
				N.end_y = M[i].end_y;
				N.d = M[i].d;
			}
			else if (M[i].d == N.d) {
				if (M[i].start_x < N.start_x) {
					N.start_x = M[i].start_x;
					N.start_y = M[i].start_y;
					N.end_x = M[i].end_x;
					N.end_y = M[i].end_y;
					N.d = M[i].d;
				}
				else if (M[i].start_x == N.start_x) {
					if (M[i].start_y < N.start_y) {
						N.start_x = M[i].start_x;
						N.start_y = M[i].start_y;
						N.end_x = M[i].end_x;
						N.end_y = M[i].end_y;
						N.d = M[i].d;
					}
				}
			}

		}

		for (int i = 0; i < m; i++) {
			if (M[i].start_x == N.start_x && M[i].start_y == N.start_y) {
				M[i].done = true;
			}
		}

		int startx = N.start_x;
		int starty = N.start_y;
		int endx = N.end_x;
		int endy = N.end_y;
		int dis = N.d;

		if (fuel < dis)return -1;

		//½Â°´ÇÑÅ× ÀÌµ¿
		taxy_x = startx;
		taxy_y = starty;
		fuel -= dis;
		bfs(taxy_x, taxy_y);

		int des = move_map[endx][endy];

		if (fuel < des)return -1;

		//ÀÌµ¿
		taxy_x = endx;
		taxy_y = endy;
		fuel -= des;
		ack++;
		fuel += des * 2;
		
		if (ack == m) return fuel;
	}
}

int main() {
	input();
	cout <<solve() << endl;
}
