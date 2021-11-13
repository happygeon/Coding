#include<bits/stdc++.h>
#define inf 2147483647
using namespace std;

int q;
int n;
int arr[110];
int dp[110][110][2]; // �̱� �� ������ 1
int x;

void f(int s, int e, int remain) {
	bool canwin = false;
	//���� �� ���� ����
	for (int i = s; i <= e; i++) {
		if (arr[i - 1] > arr[i] && i > s)continue;
		if (arr[i + 1] > arr[i] && i < e)continue; // ���źҰ�

		if (x == i) {//1�� ������ �� �ִٸ�
			dp[s][e][remain] = 1;
			return;
		}
		if (x > i) {//1�� �����ϴ°� ���� �����ʿ�
			int tmp = (remain + i - s) % 2; // i�� ������ ����� �׿��� ����
			if (dp[i + 1][e][tmp] == -1)f(i + 1, e, tmp); // ���� �������� ��밡 �̱� �� �ִ��� ���
			if (dp[i + 1][e][tmp])continue;
			canwin = true;
		}
		else {
			int tmp = (remain + e - i) % 2;
			if (dp[s][i - 1][tmp] == -1)f(s, i - 1, tmp); // ���� �������� ��밡 �̱� �� �ִ���
			if (dp[s][i - 1][tmp])continue;
			canwin = true;
		}
	}

	if (remain) {//�׿��� �ִٸ�
		if (dp[s][e][0] == -1)f(s, e, 0); // �׿��� ���� �� ���
		if (dp[s][e][0] == 0)canwin = true; // �׿��� ���� �� ���ٸ� ������ �̱�ٴ� ��
	}

	if (canwin)dp[s][e][remain] = 1; // �̱�
	else dp[s][e][remain] = 0; // ��
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> q;
	while (q){
		q--;
		
		cin >> n;
		for (int i = 0; i <= n; i++)for (int j = 0; j <= n; j++)dp[i][j][0] = dp[i][j][1] =  -1;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			if (arr[i] == 1)x = i;
		}
		f(1, n, 0);
		cout << (dp[1][n][0] ? "Alice" : "Bob") << endl;
		

	}
}