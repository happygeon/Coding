#include<bits/stdc++.h>
#define inf 2147483647
using namespace std;

int n;
pair<int, int> arr[1000];
int dp[1000][1000];

void f(int s, int e) {
	if (dp[s][e] != 0)return;
	if (s + 1 == e)return;
	if (s + 2 == e) {
		dp[s][e] = arr[s].first * arr[s].second * arr[s + 1].second;
		return;
	}

	int m = inf;
	int x = arr[s].first;
	int z = arr[e - 1].second;
	for (int i = s + 1; i < e; i++) {
		int tmp = 0;
 		if (dp[s][i] == 0)f(s, i);
		if (dp[i][e] == 0)f(i, e);
		tmp += dp[s][i];
		tmp += dp[i][e];

		int y = arr[i].first;
		tmp += x * y * z;

		m = min(m, tmp);
	}
	dp[s][e] = m;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	f(0, n);

	cout << dp[0][n];
}