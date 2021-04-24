/*
4X4�� ����
��ĭ�� X Y

��ĭ���� ������Ѹ���
������ ��ȣ��, ����  , 
	��ȣ ������� x
	���� 8���� 
	��ĭ�� �̵�����

���
	���� 
	������ĭ �̵�����

û�ҳ� ��� ����
	0,0 ����� �԰� 
	����� ���� 0,0 ��������


����� �̵�
	#������ �ѹ��� �̵��ؾ��� 
	#��ȣ�� ���� �������� ������� 
	for 1 16
	if ������ = continue
	while
	�̵�����(����Ⱑ �ְų� ��ĭ)
		�̵�
		���� ���������
			���� ��ġ ��ȯ
			�� break
	�̵��Ұ��� (�� �ְų� �����ǰ��)
		���� ��� & ���̶�� 
			45�� �ݽð� ȸ�� 

����̵�
	#������ ĭ �̵�����
	#��ĭ�� ���� ����
	#�̵��߿��� ��������
	���⿡ ����� ������ �̵�
	���⿡ ����� ������ ����
		���� ������ >max max = ������ 
	

����
��ȣ 1����ũ�ų� ���� 16���� ����

����
fishes �迭 
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
