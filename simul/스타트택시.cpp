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

bool cmp(people A, people B) {
	if (A.done == true)return A.d > B.d;
	return A.d > B.d;
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
			if (move_map[nx][ny] == 0) {
				move_map[nx][ny] = move_map[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	cout << "bfs" << endl;
	cout << fuel << endl;
}

int solve() {
	bfs(taxy_x, taxy_y);
	
	vector <people> N;
	int ack = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << move_map[i][j]<<" ";
		}
		cout << endl;
	}


	for (int i = 0; i < m; i++) {
		if (M[i].done) {
			continue;
			ack++;
		}
		M[i].d = move_map[M[i].start_x][M[i].start_y];
	}


	sort(M.begin(), M.end(), cmp);
	
	int startx = M[m - 1].start_x;
	int starty = M[m - 1].start_y;
	int endx = M[m - 1].end_x;
	int endy = M[M.size() - 1].end_y;
	int dis = M[M.size() - 1].d;
	
	if (fuel < dis)return -1;


	//이동
	taxy_x = startx;
	taxy_y = starty;
	fuel -= dis;
	bfs(taxy_x, taxy_y);
	
	int des = move_map[endx][endy];

	if (fuel < des)return -1;
	
	//이동
	taxy_x = startx;
	taxy_y = starty;
	fuel -= des;
	M[M.size()-1].done = true;
	ack++;

	if (ack == m) return fuel;
	else {
		fuel += des * 2;
	}

}

int main() {
	input();
	cout << "solve : "<<solve() << endl;


}
