/*
등산로 NN

최대한 긴 등산로

숫자는 지형의 높이

등산로를 만드는 규칙
1. 등산로는 가장 높은 봉우리 시작
2, 등산로의 높이가 무조건 낮아야한다 (같아도 x 높아도 x)
	가로 또는 세로만 (대각선 X)
3, 긴 등산로를 위해 딱 한곳만 최대 K 깊이 만큼 지형을 깍는 공사 가능

범위
N은 3 이상 8이하
K는 1이상 20이하
지도에서 가장 높은 봉우리는 최대 5개
높이를 1보다 작게도 가능 


변수
map[19][19];
copy map도 있어야할듯 
제일 높은 봉오리 위치저장 할곳 vector


*/


#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include<stack>

using namespace std;

int T;
int n, k;
int map[19][19];
int path = 1;	//자기 자신도 센다 
vector <pair<int, int>>v;	//높은 봉오리 
int high = 0;

int dx[4] = {-1,0,1,0}; //위 오 아 왼
int dy[4] = {0,1,0,-1};

void init() {
	int path = 1;	//자기 자신도 센다 
	vector <pair<int, int>>v;	//높은 봉오리 
	int high = 0;
	v.clear();
}


void input() {
	int high = 0;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			if (x > high) x = high;
			map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == high) {
				v.push_back({ i,j });
			}
		}
	}

}

int DFS(int x, int y, bool usek, int a[],int path) {
	int max_path = 1;


	stack < pair<int, int>> st;
	st.push({ x,y });

	while (!st.empty()) {
		int x = st.top().first;
		int y = st.top().second;
		st.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny<0 || nx >= n || ny>n) continue;

			if (a[nx][ny] < a[x][y]) {
				int npath = path + 1;
				if (npath > max_path) max_path = npath;

				if(usek ==true) st.push(nx, ny, true,a,npath);
				else if(usek ==false ) st.push(nx, ny, false,a,npath);
			}
			else {
				if (usek == false) {
					if (a[nx][ny] - k < a[x][y]) {
						int npath = path + 1;
						if (npath > max_path) max_path = npath;
						a[nx][ny] -= k;
						st.push(nx, ny, true, a, npath);
					}
				}
				else if (use == true) continue;

			}

		}
	}

	return max_path;

}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		init();
		input();

		for (int j = 0; j < v.size(); j++) {
			int r = v[i].first;
			int c = v[i].second;
			int temp = DFS(r, c,false,map,1);

			if (temp > high) temp = high;

		}
		cout << "#" << i + 1 << " " << high << endl;

		}
	
}


