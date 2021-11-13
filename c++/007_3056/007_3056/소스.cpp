#include<bits/stdc++.h>
#define inf 987654321
using namespace std;

int n;
int arr[20][20];
double dp[1 << 21];

double f(int mi, int idx) {
	if (idx == (1 << n) - 1)return 1;
	double ret = 0;
	for (int i = 0, j = 1; i < n; i++, j <<= 1) {
		if (idx & j)continue;//이미 한거야
		double tmp = (double) arr[i][mi] / 100;
		if (dp[idx + j] == -1)dp[idx + j] = f(mi + 1, idx + j);
		tmp *= dp[idx + j];
		ret = max(ret, tmp);
	}
	dp[idx] = ret;
	return ret;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < (1 << n); i++)dp[i] = -1;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];

	printf("%.8f", f(0, 0) * 100);
}