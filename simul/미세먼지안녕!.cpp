#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int R, C;
int map[60][60];
int mapr[60][60];
int T;

int dy[4] = {1,0,-1,0};//오 위 왼 아
int dx[4] = {0,-1,0,1};

int dyy[4] = {1,0,-1,0}; //오 아 왼위
int dxx[4] = {0,1,0,-1};

int g1_x = 0;
int g1_y = 0;
int g2_x = 0;
int g2_y = 0;
bool g1 = false;

int result = 0;

void input() {
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			int x;
			cin >> x;
			if (x == -1 && !g1) {
				g1_x = i;
				g1_y = j;
				g1 = true;
			}
			else if (x == -1 && g1) {
				g2_x = i;
				g2_y= j;
			}
			map[i][j] = x;
		}
}

void mise_move() {	
	while (T) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] == -1)continue;
				int x = i;
				int y = j;
				int dc = 0;
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx < 0 || ny < 0 || nx >= R || ny >= C)continue;
					if (nx == g1_x && ny == g1_y)continue;
					if (nx == g2_x && ny == g2_y)continue;

					map[nx][ny] += map[x][y] / 5;
					dc++;
				}

				map[x][y] = map[x][y] - map[x][y] * dc / 5;
			}
		}
		T--;
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}


void airClean() {		//잘작동하는데 이거를 함수로 적어서 똑같이 코드를 안적게 했더라면 더 좋았을거 같다 

	int up_d= 0;
	int up_x=g1_x, up_y=g1_y+1;
	queue<int>uq;
	uq.push(0);

	int do_d=0;
	int do_x=g2_x, do_y=g2_y+1;
	queue<int>dq;
	dq.push(0);

	while (1) {
		if (up_x == g1_x && up_y == g1_y) break;
		uq.push(map[up_x][up_y]);
		int key = uq.front();
		uq.pop();
		map[up_x][up_y] = key;

		while (1) {
			int nx = up_x + dx[up_d];
			int ny = up_y + dy[up_d];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
				up_d++;
			}
			else {
				up_x = nx;
				up_y = ny;
				break;
			}
		}

	}
	while (1) {
		if (do_x == g2_x && do_y == g2_y) break;
		dq.push(map[do_x][do_y]);
		int key = dq.front();
		dq.pop();
		map[do_x][do_y] = key;

		while (1) {
			int nx = do_x + dxx[do_d];
			int ny = do_y + dyy[do_d];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
				do_d++;
			}
			else {
				do_x = nx;
				do_y = ny;
				break;
			}
		}

	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void count_mise() {
	for(int i=0;i<R;i++)
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 0 || map[i][j] == -1)continue;
			result += map[i][j];
		}

}

int main() {
	input();
	cout << endl;

	mise_move();
	cout << endl;

	airClean();
	count_mise();
	cout << result << endl;
}
