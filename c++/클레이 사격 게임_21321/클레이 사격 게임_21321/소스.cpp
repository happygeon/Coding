#include<bits/stdc++.h>
#define inf 987654321
using namespace std;

int n;
int a[20];
int b[20];
int v[20];
int dp[20][70000];

int f(int rou, int idx) {
	if (idx == (1 << n) - 1) {// �� ��
		return 0;
	}
	int ret = -1;
	for (int i = 0, j = 1; i < n; i++, j <<= 1) {
		if (idx & j)continue; // �̹� ��ž�
		if ((idx & v[i]) != v[i])continue;// ������ �ȵȰ�

		int tmp = 0;
		if (dp[rou + 1][idx + j] == 0)dp[rou + 1][idx + j] = f(rou + 1, idx + j);
		ret = max(ret, dp[rou + 1][idx + j] + rou * b[i]);
	}
	return ret;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		for (int j = 0; j < i; j++)if (a[i] % a[j] == 0) v[i] += (1 << j);
	}
	cout << f(1, 0);
}