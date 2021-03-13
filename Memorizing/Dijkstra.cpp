#include <bits/stdc++.h>
#define INF 1e9 // ������ �ǹ��ϴ� ������ 10���� ����

using namespace std;

// ����� ����(N), ������ ����(M), ���� ��� ��ȣ(Start)
// ����� ������ �ִ� 100,000����� ����
int n, m, start;
// �� ��忡 ����Ǿ� �ִ� ��忡 ���� ������ ��� �迭
vector<pair<int, int> > graph[100001];
// �湮�� ���� �ִ��� üũ�ϴ� ������ �迭 �����
bool visited[100001];
// �ִ� �Ÿ� ���̺� �����
int d[100001];

// �湮���� ���� ��� �߿���, ���� �ִ� �Ÿ��� ª�� ����� ��ȣ�� ��ȯ
int getSmallestNode() {
    int min_value = INF;
    int index = 0; // ���� �ִ� �Ÿ��� ª�� ���(�ε���)
    for (int i = 1; i <= n; i++) {
        if (d[i] < min_value && !visited[i]) {
            min_value = d[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int start) {
    // ���� ��忡 ���ؼ� �ʱ�ȭ
    d[start] = 0;
    visited[start] = true;
    for (int j = 0; j < graph[start].size(); j++) {
        d[graph[start][j].first] = graph[start][j].second;
    }
    // ���� ��带 ������ ��ü n - 1���� ��忡 ���� �ݺ�
    for (int i = 0; i < n - 1; i++) {
        // ���� �ִ� �Ÿ��� ���� ª�� ��带 ������, �湮 ó��
        int now = getSmallestNode();
        visited[now] = true;
        // ���� ���� ����� �ٸ� ��带 Ȯ��
        for (int j = 0; j < graph[now].size(); j++) {
            int cost = d[now] + graph[now][j].second;
            // ���� ��带 ���ļ� �ٸ� ���� �̵��ϴ� �Ÿ��� �� ª�� ���
            if (cost < d[graph[now][j].first]) {
                d[graph[now][j].first] = cost;
            }
        }
    }
}

int main(void) {
    cin >> n >> m >> start;

    // ��� ���� ������ �Է¹ޱ�
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // a�� ��忡�� b�� ���� ���� ����� c��� �ǹ�
        graph[a].push_back({b, c});
    }

    // �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
    fill_n(d, 100001, INF);
    
    // ���ͽ�Ʈ�� �˰����� ����
    dijkstra(start);

    // ��� ���� ���� ���� �ִ� �Ÿ��� ���
    for (int i = 1; i <= n; i++) {
        // ������ �� ���� ���, ����(INFINITY)�̶�� ���
        if (d[i] == INF) {
            cout << "INFINITY" << '\n';
        }
        // ������ �� �ִ� ��� �Ÿ��� ���
        else {
            cout << d[i] << '\n';
        }
    }
}
