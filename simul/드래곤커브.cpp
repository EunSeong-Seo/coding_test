#include <iostream>
#include <vector>

using namespace std;

int n, x, y, d, g;
int end_x, end_y;
bool map[120][120];
int result;

int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };

vector <int>dirs;

void make_dragon() {
	int size = dirs.size();

	for (int i = size - 1; i >= 0; i--) {
		int dir = (dirs[i] + 1) % 4;

		end_x = end_x + dx[dir];
		end_y = end_y + dy[dir];

		map[end_x][end_y] = true;

		dirs.push_back(dir);

	}



}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> y>> x >> d >> g;

		dirs.clear();

		map[x][y] = true;

		end_x = x + dx[d];
		end_y = y + dy[d];

		map[end_x][end_y] = true;

		dirs.push_back(d);

		for (int i = 0; i < g; i++) {
			make_dragon();
		}


	}
	for (int i = 0; i <= 120 - 2; i++) {
		for (int j = 0; j <= 120 - 2; j++) {
			if (map[i][j] == true && map[i][j + 1] == true && map[i + 1][j] == true && map[i + 1][j + 1] == true) {
				result++;
			}
		}
	}
	cout << result << endl;
}

