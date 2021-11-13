#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int n;
int arr[400];
int dp[400][400];// 시작~끝 일 때 최대 수 

void init() {
	for (int i = 0; i < 400; i++)for (int j = i; j < 400; j++)dp[i][j] = 0;
}

void f(int s, int e) {
	int M = 0;
	if (s >= e) {
		dp[s][e] = 0;
		return;
	}
	if (s + 1 == e) {
		if (abs(arr[s] - arr[e]) < 2)dp[s][e] = 2;
		return;
	}

	if (dp[s + 1][e - 1] == -1)f(s + 1, e - 1);

	if (abs(arr[s] - arr[e]) < 2 && dp[s + 1][e - 1] == e - s - 1) {
		dp[s][e] = dp[s + 1][e - 1] + 2;
		return;
	}
	//else M = max(M, dp[s + 1][e - 1]);

	for (int i = s; i < e; i++) {
		if (dp[s][i] == -1)f(s, i);
		if (dp[i][e] == -1)f(i + 1, e);
		M = max(M, dp[s][i] + dp[i + 1][e]);
	}

	dp[s][e] = M;
}

int main() {
	cin >> n;
	while (n){
		init();

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		
		//f(0, n - 1);// [s, e]
		
		for (int j = 1; j <= n; j++) {//시작
			for (int i = 0; i + j <= n; i++) {//길이
				int s = i;
				int e = i + j;
				
				int M = 0;
				if (s >= e) {
					dp[s][e] = 0;
					continue;
				}
				if (j == 1) {
					if (abs(arr[s] - arr[e]) < 2)dp[s][e] = 2;
					continue;
				}

				if (abs(arr[s] - arr[e]) < 2 && dp[s + 1][e - 1] == j - 1) {
					dp[s][e] = dp[s + 1][e - 1] + 2;
					continue;
				}

				for (int k = s; k < e; k++) {
					M = max(M, dp[s][k] + dp[k + 1][e]);
				}

				dp[s][e] = M;

			}
		}

		cout << dp[0][n - 1] << endl;

		cin >> n;
	}

}