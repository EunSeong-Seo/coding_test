/*
���� NN

�ִ��� �� ����

���ڴ� ������ ����

���θ� ����� ��Ģ
1. ���δ� ���� ���� ���츮 ����
2, ������ ���̰� ������ ���ƾ��Ѵ� (���Ƶ� x ���Ƶ� x)
	���� �Ǵ� ���θ� (�밢�� X)
3, �� ���θ� ���� �� �Ѱ��� �ִ� K ���� ��ŭ ������ ��� ���� ����

����
N�� 3 �̻� 8����
K�� 1�̻� 20����
�������� ���� ���� ���츮�� �ִ� 5��
���̸� 1���� �۰Ե� ���� 


����
map[19][19];
copy map�� �־���ҵ� 
���� ���� ������ ��ġ���� �Ұ� vector


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
int path = 1;	//�ڱ� �ڽŵ� ���� 
vector <pair<int, int>>v;	//���� ������ 
int high = 0;

int dx[4] = {-1,0,1,0}; //�� �� �� ��
int dy[4] = {0,1,0,-1};

void init() {
	int path = 1;	//�ڱ� �ڽŵ� ���� 
	vector <pair<int, int>>v;	//���� ������ 
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


