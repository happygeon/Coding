#include<bits/stdc++.h>
#define inf 2147483647
using namespace std;

int q;
int n;
int arr[110];
int dp[110][110][2]; // 이길 수 있으면 1
int x;

void f(int s, int e, int remain) {
	bool canwin = false;
	//제거 할 숫자 선택
	for (int i = s; i <= e; i++) {
		if (arr[i - 1] > arr[i] && i > s)continue;
		if (arr[i + 1] > arr[i] && i < e)continue; // 제거불가

		if (x == i) {//1을 제거할 수 있다면
			dp[s][e][remain] = 1;
			return;
		}
		if (x > i) {//1이 제거하는것 보다 오른쪽에
			int tmp = (remain + i - s) % 2; // i를 제거할 경우의 잉여를 갱신
			if (dp[i + 1][e][tmp] == -1)f(i + 1, e, tmp); // 남은 구간에서 상대가 이길 수 있는지 계산
			if (dp[i + 1][e][tmp])continue;
			canwin = true;
		}
		else {
			int tmp = (remain + e - i) % 2;
			if (dp[s][i - 1][tmp] == -1)f(s, i - 1, tmp); // 남은 구간에서 상대가 이길 수 있는지
			if (dp[s][i - 1][tmp])continue;
			canwin = true;
		}
	}

	if (remain) {//잉여가 있다면
		if (dp[s][e][0] == -1)f(s, e, 0); // 잉여가 없을 때 계산
		if (dp[s][e][0] == 0)canwin = true; // 잉여가 없을 때 진다면 있으면 이긴다는 뜻
	}

	if (canwin)dp[s][e][remain] = 1; // 이김
	else dp[s][e][remain] = 0; // 짐
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