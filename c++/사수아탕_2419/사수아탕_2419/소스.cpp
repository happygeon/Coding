#include<bits/stdc++.h>
#define inf 2147483647
typedef long long int ll;
using namespace std;

ll n, m, x;
ll arr[400];
ll dp[400][400][2];

ll f(ll s, ll e, bool left, ll k) { // 사라지는 사탕을 계산. 사라지는계 최소min이 되어야 함.
	if (k == 0)return dp[s][e][left] = 0; // 먹을 상자가 0개이면
	if (e < s)return inf; // 불가능한 경우
	if (dp[s][e][left] != -1)return dp[s][e][left]; // 이미 구한거라면

	ll ret = inf;
	if (left) {
		if (e < n) { // 오른쪽으로 갈 수 있으면 비교
			if (dp[s][e + 1][0] == -1)f(s, e + 1, 0, k - 1);
			ret = min(ret, dp[s][e + 1][0] + k * (arr[e + 1] - arr[s]));// 오른쪽에ㅓ 왼쪽으로 이동
		}
		if (s > 0) {// 왼쪽으로 갈 수 있으면
			if (dp[s - 1][e][1] == -1)f(s - 1, e, 1, k - 1);
			ret = min(ret, dp[s - 1][e][1] + k * (arr[s] - arr[s - 1]));// 왼쪽에서 한칸 더 왼쪽으로 이동
		}
	}
	else {
		if (e < n) { // 오른쪽으로 갈 수 있으면 비교
			if (dp[s][e + 1][0] == -1)f(s, e + 1, 0, k - 1);
			ret = min(ret, dp[s][e + 1][0] + k * (arr[e + 1] - arr[e]));// 오른쪽에ㅓ 왼쪽으로 이동
		}
		if (s > 0) {// 왼쪽으로 갈 수 있으면
			if (dp[s - 1][e][1] == -1)f(s - 1, e, 1, k - 1);
			ret = min(ret, dp[s - 1][e][1] + k * (arr[e] - arr[s - 1]));// 왼쪽에서 한칸 더 왼쪽으로 이동
		}
	}

	dp[s][e][left] = ret;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (ll i = 1; i <= n; i++) cin >> arr[i];

	// 정렬. arr[1]부터, arr[0]은 0
	sort(arr, arr + n + 1);

	// 0으로 이동
	ll idx = lower_bound(arr, arr + n, 0) - arr;
	ll ans = 0;
	for (ll k = 0; k <= n; k++) {
		memset(dp, -1, sizeof dp);
		//cout << k * m - f(idx, idx, 0, k) << endl;
		ans = max(ans, k * m - f(idx, idx, 0, k));
	}

	cout << ans;
}