#include<bits/stdc++.h>
#define inf 987654321
using namespace std;

int n;
int arr[20][20];
int dp[20][70000];

int f(int now, int idx) {
	if (idx == (1 << n) - 1) {// 전부 방문 했을 떄
		return arr[now][0];
	}

	int ret = inf;
	for (int i = 0, j = 1; i < n; i++, j <<= 1) {
		if (idx & j)continue; // 방문 한거
		if (arr[now][i] == 0)continue; // 길이 없는거
		int tmp = arr[now][i];
		if (dp[i][idx + j] == 0)dp[i][idx + j] = f(i, idx + j);
		if (dp[i][idx + j] == 0)continue;
		ret = min(ret, dp[i][idx + j] + tmp);
	}

	dp[now][idx] = ret;
	return ret;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];

	cout << f(0, 1);

}