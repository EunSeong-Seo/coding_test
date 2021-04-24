/*
4X4의 공간
각칸은 X Y

한칸에는 물고기한마리
물고기는 번호와, 방향  , 
	번호 같은경우 x
	방향 8가지 
	한칸만 이동가능

상어
	방향 
	여러개칸 이동가능

청소년 상어 시작
	0,0 물고기 먹고 
	상어의 방향 0,0 물고기방향


물고기 이동
	#무조건 한번은 이동해야함 
	#번호가 작은 물고기부터 순서대로 
	for 1 16
	if 먹혔음 = continue
	while
	이동가능(물고기가 있거나 빈칸)
		이동
		만약 물고기있음
			서로 위치 교환
			끝 break
	이동불가능 (상어가 있거나 공간의경계)
		만약 상어 & 벽이라면 
			45도 반시계 회전 

상어이동
	#여러개 칸 이동가능
	#빈칸은 갈수 없음
	#이동중에는 먹지않음
	방향에 물고기 있으면 이동
	방향에 물고기 없으면 종료
		먹은 물고기양 >max max = 물고기양 
	

범위
번호 1보다크거나 같고 16보다 작음

변수
fishes 배열 
max_eat
map 
copy map 
cppy fish


*/

#include <iostream>
#include<algorithm>

using namespace std;

class Fish {
public:
	int x;
	int y;
	int d;
	int dead;
};


int dx[9] ={0,-1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {0, 0,-1,-1,-1,0,1,1,1 };

int map[4][4];
int ans=0;
Fish fishes[20];

void input() {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			map[i][j] = a;
			fishes[a] = { i,j,b,false };
		}
	}

}


void swap_fish( int idx1 , int idx2 ) {

	Fish temp = fishes[idx1];
	fishes[idx1].x = fishes[idx2].x;
	fishes[idx1].y = fishes[idx2].y;
	fishes[idx2].x = temp.x;
	fishes[idx2].y = temp.y;
}

void copy_state(int A[][4], int B[][4],Fish C[],Fish D[]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			A[i][j] = B[i][j];
		}
	}
	for (int i = 0; i < 16; i++) {
		C[i] = D[i];
	}
}

void move_fish() {
	for (int i = 1; i <= 16; i++) {
		if (fishes[i].dead) continue;

		int x = fishes[i].x;
		int y = fishes[i].y;
		int d = fishes[i].d;

		while (true) {
			
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {
				if (map[nx][ny] == 0) {
					map[nx][ny] = i;
					map[x][y] = 0;
					fishes[i].x = nx;
					fishes[i].y = ny;
					fishes[i].d = d;
					break;
				}
				else if (map[nx][ny] != -1) {
					fishes[i].d = d;
					swap_fish(i, map[nx][ny]);
					swap(map[nx][ny], map[x][y]);
					break;
				}
			}

			else {
				int nd = d + 1;
				if (nd == 9) nd = 1;
				d = nd;
			}
		}
	}
}

void make_state(int x, int y, int nx, int ny, int fish_num, bool T) {

	if (T == true) {
		map[x][y] = 0;
		map[nx][ny] = -1;
		fishes[map[nx][ny]].dead = true;
	}
	else if (T==false){
		
		map[x][y] = -1;
		map[nx][ny] = fish_num;
		fishes[fish_num].dead = false;

	}
}

void DFS(int x, int y, int dir, int eat) {
	int ans = max(ans, eat);

	int c_map[4][4];
	Fish c_fishes[16];
	copy_state(c_map, map, c_fishes, fishes);

	move_fish();

	for (int i = 1; i <= 3; i++) {
		int nx = x + dx[dir] * i;
		int ny = y + dy[dir] * i;

		if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {
			if (map[nx][ny] == 0)continue;

			int fishn = map[nx][ny];
			int dn = fishes[map[nx][ny]].d;

			make_state(x, y, nx, ny, fishn, true);
			DFS(nx, ny, dn, eat + fishn);
			make_state(x, y, nx, ny, fishn, false);
		}
		else break;
	}
	copy_state(map, c_map, fishes, c_fishes);
}


void solution() {
	int fnum = map[0][0];
	int dir = fishes[map[0][0]].d;
	fishes[fnum].dead = true;
	map[0][0] = -1;
	DFS(0, 0, dir, fnum);
	cout << ans << endl;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();

	return 0;


}
