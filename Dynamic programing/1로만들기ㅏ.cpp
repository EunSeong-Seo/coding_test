#include <bits/stdc++.h>

using namespace std;

// �ռ� ���� ����� �����ϱ� ���� DP ���̺� �ʱ�ȭ
int d[100];
int n;
vector<int> arr;

int main(void) {
    // ���� N�� �Է¹ޱ�
    cin >> n;
    // ��� �ķ� ���� �Է¹ޱ�
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);A
    }

    // ���̳��� ���α׷���(Dynamic Programming) ����(���Ҿ�)
    d[0] = arr[0];
    d[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++) {
        d[i] = max(d[i - 1], d[i - 2] + arr[i]);
    }

    // ���� ��� ���
    cout << d[n - 1] << '\n';
}
